cmake_minimum_required(VERSION 3.13)
project(bout_helper)

set(CMAKE_CXX_STANDARD 17)

add_executable(bout_helper main.cpp src/Fighter.cpp include/Fighter.hpp src/Bout.cpp include/Bout.hpp include/EnumClasses.hpp src/Ladder.cpp include/Ladder.hpp src/Scoreboard.cpp include/Scoreboard.hpp src/Tournament.cpp include/Tournament.hpp src/Rooster.cpp include/Rooster.hpp src/CSVManager.cpp include/CSVManager.hpp src/Collection.cpp include/Collection.hpp include/PrimitiveTypes.hpp src/Score.cpp include/Score.hpp src/Utilities.cpp include/Utilities.hpp FighterCollection.cpp FighterCollection.hpp)