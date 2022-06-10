#include "utils.hpp"
#include "actions.hpp"

namespace utils {
    int string_similarity(std::string s1, std::string s2) {
        int matching_characters = 0;

        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                if (tolower(s1[i]) == tolower(s2[j])) {
                    matching_characters++;
                }
            }
        }
        return matching_characters;
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
        if (action_map.find(input.action) == action_map.end()) {
            std::cout << "Invalid action: " << input.action << std::endl;

            std::string closest_string;
            int best_match = 0;
            for (auto& action : action_map) {
                int distance = string_similarity(input.action, action.first);
                if (distance > best_match) {
                    best_match = distance;
                    closest_string = action.first;
                }
            }
            if (best_match > 2) {
                std::cout << "Did you mean " << closest_string << "?" << std::endl;
            }

            return -1;
        }

        ActionDefinition action_definition = action_map.at(input.action);

        if (input.parameters.size() != action_definition.number_of_parameters) {
            std::cout << "Invalid number of parameters for action: " << input.action << std::endl;
            std::cout << "Expected " << action_definition.number_of_parameters << " parameters" << std::endl;
            std::cout << "Got " << input.parameters.size() << " parameters" << std::endl;

            return -1;
        }

        return 0;
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