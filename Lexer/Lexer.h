//
// Created by Dahir on 04/09/2024.
//

#ifndef LEXER_H
#define LEXER_H
#include <list>
#include <stack>
#include <string>
#include <utility>

class Lexer {
private:
    std::stack<char> stack;
    struct Tokens {
        std::string name;
        std::string type;
        Tokens(std::string n, std::string t) : name(std::move(n)), type(std::move(t)) {}
    };
    std::list<Tokens> tokens;
    int state = 0;
    int line = 0;
public:
    void ReadInput(std::string code);
};
#endif //LEXER_H
