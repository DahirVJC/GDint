cmake_minimum_required(VERSION 3.29)
project(CLionProjects)

set(CMAKE_CXX_STANDARD 14)

include_directories(.,${CMAKE_SOURCE_DIR})

add_executable(CLionProjects
        Preprocessing/BlankCharacters.hpp
        Preprocessing/CleanCharacters.cpp
        Preprocessing/CleanCharacters.hpp
        Preprocessing/FileHandler.cpp
        Preprocessing/FileHandler.hpp
        Preprocessing/PreprocessCode.cpp
        Lexer/Lexer.h
        TokensTable.h
        Lexer/Lexer.cpp
        Lexer/StatesToType.h
        Lexer/Automata.h)
