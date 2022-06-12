#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "utils.hpp"

TEST(test_utils, parse_int_success) {
    std::string raw_input = " 1 ";

    int result = utils::get_positive_int(raw_input, "test");

    EXPECT_EQ(result, 1);
}

TEST(test_utils, parse_int_fail) {
    std::string raw_input = "a";

    int result = utils::get_positive_int(raw_input, "test");

    EXPECT_EQ(result, -1);
}

TEST(test_utils, string_similarity) {
    std::string input_a = "abc";
    std::string input_b = "a b 123";

    int result = utils::string_similarity(input_a, input_b);

    EXPECT_EQ(result, 2);
}

TEST(test_utils, string_similarity_2) {
    std::string input_a = "Abc";
    std::string input_b = "ba 123 c";

    int result = utils::string_similarity(input_a, input_b);

    EXPECT_EQ(result, 3);
}

TEST(test_utils, split) {
    std::string input = "a,b,c";

    std::vector<std::string> result = utils::split(input, ",");

    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "b");
    EXPECT_EQ(result[2], "c");
}


TEST(test_utils, suggest) {
    std::string input = "TEST";
    testing::internal::CaptureStdout();

    std::vector<std::string> options = { "testing", "something" };


    utils::suggest(input, options);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Did you mean testing?\n");
}
