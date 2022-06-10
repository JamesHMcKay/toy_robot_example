cmake_minimum_required(VERSION 3.5)

project (robot)

set(SOURCES
    src/utils.cpp
    src/commands.cpp
    src/main.cpp
)

add_executable(robot ${SOURCES})

target_compile_options(robot PRIVATE -std=c++11)

target_include_directories(robot
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)