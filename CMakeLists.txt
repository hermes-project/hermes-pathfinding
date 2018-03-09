cmake_minimum_required(VERSION 3.9)
project(Hermes_pathfinding)

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