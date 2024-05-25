cmake_minimum_required(VERSION 3.27)
project(PDA_Acceptance)

set(CMAKE_CXX_STANDARD 17)

add_executable(PDA_Acceptance main.cpp
        PDA.h
        PDA.cpp
)
