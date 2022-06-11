#include "robot.hpp"

Robot::Robot(Table* table) : table(table) {
    x = 0;
    y = 0;
    direction = Direction::NORTH;
    initialised = false;
}


bool Robot::is_initialised() {
    return initialised;
}

std::string Robot::report() {
    std::stringstream ss;

    std::string direction_string;
    for (auto value : DIRECTION_MAP) {
        if (value.second == direction) {
            direction_string = value.first;
            break;
        }
    }

    ss << "X: " << x << " Y: " << y << " Direction: " << direction_string;
    return ss.str();
}

void Robot::turn_left() {
    int direction_index = static_cast<int>(direction);
    int direction_length = static_cast<int>(DIRECTION_MAP.size());
    direction_index = (direction_index + direction_length - 1) % direction_length;
    direction = static_cast<Direction>(direction_index);
}

void Robot::turn_right() {
    int direction_index = static_cast<int>(direction);
    int direction_length = static_cast<int>(DIRECTION_MAP.size());
    direction_index = (direction_index + 1) % direction_length;
    direction = static_cast<Direction>(direction_index);
}

void Robot::place(int _x, int _y, Direction _direction) {
    if (table->is_on_table(_x, _y)) {
        x = _x;
        y = _y;
        direction = _direction;
        initialised = true;
    }
    else {
        std::cout << "Invalid position" << std::endl;
    }
}

void Robot::move() {
    int new_x = x;
    int new_y = y;
    switch (direction) {
    case 0:
        new_y++;
        break;
    case 1:
        new_x++;
        break;
    case 2:
        new_y--;
        break;
    case 3:
        new_x--;
        break;
    }
    if (table->is_on_table(new_x, new_y)) {
        x = new_x;
        y = new_y;
    }
    else {
        std::cout << "Cannot move off the table!" << std::endl;
    }
}
