#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>


namespace utils {
    int parse_int(std::string s);

    int string_similarity(std::string s1, std::string s2);

    std::vector<std::string> split(std::string input, std::string delimiter);

    void suggest(std::string user_input, std::vector<std::string> options);

    int parse_args(int argc, char** argv);
}

#endif // __UTILS_H__