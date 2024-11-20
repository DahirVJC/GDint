cmake_minimum_required(VERSION 3.29)
project(CLionProjects)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(NewLexer/Cpp)

include_directories(.,${CMAKE_SOURCE_DIR})
set(ANTLR_FILES
        NewLexer/Lexer.cpp
        NewLexer/Lexer.h
)

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

# Vincular con el runtime de ANTLR
target_link_libraries(CLionProjects antlr4_shared)