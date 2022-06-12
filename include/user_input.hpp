
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

    const std::string action_delimiter = " ";

    const std::string parameter_delimiter = ",";

    UserInput(std::string input);

    int validate();

    void execute(Robot& robot);
};

#endif // __USER_INPUT_H__
