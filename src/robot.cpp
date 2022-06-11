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
    directions::turn_left(direction);
}

void Robot::turn_right() {
    directions::turn_right(direction);
}

void Robot::place(int _x, int _y, Direction _direction) {
    Position position(_x, _y);
    if (table->is_on_table(position)) {
        x = _x;
        y = _y;
        direction = _direction;
        initialised = true;
    }
    else {
        std::cout << "Invalid position" << x << ", " << y << std::endl;
    }
}

void Robot::move() {
    Position new_position = { x, y };
    new_position.move(direction, step_size);
    if (table->is_on_table(new_position)) {
        x = new_position.x;
        y = new_position.y;
    }
    else {
        std::cout << "Cannot move off the table!" << std::endl;
    }
}
