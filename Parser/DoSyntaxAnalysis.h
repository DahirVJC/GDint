#ifndef DOSYNTAXANALYSIS_H
#define DOSYNTAXANALYSIS_H
#include "GrammarInterpreter.h"
#include "SyntaxNode.h"

inline void printTokens(const std::list<SyntaxToken> &tokens) {
    for (const SyntaxToken& token : tokens) {
        std::string nameToPrint = (token.name == "\n") ? "\\n" : token.name;
        std::cout << "Token(name: " << nameToPrint
                    << ", token type: " << token.tokenType
                    << ", line: " << token.line
                    << ", data type: " << token.dataType
                    << ")" << std::endl;
    }
}

bool DoSyntaxAnalysis(std::list<LexerToken> tokens) {
    GrammarInterpreter grammarReader;
    grammarReader.readGrammar("LL1Grammar.txt");
    Grammar grammar = grammarReader.getGrammar();
    std::pair<std::shared_ptr<SyntaxNode>,std::list<SyntaxToken>> result = grammar.SyntaxAnalysis(tokens);
    if (nullptr != result.first) {
        printSyntaxTree(result.first);
        if (result.second.size() > 0) {
            printTokens(result.second);
        }
        std::cout << "Valido" << std::endl;
        return true;
    }
    return false;
}
#endif //DOSYNTAXANALYSIS_H
