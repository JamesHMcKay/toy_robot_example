#!/bin/bash

# This is a very basic end-to-end test based on the test data.
# Usage: ./end_to_end_tests.sh <path to project root>
# For example ./end_to_end_tests.sh . build/robot
# It is intended to run from a build directory, as used in the CMakeLists.txt file
# under the add_test command.

scenarios=("scenario_a" "scenario_b" "scenario_c")

expected=("Output: 0,1,NORTH" "Output: 0,0,WEST" "Output: 3,3,NORTH")

for i in {0..2}
do
    var="$(./$2 -f $1/test_data/${scenarios[$i]}.txt)"

    if [[ $var != ${expected[$i]} ]]; then
        echo "Test failed for ${scenarios[$i]}"
        echo "Expected: ${expected[$i]}"
        echo "Got: $var"
        exit 1
    else
        echo "Test passed for ${scenarios[$i]}"
    fi
done
