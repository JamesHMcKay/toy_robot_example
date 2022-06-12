#include <fstream>
#include <string>
#include <functional>

#include "table.hpp"
#include "robot.hpp"
#include "user_input.hpp"

typedef std::basic_istream<char> cmd_stream;

void run(cmd_stream& commands, const std::function <bool(cmd_stream&, std::string)>& exit_program) {
    int table_size = 5;
    Table table(table_size, table_size);
    Robot robot(&table);

    std::string input;

    while (std::getline(commands, input) && !exit_program(commands, input)) {
        UserInput user_input(input);
        if (user_input.validate()) {
            user_input.execute(robot);
        }
    }
}

int main(int argc, char* argv[]) {
    utils::ProgramMode program = utils::parse_args(argc, argv);

    if (program == utils::ProgramMode::FROM_FILE) {
        std::ifstream ifs(argv[2]);
        run(ifs, [](cmd_stream& ifs, std::string s) { return ifs.eof(); });
    }

    if (program == utils::ProgramMode::INTERACTIVE) {
        run(std::cin, [](cmd_stream& ifs, std::string s) { return s == "exit"; });
    }

    return 0;
}
