#ifndef DOLEXICALANALYSIS_H
#define DOLEXICALANALYSIS_H
#include "Lexer.h"
#include "../Tools/FileHandler.hpp"
#include "TokenStruct.h"
#include <iostream>
#include <list>

// Asistido por: ChatGPT
inline void printTokens(const std::list<LexerToken>& tokens) {
    for (const LexerToken& token : tokens) {
        std::string nameToPrint = (token.name == "\n") ? "\\n" : token.name;
        std::cout << "Token(name: " << nameToPrint
                  << ", type: " << token.type
                  << ", line: " << token.line
                  << ")" << std::endl;
    }
}
// Fin Asistencia

inline std::list<LexerToken> doLexicalAnalysis(const std::string& code) {
    Lexer lexer;
    lexer.readInput(code);
    std::list<LexerToken> TokenTable = lexer.getTokens();
    printTokens(TokenTable);
    return TokenTable;
}

#endif //DOLEXICALANALYSIS_H
