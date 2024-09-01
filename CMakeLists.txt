cmake_minimum_required(VERSION 3.29)
project(CLionProjects)

set(CMAKE_CXX_STANDARD 14)

include_directories(.,${CMAKE_SOURCE_DIR})

add_executable(CLionProjects
    BlankCharacters.hpp
    CleanCharacters.cpp
    CleanCharacters.hpp
    FileHandler.cpp
    FileHandler.hpp
    PreprocessCode.cpp)
