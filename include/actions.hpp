#ifndef __ACTIONS_H__
#define __ACTIONS_H__

#include <map>
#include <string>
#include "commands.hpp"

struct ActionDefinition {
    std::string name;
    int number_of_parameters;
    bool must_be_initialized;
    void (*command)(Robot&, std::vector<std::string>&);

    ActionDefinition(
        std::string name,
        int number_of_parameters,
        bool must_be_initialized,
        void (*command)(Robot&, std::vector<std::string>&)
    ) : name(name), number_of_parameters(number_of_parameters), must_be_initialized(must_be_initialized), command(command) {}
};

extern const std::map<std::string, ActionDefinition> ACTION_MAP;

#endif // __ACTIONS_H__
