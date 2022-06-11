#ifndef __ROBOT_H__
#define __ROBOT_H__

#include <iostream>
#include <sstream>

#include "directions.hpp"
#include "table.hpp"
#include "position.hpp"


class Robot {
    int x;
    int y;
    Direction direction;
    bool initialised;
    Table* table;

    static const int step_size = 1;

public:
    Robot(Table* _table);

    bool is_initialised();

    std::string report();

    void turn_left();

    void turn_right();

    void place(int _x, int _y, Direction _direction);

    void move();
};

#endif // __ROBOT_H__
