#include <iostream>
#include <fstream>
#include <cstring>
#include <istream>
#include <string>
#include <functional>

#include "table.hpp"
#include "robot.hpp"
#include "input.hpp"

typedef std::basic_istream<char> cmd_stream;


void run(cmd_stream& commands, const std::function <bool(cmd_stream&, std::string s)>& exit_program) {
    int table_size = 5;
    Table table(table_size, table_size);
    Robot robot(&table);

    std::string input;

    while (std::getline(commands, input) && !exit_program(commands, input)) {
        UserInput user_input = input::decompose_input(input);
        if (input::validate_user_input(user_input)) {
            input::execute_command(user_input, robot);
        }
    }
}

int main(int argc, char* argv[]) {
    int program = utils::parse_args(argc, argv);

    if (program == 1) {
        std::ifstream ifs(argv[2]);
        run(ifs, [](cmd_stream& ifs, std::string s) { return ifs.eof(); });
    }

    if (program == 2) {
        run(std::cin, [](cmd_stream& ifs, std::string s) { return s == "exit"; });
    }

    return 0;
}
