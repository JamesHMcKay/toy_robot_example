#include "commands.hpp"


namespace commands {
    void move(Robot& robot, std::vector<std::string>& parameters) {
        robot.move();
    }

    void turn_left(Robot& robot, std::vector<std::string>& parameters) {
        robot.turn_left();
    }

    void turn_right(Robot& robot, std::vector<std::string>& parameters) {
        robot.turn_right();
    }

    void place(Robot& robot, std::vector<std::string>& parameters) {
        int x = utils::parse_int(parameters[0]);
        int y = utils::parse_int(parameters[1]);

        if (x == -1) {
            std::cout << "Invalid x coordinate" << std::endl;
            return;
        }
        if (y == -1) {
            std::cout << "Invalid y coordinate" << std::endl;
            return;
        }

        if (DIRECTION_MAP.find(parameters[2]) == DIRECTION_MAP.end()) {
            std::cout << "Invalid direction '" << parameters[2] << "'" << std::endl;
            std::vector<std::string> options;
            for (auto& direction : DIRECTION_MAP) {
                options.push_back(direction.first);
            }

            utils::suggest(parameters[2], options);

            return;
        }

        robot.place(x, y, DIRECTION_MAP.at(parameters[2]));

        std::cout << "PLACE COMMAND EXECUTED" << std::endl;
    }

    void report(Robot& robot, std::vector<std::string>& parameters) {
        std::cout << robot.report() << std::endl;
    }
}
