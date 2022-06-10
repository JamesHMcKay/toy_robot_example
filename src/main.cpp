#include <iostream>

#include "utils.hpp"


int main(int argc, char* argv[])
{
    bool is_running = true;

    std::string input;

    while (is_running) {
        std::getline(std::cin, input);

        UserInput user_input = utils::decompose_input(input);
        is_running = strcmp(user_input.action.c_str(), "exit");
        if (!is_running) {
            break;
        }
        utils::validate_user_input(user_input);

    }

    return 0;
}