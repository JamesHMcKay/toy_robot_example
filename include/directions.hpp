#ifndef __DIRECTIONS_H__
#define __DIRECTIONS_H__

#include <map>

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

extern const std::map<std::string, Direction> DIRECTION_MAP;

#endif // __DIRECTIONS_H__
