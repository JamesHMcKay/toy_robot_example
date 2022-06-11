
#include "gtest/gtest.h"
#include "directions.hpp"

TEST(test_directions, turn_left) {
    Direction direction = Direction::NORTH;
    directions::turn_left(direction);
    EXPECT_EQ(direction, Direction::WEST);
}

TEST(test_directions, turn_right) {
    Direction direction = Direction::NORTH;
    directions::turn_right(direction);
    EXPECT_EQ(direction, Direction::EAST);
}
