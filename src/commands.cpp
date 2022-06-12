#include "commands.hpp"

namespace commands {
    void move(Robot& robot, std::vector<std::string>& parameters) {
        robot.move();
    }

    void place(Robot& robot, std::vector<std::string>& parameters) {
        int x = utils::get_positive_int(parameters[0], "X");
        int y = utils::get_positive_int(parameters[1], "Y");

        if (x == -1 || y == -1) {
            return;
        }

        if (DIRECTION_MAP.find(parameters[2]) == DIRECTION_MAP.end()) {
            std::cout << parameters[2] << "' is not a valid direction." << std::endl;
            std::vector<std::string> options;
            for (auto& direction : DIRECTION_MAP) {
                options.push_back(direction.first);
            }

            utils::suggest(parameters[2], options);

            return;
        }

        robot.place(Position(x, y), DIRECTION_MAP.at(parameters[2]));
    }

    void turn_left(Robot& robot, std::vector<std::string>& parameters) {
        Direction direction = robot.get_direction();
        directions::turn_left(direction);
        robot.set_direction(direction);
    }

    void turn_right(Robot& robot, std::vector<std::string>& parameters) {
        Direction direction = robot.get_direction();
        directions::turn_right(direction);
        robot.set_direction(direction);
    }

    void report(Robot& robot, std::vector<std::string>& parameters) {
        std::stringstream ss;

        Direction direction = robot.get_direction();
        Position position = robot.get_position();

        std::string direction_string;
        for (auto value : DIRECTION_MAP) {
            if (value.second == direction) {
                direction_string = value.first;
                break;
            }
        }

        std::cout << "Output: " << position.x << "," << position.y << "," << direction_string << std::endl;
    }
}
