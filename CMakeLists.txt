cmake_minimum_required(VERSION 3.15)
project(solver_a)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(solver_a
        Demo.cpp
        doctest.h
        solver.cpp
        solver.hpp
        TestCounter.cpp)
