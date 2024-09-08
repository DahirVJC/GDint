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

class Lexer {
    //Input
    Automata automata = transitionTable;
    //Process
    int line = 0;
    std::stack<char> stack;
    //Output
    struct Token {
        std::string name;
        std::string type;
        int line;
        Token(std::string n, std::string t, const int line) : name(std::move(n)), type(std::move(t)), line(line) {}
    };
    std::list<Token> tokens;
public:
    Lexer(Automata automata, const int state) : automata(std::move(automata)) {}
    void ReadInput(const std::string& code);
    std::string testState(int state);
    std::list<Token> getTokens();
};
#endif //LEXER_H
