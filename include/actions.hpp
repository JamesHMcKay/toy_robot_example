#include <map>
#include <string>
#include "commands.hpp"

struct ActionDefinition {
    std::string name;
    int number_of_parameters;
    void (*command)(Robot&, std::vector<std::string>&);

    ActionDefinition(
        std::string name,
        int number_of_parameters,
        void (*command)(Robot&, std::vector<std::string>&)
    ) : name(name), number_of_parameters(number_of_parameters), command(command) {}
};

const std::map<std::string, ActionDefinition> action_map = {
    {"MOVE", ActionDefinition("MOVE", 0, &commands::move)},
    {"TURN_LEFT", ActionDefinition("TURN_LEFT", 0, &commands::turn_left)},
    {"TURN_RIGHT", ActionDefinition("TURN_RIGHT", 0, &commands::turn_right)},
    {"PLACE", ActionDefinition("PLACE", 3, &commands::place)},
    {"REPORT", ActionDefinition("REPORT", 0, &commands::report)}
};