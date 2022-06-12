#include "robot.hpp"

Robot::Robot(Table* table) : table(table) {
    position = Position(0, 0);
    direction = Direction::NORTH;
    initialised = false;
}

bool Robot::is_initialised() {
    return initialised;
}

Position Robot::get_position() {
    return position;
}

Direction Robot::get_direction() {
    return direction;
}

void Robot::set_direction(Direction new_direction) {
    direction = new_direction;
}

void Robot::place(Position new_position, Direction new_direction) {
    if (table->is_on_table(new_position)) {
        position = new_position;
        direction = new_direction;
        initialised = true;
    }
    else {
        std::cout << "Invalid robot placement" << std::endl;
    }
}

void Robot::move() {
    Position new_position = position;
    new_position.move(direction, step_size);
    if (table->is_on_table(new_position)) {
        position = new_position;
    }
    else {
        std::cout << "Cannot move off the table!" << std::endl;
    }
}
