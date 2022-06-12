#include "directions.hpp"

const std::map<std::string, Direction> DIRECTION_MAP = {
    {"NORTH", Direction::NORTH},
    {"SOUTH", Direction::SOUTH},
    {"EAST", Direction::EAST},
    {"WEST",  Direction::WEST}
};

const int N_DIRECTIONS = static_cast<int>(DIRECTION_MAP.size());

namespace directions {
    void turn_left(Direction& direction) {
        int index = (static_cast<int>(direction) + N_DIRECTIONS - 1) % N_DIRECTIONS;
        direction = static_cast<Direction>(index);
    }

    void turn_right(Direction& direction) {
        int index = (static_cast<int>(direction) + 1) % N_DIRECTIONS;
        direction = static_cast<Direction>(index);
    }
}
