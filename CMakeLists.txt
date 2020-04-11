cmake_minimum_required(VERSION 3.13)
project(bout_helper)

set(CMAKE_CXX_STANDARD 17)

add_executable(bout_helper main.cpp Fighter.cpp Fighter.hpp Bout.cpp Bout.hpp EnumClasses.hpp Ladder.cpp Ladder.hpp Scoreboard.cpp Scoreboard.hpp Tournament.cpp Tournament.hpp Rooster.cpp Rooster.hpp CSVManager.cpp CSVManager.hpp)