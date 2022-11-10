cmake_minimum_required(VERSION 3.23)
project(DarkForest)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        DarkForest
        main.cpp
        Void/Void.cpp
        Void/Void.h
        Universe/Universe.cpp
        Universe/Universe.h)
