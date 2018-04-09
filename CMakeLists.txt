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
        graph/Node.cpp
        graph/Node.h
        graph/Ridge.cpp
        graph/Ridge.h
        smartMaths/Circle.cpp
        smartMaths/Circle.h display/Window.cpp display/Window.h display/Menu.cpp display/Menu.h graph/Graph.cpp graph/Graph.h graph/Landmark.cpp graph/Landmark.h display/LandmarkFrame.cpp display/LandmarkFrame.h)

target_link_libraries(Hermes_pathfinding Qt5::Core Qt5::Widgets)