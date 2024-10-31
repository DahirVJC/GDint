#ifndef SYNTAXTOKEN_H
#define SYNTAXTOKEN_H
#include <string>

struct SyntaxToken {
    std::string name;
    std::string tokenType;
    int line;
    std::string dataType;
    SyntaxToken(std::string n, std::string t, const int line, std::string d) : name(std::move(n)), tokenType(std::move(t)), line(line), dataType(std::move(d))  {}
};
#endif //SYNTAXTOKEN_H
