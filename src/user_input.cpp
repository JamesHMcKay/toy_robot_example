#include "user_input.hpp"

UserInput::UserInput(std::string input) {
    std::string delimiter = " ";
    action = input.substr(0, input.find(action_delimiter));

    std::string parameters_input = "";

    if (input.find(action_delimiter) != std::string::npos) {
        input.erase(0, input.find(action_delimiter) + action_delimiter.length());
        parameters_input = input;
    }

    parameters = utils::split(parameters_input, parameter_delimiter);
}

void UserInput::execute(Robot& robot) {
    ActionDefinition action_definition = ACTION_MAP.at(action);
    if (robot.is_initialised() || !action_definition.must_be_initialized) {
        action_definition.command(robot, parameters);
    }
    else {
        std::cout << "Robot must be initalised to run this command" << std::endl;
    }
}

int UserInput::validate() {
    if (ACTION_MAP.find(action) == ACTION_MAP.end()) {
        std::vector<std::string> action_keys;
        for (auto& action : ACTION_MAP) {
            action_keys.push_back(action.first);
        }

        std::cout << action << "' is not a valid action." << std::endl;
        utils::suggest(action, action_keys);

        return 0;
    }

    ActionDefinition action_definition = ACTION_MAP.at(action);

    if (parameters.size() != action_definition.number_of_parameters) {
        std::cout << "Invalid number of parameters for action: " << action << std::endl;
        std::cout << "Expected " << action_definition.number_of_parameters << " parameters" << std::endl;
        std::cout << "Got " << parameters.size() << " parameters" << std::endl;

        return 0;
    }

    return 1;
}
