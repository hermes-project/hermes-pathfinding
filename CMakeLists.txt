cmake_minimum_required(VERSION 3.9)
project(Hermes_pathfinding)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 11)

add_executable(Hermes_pathfinding
        main.cpp
        smartMaths/Vector.cpp
        smartMaths/Vector.h
        smartMaths/maths_lib.h
        smartMaths/Ellipse.cpp
        smartMaths/Ellipse.h
        graph/Node.cpp
        graph/Node.h
        graph/Ridge.cpp
        graph/Ridge.h
        smartMaths/Circle.cpp
        smartMaths/Circle.h)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
target_link_libraries(Hermes_pathfinding Qt5::Core Qt5::Widgets)