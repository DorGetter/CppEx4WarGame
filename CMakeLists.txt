cmake_minimum_required(VERSION 3.16)
project(WarGame_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(WarGame_
        Board.cpp
        Board.hpp
        DemoGame.cpp
        DemoGame.hpp
        doctest.h
        FootCommander.hpp
        FootSoldier.hpp
        Paramedic.hpp
        ParamedicCommander.hpp
        Sniper.hpp
        SniperCommander.hpp
        Soldier.hpp
        Demo.cpp)
