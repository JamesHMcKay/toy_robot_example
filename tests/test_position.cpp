
#include "gtest/gtest.h"
#include "position.hpp"
#include "table.hpp"
#include "directions.hpp"


TEST(test_position, move) {
    Position position(0, 0);
    position.move(Direction::NORTH, 1);

    EXPECT_EQ(position.x, 0);
    EXPECT_EQ(position.y, 1);
}