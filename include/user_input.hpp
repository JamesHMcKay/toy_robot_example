
#ifndef __USER_INPUT_H__
#define __USER_INPUT_H__

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "robot.hpp"
#include "actions.hpp"


struct UserInput {
    std::string action;
    std::vector<std::string> parameters;

    UserInput(std::string input);

    int validate();

    void execute(Robot& robot);
};

#endif // __USER_INPUT_H__