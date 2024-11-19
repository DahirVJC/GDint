cmake_minimum_required(VERSION 3.29)
project(CLionProjects)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(antlr4)

include_directories(.,${CMAKE_SOURCE_DIR})

add_executable(CLionProjects
        Preprocessing/BlankCharacters.hpp
        Preprocessing/CleanCharacters.cpp
        Preprocessing/CleanCharacters.hpp
        Tools/FileHandler.cpp
        Tools/FileHandler.hpp
        Lexer/Lexer.h
        TokensTable.h
        Lexer/Lexer.cpp
        Lexer/StatesInfo.h
        Lexer/Automata.cpp
        Lexer/Automata.h
        Lexer/TransitionTable.h
        Compiler/Compiler.cpp
        Preprocessing/DoPreproccesing.h
        Lexer/DoLexicalAnalysis.h
        Lexer/TokenStruct.h
        Lexer/TransitionTable.cpp
        Tools/paths.h
        Parser/DoSyntaxAnalysis.h
        Parser/GrammarInterpreter.cpp
        Parser/GrammarInterpreter.h
        Tools/util.cpp
        Tools/util.h
        Parser/Grammar.cpp
        Parser/Grammar.h
        Tools/TokenTypes.h
        Parser/SyntaxNode.h
        Parser/SyntaxToken.h
)
