#include "utils.hpp"
#include "commands.hpp"

namespace commands
{
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
        int x = std::stoi(parameters[0]);
        int y = std::stoi(parameters[1]);
        int direction = std::stoi(parameters[2]);

        robot.x = x;
        robot.y = y;
        robot.direction = direction;
    }

    void report(Robot& robot, std::vector<std::string>& parameters) {
        std::cout << "X: " << robot.x << " Y: " << robot.y << " Direction: " << robot.direction << std::endl;
    }
}
