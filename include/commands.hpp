#ifndef __COMMANDS_H__
#define __COMMANDS_H__

namespace commands
{
    void move(Robot& robot, std::vector<std::string>& parameters);

    void turn_left(Robot& robot, std::vector<std::string>& parameters);

    void turn_right(Robot& robot, std::vector<std::string>& parameters);

    void place(Robot& robot, std::vector<std::string>& parameters);

    void report(Robot& robot, std::vector<std::string>& parameters);
}

#endif