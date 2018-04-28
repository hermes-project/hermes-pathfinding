cmake_minimum_required(VERSION 3.9)
project(Hermes_pathfinding)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

add_executable(Hermes_pathfinding
        main.cpp
        smartMaths/Vector.cpp
        smartMaths/Vector.h
        smartMaths/maths_lib.h
        smartMaths/Ellipse.cpp
        smartMaths/Ellipse.h
        smartMaths/Circle.cpp
        smartMaths/Circle.h
        display/Window.cpp
        display/Window.h
        display/LandmarkFrame.h
        display/LandmarkFrame.cpp
        display/LogFrame.cpp
        display/LogFrame.h
        display/Menu.cpp
        display/Menu.h
        display/Line.cpp
        display/Line.h
        graph/Graph.h
        graph/Graph.cpp
        graph/Landmark.h
        graph/Landmark.cpp
        graph/Node.h
        graph/Node.cpp
        utils/Log.h
        utils/Log.cpp)

target_link_libraries(Hermes_pathfinding Qt5::Core Qt5::Widgets)