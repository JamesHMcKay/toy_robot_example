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

bool operator== (const Position& p1, const Position& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!= (const Position& p1, const Position& p2) {
    return p1.x != p2.x || p1.y != p2.y;
}

