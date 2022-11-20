cmake_minimum_required(VERSION 3.22)
project(DarkForest)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(
        DarkForest
        main.cpp
        Void/Void.cpp
        Void/Void.h
        Universe/Universe.cpp
        Universe/Universe.h
        Civilization/Civilization.cpp
        Civilization/Civilization.h
        CycleActions/CycleAction.cpp
        CycleActions/CycleAction.h
        CycleActions/CivilizationGeneration.cpp
        CycleActions/CivilizationGeneration.h
        Tools/Randomizer.cpp
        Tools/Randomizer.h
        Tools/Logger.cpp
        Tools/Logger.h
        CycleActions/CivilizationGrowth.cpp
        CycleActions/CivilizationGrowth.h
        Frontend/Drawer.cpp
        Frontend/Drawer.h
        Color/Color.h
        DataTypes/Vector2D.h)

target_link_libraries(DarkForest sfml-graphics)