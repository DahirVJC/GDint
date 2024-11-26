#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>

#include "SyntaxNode.h"
#include "SyntaxToken.h"
#include "../Lexer/TokenStruct.h"

//std::vector<std::pair<std::string No terminal, std::vector<std::vector<std::string Simbolos>Produccion >Producciones >>
using Production = std::vector<std::string>;
using Productions = std::vector<Production>;
using Rule = std::pair<std::string, Productions>;

class Grammar {
private:
    // Atributos
    std::vector<Rule>  rules;
    std::map<std::pair<std::string, std::string>, Production> parserTable;
    // Metodos internos
    //  Informacion de un simbolo
    bool isNonTerminal (const std::string& rule);
    bool hasEpsilon (const std::string& rule);
    Productions getProductions(const std::string& ruleName);
    std::vector<Rule> getProducerRules(const std::string& ruleName);
    //  First y Follow
    std::vector<std::string> doFirst(const std::string &symbol);
    std::set<std::string> doFollow(const std::string &symbol);
    void first(std::vector<std::string>& firstSym, const std::string &symbol);
    void firstNoEpsilon(std::set<std::string>& firstSym, const std::string &symbol);
    void follow(std::set<std::string>& followSym, const std::string &symbol);
    Production getFirstProduction(const std::string &symbol, const std::string &ruleName);
    std::set<std::string> getAllTerminalSymbols();
    //  LL(1)
    void createParserTable();
    std::string usedToken(LexerToken token);
public:
    // Metodos externos
    Grammar createToRightRecursion();
    std::vector<Rule> & getRules();
    //  Metodos para imprimir
    void printGrammar();
    void printFirst(const std::string &symbol);
    void printFollow(const std::string &symbol);
    void printAllFirsts();
    void printAllFollows();
    void printPrintParserTable();
    //  Realizar el analisis sintactico
    std::pair<std::shared_ptr<SyntaxNode>,std::list<SyntaxToken>> syntaxAnalysis(std::list<LexerToken> tokens);
};



#endif //GRAMMAR_H
