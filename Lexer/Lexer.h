//
// Created by Dahir on 04/09/2024.
//

#ifndef LEXER_H
#define LEXER_H
#include <list>
#include <stack>
#include <string>
#include <utility>
#include "Automata.h"
#include "TransitionTable.h"

// The lexer reads code as input and uses an automata to determine the token of each word and place it in the Token table
class Lexer {
    //Input
    Automata automata = transitionTable;
    //Process
    int line = 0;
    //Output
    struct Token {
        std::string name;
        std::string type;
        int line;
        Token(std::string n, std::string t, const int line) : name(std::move(n)), type(std::move(t)), line(line) {}
    };
    std::list<Token> tokens;
public:
    // Constructor
    Lexer(Automata automata, const int state) : automata(std::move(automata)) {}
    // Process
    void ReadInput(const std::string& code);
    std::string testState(int state);
    // Getters
    std::list<Token> getTokens();
};
#endif //LEXER_H
