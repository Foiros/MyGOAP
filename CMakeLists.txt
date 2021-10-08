cmake_minimum_required(VERSION 3.20)
project(MyGOAP)

set(CMAKE_CXX_STANDARD 23)

add_executable(MyGOAP main.cpp A-Star/PathfindingGrid.cpp A-Star/PathfindingGrid.h A-Star/Pathfinder.cpp A-Star/Pathfinder.h A-Star/Node.cpp A-Star/Node.h GOAP/Worker.cpp GOAP/Worker.h GOAP/Brain.cpp GOAP/Brain.h GOAP/Action.cpp GOAP/Action.h GOAP/GatherFood.h GOAP/BuildWeapons.h GOAP/Eat.h GOAP/Sleep.h GOAP/BuildWeapons.cpp GOAP/Eat.cpp GOAP/Sleep.cpp GOAP/GatherFood.cpp)
