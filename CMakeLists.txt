cmake_minimum_required(VERSION 3.12)
project(pwr-racing-entry CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(convex_hull src/main.cpp)
target_include_directories(convex_hull PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
