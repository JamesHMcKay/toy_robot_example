#ifndef __DIRECTIONS_H__
#define __DIRECTIONS_H__

#include <map>
#include <string>

enum class Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

extern const std::map<std::string, Direction> DIRECTION_MAP;

namespace directions {
    void turn_left(Direction& direction);

    void turn_right(Direction& direction);

}

#endif // __DIRECTIONS_H__
