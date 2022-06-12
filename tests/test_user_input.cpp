#include <string>

#include "gtest/gtest.h"
#include "user_input.hpp"

// There is a tight coupling here between these tests and the valid actions. Ideally this would
// be handled by injecting ACTION_MAP into the UserInput class, and then we could 
// control that here, but to keep things simpler I haven't done this for now as it's not really a big deal.

TEST(test_user_input, basic_action_parameter_split) {
    std::string raw_input = "PLACE 1,2,NORTH";

    UserInput user_input(raw_input);

    EXPECT_EQ(user_input.action, "PLACE");
    EXPECT_EQ(user_input.parameters.size(), 3);
}

TEST(test_user_input, unusual_input) {
    std::string raw_input = "something   some,more,stuff,here";

    UserInput user_input(raw_input);

    EXPECT_EQ(user_input.action, "something");
    EXPECT_EQ(user_input.parameters.size(), 4);
}

TEST(test_user_input, validation_of_action_name_false) {
    std::string raw_input = "something";

    UserInput user_input(raw_input);

    EXPECT_FALSE(user_input.validate());
}

TEST(test_user_input, validation_of_action_name_true) {
    std::string raw_input = "RIGHT";

    UserInput user_input(raw_input);

    EXPECT_TRUE(user_input.validate());
}


TEST(test_user_input, validation_of_parameters_true) {
    std::string raw_input = "PLACE 1,2,NORTH";

    UserInput user_input(raw_input);

    EXPECT_TRUE(user_input.validate());
}


TEST(test_user_input, validation_of_parameters_false) {
    std::string raw_input = "PLACE 1,NORTH";

    UserInput user_input(raw_input);

    EXPECT_FALSE(user_input.validate());
}
