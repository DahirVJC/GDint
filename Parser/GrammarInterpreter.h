#ifndef GRAMMARINTERPRETER_H
#define GRAMMARINTERPRETER_H

#include <string>
#include <vector>

#include "Grammar.h"


class GrammarInterpreter {
    private:
    Grammar grammar;
    void interpretGrammar(const std::vector<std::string>& grammarRules);
    public:
    void readGrammar(const std::string &filename);
    Grammar getGrammar();
};



#endif //GRAMMARINTERPRETER_H
