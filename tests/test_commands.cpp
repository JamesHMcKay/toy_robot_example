#include <vector>
#include <string>

#include "gtest/gtest.h"
#include "robot.hpp"
#include "table.hpp"
#include "commands.hpp"

TEST(test_commands, move) {
    Table table(5, 5);
    Robot robot(&table);
    robot.place(Position(0, 0), Direction::NORTH);
    std::vector<std::string> parameters;
    commands::move(robot, parameters);
    EXPECT_EQ(robot.get_position(), Position(0, 1));
}

TEST(test_commands, move_off_table) {
    // This duplicates testing from robot logic, but good to make sure
    // these commands are not able to override the expected behavior.
    Table table(5, 5);
    Robot robot(&table);
    robot.place(Position(0, 0), Direction::SOUTH);
    std::vector<std::string> parameters;
    commands::move(robot, parameters);
    EXPECT_EQ(robot.get_position(), Position(0, 0));
}

TEST(test_commands, turn_left) {
    Table table(5, 5);
    Robot robot(&table);
    robot.place(Position(0, 0), Direction::NORTH);
    std::vector<std::string> parameters;
    commands::turn_left(robot, parameters);
    EXPECT_EQ(robot.get_direction(), Direction::WEST);
}

TEST(test_commands, turn_right) {
    Table table(5, 5);
    Robot robot(&table);
    robot.place(Position(0, 0), Direction::NORTH);
    std::vector<std::string> parameters;
    commands::turn_right(robot, parameters);
    EXPECT_EQ(robot.get_direction(), Direction::EAST);
}

TEST(test_commands, place) {
    Table table(5, 5);
    Robot robot(&table);

    std::vector<std::string> parameters;
    parameters.push_back("1");
    parameters.push_back("2");
    parameters.push_back("NORTH");
    commands::place(robot, parameters);
    EXPECT_EQ(robot.get_position(), Position(1, 2));
    EXPECT_EQ(robot.get_direction(), Direction::NORTH);
}

TEST(test_commands, place_bad_input) {
    Table table(5, 5);
    Robot robot(&table);

    std::vector<std::string> parameters;
    parameters.push_back("1");
    parameters.push_back("2");
    parameters.push_back("SOMETHING");
    commands::place(robot, parameters);
    EXPECT_EQ(robot.is_initialised(), false);
}

TEST(test_commands, report) {
    Table table(5, 5);
    Robot robot(&table);

    robot.place(Position(1, 2), Direction::NORTH);

    testing::internal::CaptureStdout();

    std::vector<std::string> parameters;
    commands::report(robot, parameters);

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Output: 1,2,NORTH\n");
}
