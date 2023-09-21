cmake_minimum_required(VERSION 3.21.1)
project(DataStructures)

set(CMAKE_CXX_STANDARD 11)

add_executable(DataStructures main.cpp AddOnlyGraph.cpp
        Graph.cpp
        MyList.h
)
