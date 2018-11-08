cmake_minimum_required (VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 11)

include(CTest)

set (CMAKE_PROJECT_NAME testrepo)
set (BINARY_NAME bin)
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)

set(CMAKE_BINARY_DIR  ${CMAKE_HOME_DIRECTORY}/build)
include_directories("${CMAKE_BINARY_DIR}")

set(BOOST_ROOT ${CMAKE_HOME_DIRECTORY}/boost)
find_package(Boost 1.68.0 COMPONENTS)
include_directories(${Boost_INCLUDE_DIRS})

message("Boost_INCLUDE_DIRS -> " ${Boost_INCLUDE_DIRS})
set(Boost_LIBRARIES ${CMAKE_HOME_DIRECTORY}/boost/stage/lib)
message("Boost_LIBRARIES -> " ${Boost_LIBRARIES})
include_directories(${Boost_LIBRARIES})

configure_file("${CMAKE_HOME_DIRECTORY}/config/_Config.h.in" "${CMAKE_BINARY_DIR}/MainConfig.h")

if (WIN32)
    configure_file ("${CMAKE_HOME_DIRECTORY}/config/WinConfig.h.in" "${CMAKE_BINARY_DIR}/osConfig.h")
endif (WIN32)

if (UNIX)
    while (APPLE)
        configure_file ("${CMAKE_HOME_DIRECTORY}/config/macConfig.h.in" "${CMAKE_BINARY_DIR}/osConfig.h")
        break()
    endwhile(APPLE)
    configure_file ("${CMAKE_HOME_DIRECTORY}/config/LinConfig.h.in" "${CMAKE_BINARY_DIR}/osConfig.h")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread")
endif (UNIX)

add_executable(${BINARY_NAME} test.cpp)
target_link_libraries(${BINARY_NAME} ${Boost_LIBRARIES}/libboost_thread.so.1.69.0)
add_test(DoesItRun bin)