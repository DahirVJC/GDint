//
// Created by Dahir on 04/09/2024.
//

#ifndef LEXER_H
#define LEXER_H
#include <list>
#include <string>
#include <utility>
#include "Automata.h"
#include "TransitionTable.h"
#include "TokenStruct.h"

// The lexer reads code as input and uses an automata to determine the token of each word and place it in the Token table
class Lexer {
    //Input
    Automata automata = transitionTableDFA;
    //Process
    int line = 1;
    //Output
    std::list<LexerToken> tokens;
public:
    // Constructor
    Lexer();
    Lexer(Automata automata) : automata(std::move(automata)) {}
    // Process
    void ReadInput(const std::string& code);
    std::string testState(int state);
    // Getters
    std::list<LexerToken> getTokens();
};
#endif //LEXER_H
