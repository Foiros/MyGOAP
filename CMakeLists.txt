cmake_minimum_required(VERSION 3.20)
project(MyGOAP)

set(CMAKE_CXX_STANDARD 23)

add_executable(MyGOAP main.cpp A-Star/PathfindingGrid.cpp A-Star/PathfindingGrid.h GOAP/SimpleGOAP.cpp GOAP/SimpleGOAP.h A-Star/Pathfinder.cpp A-Star/Pathfinder.h A-Star/Node.cpp A-Star/Node.h)
