#ifndef DOSYNTAXANALYSIS_H
#define DOSYNTAXANALYSIS_H
#include "GrammarInterpreter.h"
#include "SyntaxNode.h"

std::pair<std::shared_ptr<SyntaxNode>,std::list<SyntaxToken>> doSyntaxAnalysis(std::list<LexerToken> tokens) {
    GrammarInterpreter grammarReader;
    grammarReader.readGrammar("LL1Grammar.txt");
    Grammar grammar = grammarReader.getGrammar();
    std::pair<std::shared_ptr<SyntaxNode>,std::list<SyntaxToken>> result = grammar.syntaxAnalysis(tokens);
    if (nullptr != result.first) {
        printSyntaxTree(result.first);
        if (result.second.size() > 0) {
            printTokens(result.second);
        }
        std::cout << "Valido" << std::endl;
        return result;
    }
    return {nullptr, {}};
}
#endif //DOSYNTAXANALYSIS_H
