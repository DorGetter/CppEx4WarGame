cmake_minimum_required(VERSION 3.16)
project(wargame_a)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(wargame_a
        Board.cpp
        Board.hpp FootSoldier.hpp FootCommander.hpp Sniper.hpp SniperCommander.hpp Paramedic.hpp ParamedicCommander.hpp Run.cpp)
