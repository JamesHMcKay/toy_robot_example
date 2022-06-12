#!/bin/bash

# This is a very basic end-to-end test using the examples in the test_data folder.
# Usage: ./end_to_end_tests.sh <path to project root> <path to robot executable>
# For example ./end_to_end_tests.sh . build/robot
# This test is included in the cmake tests using the add_test command.

scenarios=(
    "scenario_a"
    "scenario_b"
    "scenario_c"
)

expected_output=(
    "Output: 0,1,NORTH"
    "Output: 0,0,WEST"
    "Output: 3,3,NORTH"
)

for i in {0..2}
do
    actual_output="$(./$2 -f $1/test_data/${scenarios[$i]}.txt)"

    if [[ $actual_output != ${expected_output[$i]} ]]; then
        echo "Test failed for ${scenarios[$i]}"
        echo "Expected: ${expected_output[$i]}"
        echo "Got: $actual_output"
        exit 1
    else
        echo "Test passed for ${scenarios[$i]}"
    fi
done
