
#include "gtest/gtest.h"
#include "robot.hpp"
#include "table.hpp"

TEST(test_robot, not_initilised) {
    Table table(5, 5);
    Robot robot(&table);

    EXPECT_FALSE(robot.is_initialised());

    robot.place(Position(2, 0), Direction::NORTH);
}


TEST(test_robot, initilised) {
    Table table(5, 5);
    Robot robot(&table);

    robot.place(Position(2, 0), Direction::NORTH);

    EXPECT_TRUE(robot.is_initialised());
}


TEST(test_robot, move_off_table) {
    Table table(5, 5);
    Robot robot(&table);

    testing::internal::CaptureStdout();
    robot.place(Position(4, 4), Direction::NORTH);
    robot.move();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Cannot move off the table!\n");
}


TEST(test_robot, series_of_commands) {
    Table table(5, 5);
    Robot robot(&table);

    robot.place(Position(0, 0), Direction::NORTH);
    robot.move();
    robot.move();
    Position new_position = robot.get_position();
    EXPECT_EQ(new_position, Position(0, 2));
}

TEST(test_robot, stays_on_table) {
    Table table(5, 5);
    Robot robot(&table);

    robot.place(Position(4, 4), Direction::NORTH);
    robot.move();
    robot.move();
    robot.move();
    Position new_position = robot.get_position();
    EXPECT_EQ(new_position, Position(4, 4));
}
