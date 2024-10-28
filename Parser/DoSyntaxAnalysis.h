#ifndef DOSYNTAXANALYSIS_H
#define DOSYNTAXANALYSIS_H
#include "GrammarInterpreter.h"
#include "SyntaxNode.h"

//TODO: Define return data type
bool DoSyntaxAnalysis(std::list<LexerToken> tokens) {
    GrammarInterpreter grammarReader;
    grammarReader.readGrammar("LL1Grammar.txt");
    Grammar grammar = grammarReader.getGrammar();
    std::shared_ptr<SyntaxNode> SyntaxTree = grammar.SyntaxAnalysis(tokens);
    if (nullptr != SyntaxTree) {
        printSyntaxTree(SyntaxTree);
        std::cout << "Valido" << std::endl;
        return true;
    }
    std::cerr << "Syntax Error" << std::endl;
    return false;
}
#endif //DOSYNTAXANALYSIS_H
