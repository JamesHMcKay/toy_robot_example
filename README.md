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

- different directions
- multiple robots
- make table N dimensional, possible by generalising the position (change from member variables x and y to a vector) and various
other generalisations to the commands to allow multiple inputs and a more general concept of direction.
