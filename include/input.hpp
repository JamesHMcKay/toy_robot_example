
#ifndef __INPUT_H__
#define __INPUT_H__

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "robot.hpp"
#include "actions.hpp"


struct UserInput {
    std::string action; // TODO: make this an enum
    std::vector<std::string> parameters;
};

namespace input {
    void execute_command(UserInput input, Robot& robot);

    int validate_user_input(UserInput input);

    UserInput decompose_input(std::string input);
}

#endif // __INPUT_H__