cmake_minimum_required (VERSION 2.8.11)
project (testrepo)
set(CMAKE_CXX_STANDARD 11)
include(CTest)

set (testrepo_VERSION_MAJOR 0)
set (testrepo_VERSION_MINOR 1)

configure_file ("${PROJECT_SOURCE_DIR}/config/TestConfig.h.in" "${PROJECT_BINARY_DIR}/TestConfig.h")
include_directories("${PROJECT_BINARY_DIR}")

if (WIN32)
    configure_file ("${PROJECT_SOURCE_DIR}/config/windows/windows.h.in" "${PROJECT_BINARY_DIR}/os.h")
endif (WIN32)

if (UNIX)
    while (APPLE)
        configure_file ("${PROJECT_SOURCE_DIR}/config/macos/macos.h.in" "${PROJECT_BINARY_DIR}/os.h")
        break()
    endwhile(APPLE)
    configure_file ("${PROJECT_SOURCE_DIR}/config/linux/linux.h.in" "${PROJECT_BINARY_DIR}/os.h")
endif (UNIX)

add_executable(bin test.cpp)
add_test(DoesItRun bin)