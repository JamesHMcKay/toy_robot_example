#include "position.hpp"

void Position::move(Direction direction, int magnitude) {
    switch (direction) {
    case Direction::NORTH:
        y += magnitude;
        break;
    case Direction::EAST:
        x += magnitude;
        break;
    case Direction::SOUTH:
        y -= magnitude;
        break;
    case Direction::WEST:
        x -= magnitude;
        break;
    }
}