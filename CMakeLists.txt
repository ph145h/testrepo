cmake_minimum_required (VERSION 2.8.11)
project (testrepo)
set(CMAKE_CXX_STANDARD 11)
include(CTest)

set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)

configure_file("${PROJECT_SOURCE_DIR}/config/_Config.h.in" "${PROJECT_BINARY_DIR}/MainConfig.h")
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

if (WIN32)
    configure_file ("${PROJECT_SOURCE_DIR}/config/WinConfig.h.in" "${PROJECT_BINARY_DIR}/osConfig.h")
endif (WIN32)

if (UNIX)
    while (APPLE)
        configure_file ("${PROJECT_SOURCE_DIR}/config/macConfig.h.in" "${PROJECT_BINARY_DIR}/osConfig.h")
        break()
    endwhile(APPLE)
    configure_file ("${PROJECT_SOURCE_DIR}/config/LinConfig.h.in" "${PROJECT_BINARY_DIR}/osConfig.h")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread")
endif (UNIX)

add_executable(bin test.cpp)
add_test(DoesItRun bin)