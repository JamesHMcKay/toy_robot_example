#include "directions.hpp"

const std::map<std::string, Direction> DIRECTION_MAP = {
    {"NORTH", Direction::NORTH},
    {"SOUTH", Direction::SOUTH},
    {"EAST", Direction::EAST},
    {"WEST",  Direction::WEST}
};

namespace directions {
    void turn_left(Direction& direction) {
        int direction_index = static_cast<int>(direction);
        int direction_length = static_cast<int>(DIRECTION_MAP.size());
        direction_index = (direction_index + direction_length - 1) % direction_length;
        direction = static_cast<Direction>(direction_index);
    }

    void turn_right(Direction& direction) {
        int direction_index = static_cast<int>(direction);
        int direction_length = static_cast<int>(DIRECTION_MAP.size());
        direction_index = (direction_index + 1) % direction_length;
        direction = static_cast<Direction>(direction_index);
    }
}
