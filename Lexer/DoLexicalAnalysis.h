#ifndef DOLEXICALANALYSIS_H
#define DOLEXICALANALYSIS_H
#include "Lexer.h"
#include "../Tools/FileHandler.hpp"
#include "TokenStruct.h"
#include <iostream>
#include <list>

void printTokens(const std::list<Token>& tokens) {
    for (const auto& token : tokens) {
        std::cout << "Token(name: " << token.name
                  << ", type: " << token.type
                  << ", line: " << token.line
                  << ")" << std::endl;
    }
}

std::list<Token> DoLexicalAnalysis(std::string code) {
    Lexer lexer;
    lexer.ReadInput(code);
    std::list<Token> TokenTable = lexer.getTokens();
    printTokens(TokenTable);
    return TokenTable;
}

#endif //DOLEXICALANALYSIS_H
