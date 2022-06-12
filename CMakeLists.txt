cmake_minimum_required(VERSION 3.14)

project (robot)

set(SOURCES
    src/directions.cpp
    src/actions.cpp
    src/utils.cpp
    src/commands.cpp
    src/user_input.cpp
    src/robot.cpp
    src/position.cpp
)

add_executable(robot src/main.cpp ${SOURCES})

target_compile_options(robot PRIVATE -std=c++11)

target_include_directories(
    robot
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# Prevent overriding the parent project's compiler/linker settings (from Google Test documentation)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  run_tests
  tests/main.cpp
  tests/test_table.cpp
  tests/test_robot.cpp
  tests/test_position.cpp
  tests/test_directions.cpp
  tests/test_user_input.cpp
  tests/test_utils.cpp
  ${SOURCES}
)
target_include_directories(
    run_tests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
  run_tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_tests)

add_test(NAME end_to_end COMMAND ../end_to_end_tests.sh ${PROJECT_SOURCE_DIR} robot)
