#ifndef __POSITION_H__
#define __POSITION_H__


#include "directions.hpp"

struct Position {
    int x;
    int y;

public:
    Position(int x, int y) : x(x), y(y) {}

    Position() : x(0), y(0) {}

    void move(Direction direction, int magnitude);
};

#endif // __POSITION_H__