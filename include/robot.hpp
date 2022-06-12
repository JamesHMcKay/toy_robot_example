#ifndef __ROBOT_H__
#define __ROBOT_H__

#include <iostream>
#include <sstream>

#include "directions.hpp"
#include "table.hpp"
#include "position.hpp"


class Robot {
    Position position;
    Direction direction;
    bool initialised;
    Table* table;

    static const int step_size = 1;

public:
    Robot(Table* _table);

    bool is_initialised();

    // std::string report();

    Position get_position();

    void set_direction(Direction new_direction);

    Direction get_direction();

    void place(Position new_position, Direction new_direction);

    void move();
};

#endif // __ROBOT_H__
