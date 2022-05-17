cmake_minimum_required(VERSION 3.5)

project(game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ball_game STATIC ball_game.cpp ball_game.h)

add_executable(game main.cpp)
add_dependencies(game ball_game)
target_link_libraries(game ball_game)

