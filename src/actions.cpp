#include "actions.hpp"

const std::map<std::string, ActionDefinition> ACTION_MAP = {
    {"MOVE", ActionDefinition("MOVE", 0, true, &commands::move)},
    {"LEFT", ActionDefinition("LEFT", 0, true, &commands::turn_left)},
    {"RIGHT", ActionDefinition("RIGHT", 0, true,&commands::turn_right)},
    {"PLACE", ActionDefinition("PLACE", 3, false, &commands::place)},
    {"REPORT", ActionDefinition("REPORT", 0, true, &commands::report)}
};