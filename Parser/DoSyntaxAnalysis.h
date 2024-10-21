#ifndef DOSYNTAXANALYSIS_H
#define DOSYNTAXANALYSIS_H
#include "GrammarInterpreter.h"

//TODO: Define return data type
void DoSyntaxAnalysis(std::list<LexerToken> tokens) {
    GrammarInterpreter grammarReader;
    grammarReader.readGrammar("LL1Grammar.txt");
    Grammar grammar = grammarReader.getGrammar();
    grammar.printPrintParserTable();
    if (grammar.SyntaxAnalysis(tokens)) std::cout << "Valido" << std::endl;
    else std::cerr << "Syntax Error" << std::endl;
}
#endif //DOSYNTAXANALYSIS_H
