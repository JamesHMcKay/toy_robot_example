[![CircleCI](https://circleci.com/gh/JamesHMcKay/toy_robot_example/tree/master.svg?style=svg&circle-token=e4ad079552a25fc339db06156e8ba754c06440d8)](https://circleci.com/gh/JamesHMcKay/toy_robot_example/tree/master)

# Toy Robot Code Challenge

# Design

The program has the following layers:

User interface. This is either a file or console commands. This is all handled in one place.

Robot command input layer. This has input validation and exception handling. It translates commands into robot actions.

Robot class. This contains the state of the report and has the ability to report location. It will also raise errors back to the UI
if a command is not valid.


# Layers of validation

- First layer is the raw user input, turning the string into an action and parameters and checking the number of parameters is correct.

- Second level is managed by the command layer, where the parameters are checked to see if they are valid.

- Final level is in the Robot itself. This is because this level of validation requires knowledge of the state of the robot.


# Extensions

- currently the list of possible actions and the command layers are coupled but defined separately. This is a potential problem for maintainability as any changes must be made in both locations. This could be fixed by defining a macro which allows the action metadata
to be defined along with the command (perhaps as a string above the command function definition), which would then work like a plugin
architecture to register commands in the action list dynamically (well, at compile time).

- different directions
- multiple robots
- make table N dimensional, possible by generalising the position (change from member variables x and y to a vector) and various
other generalisations to the commands to allow multiple inputs and a more general concept of direction.
