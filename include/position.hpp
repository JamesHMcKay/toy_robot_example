#ifndef __POSITION_H__
#define __POSITION_H__

#include "directions.hpp"

struct Position {
    int x;

    int y;

public:
    Position(int x, int y) : x(x), y(y) {}
    // no exception thrown for negative coordinates since it is an expected possible user input
    // which is handled by Robot position validation instead

    Position() : x(0), y(0) {}

    void move(Direction direction, int magnitude);

    friend bool operator== (const Position& p1, const Position& p2);

    friend bool operator!= (const Position& p1, const Position& p2);
};


#endif // __POSITION_H__
