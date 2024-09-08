#ifndef TOKENSTRUCT_H
#define TOKENSTRUCT_H

#include <string>

struct Token {
    std::string name;
    std::string type;
    int line;
    Token(std::string n, std::string t, const int line) : name(std::move(n)), type(std::move(t)), line(line) {}
};
#endif
