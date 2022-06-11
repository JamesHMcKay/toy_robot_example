#include "input.hpp"

namespace input {
    void execute_command(UserInput input, Robot& robot) {
        ActionDefinition action_definition = ACTION_MAP.at(input.action);
        if (robot.is_initialised() || !action_definition.must_be_initialized) {
            action_definition.command(robot, input.parameters);
        }
        else {
            std::cout << "Robot must be initalised to run this command" << std::endl;
        }
    }

    std::vector<std::string> split(std::string input, std::string delimiter) {
        std::vector<std::string> result;
        size_t pos = 0;
        std::string token;
        while ((pos = input.find(delimiter)) != std::string::npos) {
            token = input.substr(0, pos);
            if (token.length() > 0) {
                result.push_back(token);
            }
            input.erase(0, pos + delimiter.length());
        }
        if (input.length() > 0) {
            result.push_back(input);
        }
        return result;
    }

    int validate_user_input(UserInput input) {
        if (ACTION_MAP.find(input.action) == ACTION_MAP.end()) {
            std::cout << "Invalid action: " << input.action << std::endl;

            std::vector<std::string> action_keys;
            for (auto& action : ACTION_MAP) {
                action_keys.push_back(action.first);
            }

            utils::suggest(input.action, action_keys);

            return 0;
        }

        ActionDefinition action_definition = ACTION_MAP.at(input.action);

        if (input.parameters.size() != action_definition.number_of_parameters) {
            std::cout << "Invalid number of parameters for action: " << input.action << std::endl;
            std::cout << "Expected " << action_definition.number_of_parameters << " parameters" << std::endl;
            std::cout << "Got " << input.parameters.size() << " parameters" << std::endl;

            return 0;
        }

        return 1;
    }

    UserInput decompose_input(std::string input) {
        std::string delimiter = " ";
        std::string action = input.substr(0, input.find(delimiter));

        std::string parameters = "";

        if (input.find(delimiter) != std::string::npos) {
            input.erase(0, input.find(delimiter) + delimiter.length());
            parameters = input;
        }

        std::vector<std::string> parameters_vector = split(parameters, ",");

        return UserInput{
            action,
            parameters_vector
        };
    }
}
