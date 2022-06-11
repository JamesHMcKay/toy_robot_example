
#include "gtest/gtest.h"
#include "table.hpp"

TEST(test_table, within_bounds) {
  Table table(5, 5);
  EXPECT_TRUE(table.is_on_table(Position(2, 0)));
}

TEST(test_table, within_bounds_on_edge) {
  Table table(5, 5);
  EXPECT_TRUE(table.is_on_table(Position(4, 4)));
}

TEST(test_table, out_of_bounds) {
  Table table(1, 2);
  EXPECT_FALSE(table.is_on_table(Position(0, 10)));
}

TEST(test_table, out_of_bounds_negative) {
  Table table(5, 5);
  EXPECT_FALSE(table.is_on_table(Position(-1, 0)));
}
