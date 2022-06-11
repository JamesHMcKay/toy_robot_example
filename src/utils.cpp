#include "utils.hpp"

namespace utils {
    int parse_int(std::string input) {
        std::stringstream sstr(input);
        int result;
        bool success = static_cast<bool>(sstr >> result);
        if (success) {
            return result;
        }
        return -1;
    }

    int string_similarity(std::string s1, std::string s2) {
        int n_matching_characters = 0;

        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                if (tolower(s1[i]) == tolower(s2[j])) {
                    n_matching_characters++;
                }
            }
        }
        return n_matching_characters;
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

    void suggest(std::string user_input, std::vector<std::string> options) {
        std::string closest_string;
        int best_match = 0;
        for (auto& option : options) {
            int distance = utils::string_similarity(user_input, option);
            if (distance > best_match) {
                best_match = distance;
                closest_string = option;
            }
        }
        if (best_match > 2) {
            std::cout << "Did you mean " << closest_string << "?" << std::endl;
        }
    }

    int parse_args(int argc, char** argv) {
        if (argc == 3 && strcmp(argv[1], "-f") == 0) {
            return 1;
        }
        else if (argc > 1) {
            std::cout << "Invalid usage" << std::endl;
            std::cout << "Usage for file input        : ./robot -f <input_file>" << std::endl;
            std::cout << "Usage for interactive input : ./robot" << std::endl;
            return 0;
        }
        else {
            return 2;
        }
    }
}
