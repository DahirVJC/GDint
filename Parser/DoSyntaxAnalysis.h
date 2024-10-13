#ifndef DOSYNTAXANALYSIS_H
#define DOSYNTAXANALYSIS_H
#include "GrammarInterpreter.h"

//TODO: Define return data type
void DoSyntaxAnalysis() {
    GrammarInterpreter grammar;
    grammar.readGrammar();
    grammar.getGrammar().createToRightRecursion().printGrammar();
}
#endif //DOSYNTAXANALYSIS_H
