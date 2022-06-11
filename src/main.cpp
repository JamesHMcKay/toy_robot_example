#include <iostream>
#include<cstring>

#include "table.hpp"
#include "robot.hpp"
#include "input.hpp"


int main(int argc, char* argv[]) {
    Table table(5, 5);

    Robot robot(&table);

    bool is_running = true;
    std::string input;

    while (is_running) {
        std::getline(std::cin, input);

        UserInput user_input = input::decompose_input(input);

        is_running = strcmp(user_input.action.c_str(), "exit");

        if (is_running && input::validate_user_input(user_input)) {
            input::execute_command(user_input, robot);
        }
    }

    return 0;
}