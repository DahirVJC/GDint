#ifndef DOSYNTAXANALYSIS_H
#define DOSYNTAXANALYSIS_H
#include "GrammarInterpreter.h"

//TODO: Define return data type
void DoSyntaxAnalysis() {
    GrammarInterpreter grammarReader;
    grammarReader.readGrammar("LL1Grammar.txt");
    Grammar grammar = grammarReader.getGrammar();
    //grammar.printGrammar();
    //grammar.printFirst("CODIGO'");
    //grammar.printAllFirsts();
    //grammar.printFollow("EXP");
    grammar.printAllFollows();
}
#endif //DOSYNTAXANALYSIS_H
