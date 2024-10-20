#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <string>
#include <vector>
#include <set>


class Grammar {
private:
    //std::vector<std::pair<std::string No terminal, std::vector<std::vector<std::string Simbolos>Produccion >Producciones >>
    std::vector<std::pair<std::string, std::vector<std::vector<std::string>>>>  rules;
    bool isNonTerminal (const std::string& rule);
    bool hasEpsilon (const std::string& rule);
    std::vector<std::vector<std::string>> getProductions(const std::string& ruleName);
    std::vector<std::pair<std::string, std::vector<std::vector<std::string>>>> getProducerRules(const std::string& ruleName);
    std::vector<std::string> doFirst(const std::string &symbol);
    std::set<std::string> doFollow(const std::string &symbol);
    void first(std::vector<std::string>& firstSym, const std::string &symbol);
    void firstNoEpsilon(std::set<std::string>& firstSym, const std::string &symbol);
    void follow(std::set<std::string>& followSym, const std::string &symbol);

public:
    Grammar createToRightRecursion();
    Grammar createFactorizedGrammar();
    Grammar createLL1Grammar();
    std::vector<std::pair<std::string, std::vector<std::vector<std::string>>>> & getRules();
    void printGrammar();
    void printFirst(std::string symbol);
    void printFollow(std::string symbol);
    void printAllFirsts();
    void printAllFollows();
};



#endif //GRAMMAR_H
