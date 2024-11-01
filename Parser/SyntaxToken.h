#ifndef SYNTAXTOKEN_H
#define SYNTAXTOKEN_H
#include <string>

#include "../Tools/util.h"

struct SyntaxToken {
    std::string name;
    std::string tokenType;
    int line;
    std::string dataType;
    SyntaxToken(std::string n, std::string t, const int line, std::string d) : name(std::move(n)), tokenType(std::move(t)), line(line), dataType(std::move(d))  {}
};


// Asistido por: ChatGPT
inline void printToken(const SyntaxToken &token) {
    std::cout << "Token(name: " << symbolFormat(token.name)
                << ", token type: " << token.tokenType
                << ", line: " << token.line
                << ", data type: " << token.dataType
                << ")" << std::endl;
}
// Fin Asistencia

inline void printTokens(const std::list<SyntaxToken> &tokens) {
    for (const SyntaxToken& token : tokens) {
        printToken(token);
    }
}
#endif //SYNTAXTOKEN_H
