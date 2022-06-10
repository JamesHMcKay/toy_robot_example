#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <iostream>
#include <vector>

struct UserInput {
    std::string action;
    std::vector<std::string> parameters;
};

namespace utils {
    UserInput decompose_input(std::string input);

    int validate_user_input(UserInput input);

    int string_similarity(std::string s1, std::string s2);
}

#endif