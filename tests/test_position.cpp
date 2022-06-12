
#include "gtest/gtest.h"
#include "position.hpp"

TEST(test_position, move) {
    Position position(0, 0);
    position.move(Direction::NORTH, 1);

    EXPECT_EQ(position.x, 0);
    EXPECT_EQ(position.y, 1);
}

TEST(test_position, compare) {
    Position position_1(1, 2);

    Position position_2(1, 2);

    EXPECT_EQ(position_1, position_2);
}

TEST(test_position, copy) {
    Position position_1(1, 2);

    Position position_2 = position_1;

    EXPECT_EQ(position_1, position_2);
}
