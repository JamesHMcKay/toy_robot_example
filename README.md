[![CircleCI](https://circleci.com/gh/JamesHMcKay/toy_robot_example/tree/master.svg?style=svg&circle-token=e4ad079552a25fc339db06156e8ba754c06440d8)](https://circleci.com/gh/JamesHMcKay/toy_robot_example/tree/master)

# Toy Robot Code Challenge

This is a simple toy robot simulator to demonstrate some C++ code along with some testing.

The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units. There are no
other obstructions on the table surface. The robot is free to roam around the surface of the table, but must be prevented
from falling to destruction. Any movement that would result in the robot falling from the table must be prevented,
however further valid movement commands must still be allowed.

This application has been tested with gcc version 9.4.0 on Ubuntu 20.04.3 LTS (running on Windows 10 build 21H2 using WLS2 kernal 5.10.16) and cmake version 3.16.3.

## Quick start

The provided Docker file will build the application and run all the tests. This can be done with the command
```bash
sudo docker build .
```

To build locally use the following commands

```bash
mkdir build
cd build
cmake ..
make
```

To run the application in an interative shell

```bash
./robot
```
and to exit the interative shell use the command "exit".

To run with a file use:

```bash
./robot -f input.txt
```

Note that the text file must have a new command on each line and must have an empty line at the end (otherwise the last command will be skipped).

## Usage

The following are valid commands to be used in an interactive session or from a text file (seperated by new lines).

PLACE X,Y,F
MOVE
LEFT
RIGHT
REPORT

where X,Y are the coordinates of the robot on the table, in integers, and F is the direction the robot is facing from the set NORTH, SOUTH, EAST, WEST (case sensitive).

The robot must be initialized with a valid PLACE command before any other commands can be used.

If a command is not valid the application may print a message informing the user of the error, and where possible, making a suggestion to fix the input.

The table coordinates are indexed from 0, so for our 5 by 5 unit table the Robot can range from 0,0 to 4,4.

## Testing

All tests can be run from the build directory using the command

```bash
make test
```

There are two layers of testing with this application. Unit tests are provided using the Google Test framework. These can be run from the executable with the command
```bash
./run_tests
```
from within the build directory.

End-to-end tests are provided in an extremely basic form. To avoid setting up a whole testing framework (ideally would use Python to set up some nice feature file based tests to sit around the whole application) I have just used a shell script and some test data. To run these tests use the command:

```bash
./end_to_end_tests.sh <path to project root> <path to robot executable>
```

See the end_to_end_tests.sh script for more details.

All these tests run as part of the Docker build step and any failures will result in the build not succeeding.

# Design

The program is split into layers to handle the user input.

- The main loop feeds the user input to the program. User input can come from either a file stream or an interactive console session.

- The UserInput layer. This layer converts the user input into a standardised format and then validates it against a list of predefined
commands. It checks the command is valid and has the correct number of parameters. In an interative session this layer also provides suggestions.

- This layer contains commands which act on a Robot object. As such the commands are operators, rather than member functions of the robot itself. This decoupling allows us to be flexible with the commands without having to modify the robot itself.

- Robot class. This contains the state of the robot and is deliberality as simple as possible. It is important that the position and direction are private members of this class, as it allows us to maintain control over how these are modified.

## User input

Throughout the code we refer to a line of user input as a *command* which is made up of an *action* and vector of *parameters*. For example:

PLACE 1,2,NORTH

Has an action of `PLACE` and a vector of parameters of `('1','2', 'NORTH')`.

## Levels of validation

This program must be robust to user input. How we do this can become difficult to maintain if not managed well as there are multiple conditions to meet and the order of these conditions is important. The validation works as follows:

- The first layer is the raw user input, when the input string is decomposed into an action and parameter is is checked if the action exists and if the number of parameters is correct. Metadata on the possible commands is used, such as knowing that a MOVE command should not have any parameters. But the actual parameters are not checked at this stage.

- The second level is managed by the command layer. The commands know what kind of inputs they can accept, such as knowing a coordinate must be an integer. Since these conditions are tightly coupled to the business logic of the command itself, it makes sense to have this validation along with the command.

- The final level of validation is in the Robot itself. This requires knowledge of the current state of the robot, such as the position on the table. The command layer can attempt to place the Robot in a new location either through a PLACE or MOVE command, but only the Robot can determine if the new location is valid given its current state.

*There is one exception to this heirarchy and that is the condition on Robot initilisation. Before a valid PLACE command is applied the robot cannot accept any other commands. This condition is handled at the command execution point instead of by the Robot. So Robot state is used at a higher level than Robot object to determine if a command can be applied at all. This is easy enough to do, and simplifies the code. The alternative would be a check on initailisation status prior to every other method in the Robot class resulting in lots of duplicated business logic.*

## Exception handling

There is very little exception handling in this program by design. The only place right now is in the Table class to prevent someone in future attempting to write code which would result in a table with negative dimensions, this is really just to show an example of how to do this (and how it is tested - see the relevant test case). All other "exceptions" are handled in the code rather than using exception handling. Exception handling should only be used for exceptional conditions which are not expected to occur, in most cases we can expect the user to attempt to do something so can handle it (in any of the validation layers listed above).

# Extensions


Part of building good software is thinking about what extensions may be required in the future. This helps us understand what generalisatios would be useful to implement early and where decoupling features now is going to save us time later.

Some considerations that helped me design this application are:

- Multiple robots is one of the most obvious extensions. There may be some requirement to have robots interact, such as blocking positions. The current design could be generalised by adding a parameter to each command to specify which Robot to act on. From there we could also share information about Robot locations through the Table class, and use this to validate new positions (such as through the is_on_table member function).
- Adding more directions such as diagonal directions like NORTH-EAST.
- Making the table N dimensional, this would be possible by modifying the position class and various
other generalisations to the commands to allow multiple inputs and a more general concept of direction.
- Various changes to the input layer. No need to list all the possibilities here, but in general for an application these could include a REST API, a user interface, reading from a database and so on.

Some things that could be improved as well:

- There is no logging framework set up in this application. I haven't done this as it requires a fair bit of work to implement a framework (such as boost logging) and it wasn't a specific requirement. But basically, there would be various places throughout the code where we could create log messages instead of using std out.

- Currently the list of possible actions(ACTION_MAP) and their command functions are tightly coupled. This is a potential problem for maintainability, as changes may need to be made in two places. This could be fixed by defining a macro which allows the action metadata
to be defined along with the command (perhaps as a string above the command function definition), which would then work like a plugin
architecture to register commands in the ACTION_MAP dynamically (well, at compile time). With this set up the ACTION_MAP would not even need to be defined.

- The console UI is not very informative. Would be good to give the user more information such as what commands are possible (and so this dynamically based on the current state of the robot and the available actions) and make it clear how to exit the program.

- The command line arguments handling is extremely basic and not very extensible, it needs to be rewritten in a more general way. First job would be to implement a help command which would print out a list of possible commands and their parameters.