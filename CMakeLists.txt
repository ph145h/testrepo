cmake_minimum_required (VERSION 2.8.11)
project (testrepo)
set(CMAKE_CXX_STANDARD 11)
set (testrepo_VERSION_MAJOR 0)
set (testrepo_VERSION_MINOR 2)

configure_file (
        "${PROJECT_SOURCE_DIR}/TestConfig.h.in"
        "${PROJECT_BINARY_DIR}/TestConfig.h"
)
include_directories("${PROJECT_BINARY_DIR}")

add_subdirectory (libraries)
include_directories("${PROJECT_SOURCE_DIR}/libraries")

add_executable(test test.cpp)