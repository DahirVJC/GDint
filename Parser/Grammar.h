#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <string>
#include <unordered_map>
#include <vector>


class Grammar {
private:
    //std::vector<std::pair<std::string No terminal, std::vector<std::vector<std::string Simbolos>Produccion >Producciones >>
    std::vector<std::pair<std::string, std::vector<std::vector<std::string>>>>  rules;
public:
    Grammar createToRightRecursion();
    std::vector<std::pair<std::string, std::vector<std::vector<std::string>>>> & getRules();
    void printGrammar();
};



#endif //GRAMMAR_H
