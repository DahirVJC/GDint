
#include "Grammar.h"

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>

#include "../Tools/TokenTypes.h"
#include "../Tools/util.h"

// Precondicion: La gramatica sigue con el consenso de escritura. El nombre de la regla como parametro.
// Postcondicion: Regresa true si la regla es no terminal y false si es terminal. Esto se define apartir del consenso.
bool Grammar::isNonTerminal(const std::string &rule) {
    for (char c : rule) {
        if (std::isupper(c)) {
            return true;
        }
        if (c != '\'') {
            return false;
        }
    }
    return false;
}

bool Grammar::hasEpsilon(const std::string &rule) {
    const std::vector<std::vector<std::string>> productions = getProductions(rule);

    for (auto production : productions) {
        if(production.at(0) == "ε") return true;
    }
    return false;
}

Productions Grammar::getProductions(const std::string& ruleName) {
    for(const auto& rule : this->rules) {
        if(rule.first == ruleName) {
            return rule.second;
        }
    }
    return {};
}

std::vector<Rule> Grammar::getProducerRules(const std::string& ruleName) {
    std::vector<Rule> producerRules;

    for (const auto& rule : this->rules) {
        bool found = false;

        for (const auto& production : rule.second) {
            for (const auto& symbol : production) {
                if (symbol == ruleName) {
                    producerRules.push_back(rule);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }
    return producerRules;
}

std::vector<std::string> Grammar::doFirst(const std::string &symbol) {
    std::vector<std::string> result;
    first(result, symbol);
    return result;
}

std::set<std::string> Grammar::doFollow(const std::string &symbol) {
    std::set<std::string> result;
    follow(result, symbol);
    return result;
}

void Grammar::first(std::vector<std::string>& firstSym, const std::string &symbol) {
    std::vector<std::vector<std::string>> productions = this->getProductions(symbol);
    for (const auto& production : productions) {
        if(isNonTerminal(production[0])) {
            first(firstSym, production[0]);
        }
        else {
            firstSym.push_back(production[0]);
        }
    }
}

void Grammar::firstNoEpsilon(std::set<std::string> &firstSym, const std::string &symbol) {
    Productions productions = this->getProductions(symbol);

    for (const auto& production : productions) {
        if(isNonTerminal(production[0])) {
            firstNoEpsilon(firstSym, production[0]);
        }
        else {
            if (production[0] != "ε") {
                firstSym.insert(production[0]);
            }
        }
    }
}

void Grammar::follow(std::set<std::string> &followSym, const std::string &symbol) {
    if (rules.at(0).first == symbol) followSym.insert("EOF");

    for (const auto& rule : this->rules) {
        if (rule.first != symbol) {
            for (const auto& production : rule.second) {
                for (int i = 0; i < production.size(); i++) {
                    const auto& sym = production[i];

                    if (sym == symbol) {
                        if (i + 1 < production.size()) {
                            if(isNonTerminal(production[i + 1])) {
                                firstNoEpsilon(followSym, production[i + 1]);
                                if (hasEpsilon(production[i + 1])) follow(followSym, rule.first);
                            }
                            else {
                                followSym.insert(production[i + 1]);
                            }
                        }
                        else {
                            follow(followSym, rule.first);
                        }
                    }
                }
            }
        }
    }
}

Production Grammar::getFirstProduction(const std::string &symbol, const std::string &ruleName) {
    for (const auto& rule : this->rules) {
        if (rule.first == ruleName) {
            for (const auto& production : rule.second) {
                if(production[0] == symbol) {
                    return production;
                }
                if(isNonTerminal(production[0])) {
                    Production result = getFirstProduction(symbol, production[0]);
                    if (!result.empty()) {
                        return production;
                    }
                }
            }
        }
    }
    return {};
}

std::set<std::string> Grammar::getAllTerminalSymbols() {
    std::set<std::string> result;
    for(const auto& rule : this->rules) {
        for (const auto& production : rule.second) {
            for (const auto& symbol : production) {
                if (!isNonTerminal(symbol)) result.insert(symbol);
            }
        }
    }
    return result;
}

void Grammar::createParserTable() {
    for (const auto& rule : this->rules) {
        std::vector<std::string> firstSym = doFirst(rule.first);

        for (const auto& symbol : firstSym) {
            Production production = getFirstProduction(symbol, rule.first);
            if (symbol == "∈Σ-'") {
                for (const auto& termSym : getAllTerminalSymbols()) {
                    if (termSym != "'") parserTable[std::make_pair(rule.first,termSym)] = production;
                }
                for (const auto& charSym : butCharGetAllChars('\'')) {
                    if (parserTable[std::make_pair(rule.first, std::string (1, charSym))].empty()) {
                        parserTable[std::make_pair(rule.first,std::string (1, charSym))] = production;
                    }
                }
            }
            else parserTable[std::make_pair(rule.first,symbol)] = production;
        }


        if (hasEpsilon(rule.first)) {
            std::string e = "ε";
            std::set<std::string> followSym = doFollow(rule.first);

            for (const auto& symbol : followSym) {
                if (symbol != "ε" && parserTable[std::make_pair(rule.first, symbol)].empty()) {
                    parserTable[std::make_pair(rule.first, symbol)] = {"ε"};
                }
            }
        }
    }
}

std::string Grammar::usedToken(LexerToken token) {
    if (token.type == IDENTIFIER ) return "identificador";
    if (token.type == CONSTANT) return "constante";
    return token.name;
}

Grammar Grammar::createToRightRecursion() {
    Grammar newGrammar;

    for (const auto& rule : this->rules) { // Para cada regla...
        std::string nonTerminal = rule.first; //Obtener el no terminal
        const Productions& productions = rule.second; //Obtener lo que produce
        Productions alpha, beta;

        for (const Production& production : productions) { // Para cada produccion
            if (production[0] == nonTerminal) { // Si el primer simbolo es recursivo
                // Insertar los siguientes simbolos
                // Source: https://www.geeksforgeeks.org/how-to-extract-a-subvector-from-a-vector-in-cpp/
                Production alphaProduction(production.begin() + 1, production.end());
                alpha.push_back(alphaProduction);
            } else {
                // Sino, inserta a simbolos beta
                beta.push_back(production);
            }
        }
        if (!alpha.empty()) { // Comprobar que hay simbolos alfa para verificar la recursion
            std::string nonTerminalPrime = nonTerminal + "\'";

            // Aplicar x = beta x'
            for (Production& betaProd : beta) { // Para cada todas las producciones beta
                betaProd.push_back(nonTerminalPrime); // Agregar el simbolo no terminal
                newGrammar.getRules().push_back({nonTerminal, {betaProd}}); // Establecer nuevas producciones de x
            }

            // Aplicar x' = alfa 1 x' | alfa 2 x' | ... | alfa n x'
            Productions primeProductions;
            for (std::vector<std::string>& alphaProd : alpha) { // Para cada produccion alfa
                alphaProd.push_back(nonTerminalPrime); // Agregar el no terminal primo
                primeProductions.push_back(alphaProd); // Agregar a las producciones de x'
            }
            // Aplicar x' = ε
            primeProductions.push_back({"ε"}); // Agregar epsilon a las producciones de x'
            newGrammar.getRules().emplace_back(nonTerminalPrime, primeProductions); // Establecer regla
        } else {
            // Si no hay recursividad, dejar la regla como esta
            newGrammar.getRules().emplace_back(rule);
        }
    }
    return newGrammar;
}

Grammar Grammar::createFactorizedGrammar() {
    Grammar newGrammar;
    for (const auto& rule : this->rules) {
        // Verify if first
    }
    return newGrammar;
}

Grammar Grammar::createLL1Grammar() {
    return createToRightRecursion().createFactorizedGrammar();
}

std::vector<std::pair<std::string, std::vector<std::vector<std::string>>>>  & Grammar::getRules() {
    return rules;
}

void Grammar::printGrammar() {
    for (const auto &rule : this->rules) {
        std::cout << rule.first << " -> "; // Imprimir no terminal

        for (int i = 0; i < rule.second.size(); ++i) { // Por cada produccion
            for (const std::string& symbol : rule.second[i]) { // Por cada simbolo de la produccion
                // Imprimir con espacio
                std::cout << symbolFormat(symbol) << " ";
            }
            if (i < rule.second.size() - 1) {
                std::cout << "| "; // Si aun es la produccion final, imprime el simbolo de o (|)
            }
        }
        std::cout << std::endl;
    }
}

void Grammar::printFirst(const std::string &symbol) {
    std::vector<std::string> firstSym;
    firstSym = doFirst(symbol);
    for(const std::string& sym : firstSym) {
        if (sym == "\n") std::cout << R"(\n)";
        else if (sym == " ") std::cout << "space";
        else std::cout << sym;
        std::cout << " ";
    }
}

void Grammar::printFollow(const std::string &symbol) {
    std::set<std::string> followSym = doFollow(symbol);
    for(const std::string& sym : followSym) {
        std::cout << symbolFormat(sym) << " ";
    }
}

void Grammar::printAllFirsts() {
    for (const auto& rule : this->rules) {
        std::vector<std::string> firstSym;
        firstSym = doFirst(rule.first);
        std::cout << rule.first <<"=";
        for(const std::string& symbol : firstSym) {
            if (symbol == "\n") std::cout << R"(\n)";
            else if (symbol == " ") std::cout << "space";
            else std::cout << symbol;
            std::cout << " ";
        }
        std::cout<<std::endl;
    }
}

void Grammar::printAllFollows() {
    for (const auto& rule : this->rules) {
        std::set<std::string> followSym = doFollow(rule.first);
        std::cout << rule.first <<" = ";

        for(const std::string& symbol : followSym) {
            std::cout << symbolFormat(symbol) << " ";
        }
        std::cout<<std::endl;
    }
}

void Grammar::printPrintParserTable() {
    this->createParserTable();

    for (const auto& pair : parserTable) {
        const auto& key = pair.first;
        const auto& values = pair.second;
        std::cout << "En <" << symbolFormat(key.first) << "> dado [" << symbolFormat(key.second) << "] produce: ";

        for (const auto& value : values) {
            std::cout << symbolFormat(value) << " ";
        }
        std::cout << std::endl;
    }
}

// Algoritmo de Neso Academy https://www.youtube.com/watch?v=clkHOgZUGWU
std::shared_ptr<SyntaxNode> Grammar::SyntaxAnalysis(std::list<LexerToken> tokens) {
    createParserTable();

    std::stack<ParserState> memory;
    memory.emplace("EOF", nullptr); // Start with $
    std::shared_ptr<SyntaxNode> rootNode = std::make_shared<SyntaxNode>(rules.at(0).first);
    memory.emplace(rules.at(0).first, rootNode); // Add S

    std::vector<std::pair<std::string,std::string>> flowOfTokens;
    for (const auto& token : tokens) {
        flowOfTokens.push_back(std::make_pair(usedToken(token), token.name));
    }
    flowOfTokens.push_back(std::make_pair("EOF", "EOF"));

    int index = 0;

    bool inDeclaration = false;
    const std::string NUMBER = "Number";
    const std::string STRING = "String";
    std::string dataType = NUMBER;
    std::string idName = "0";
    std::unordered_map<std::string,std::string> idTypes;

    while (index < flowOfTokens.size()) {
        if (index == flowOfTokens.size() - 1 && memory.top().symbol == "EOF") break;

        if (isNonTerminal(memory.top().symbol)) {
            ParserState currentState = memory.top();
            if (parserTable[std::make_pair(memory.top().symbol, flowOfTokens.at(index).first)].empty()) {
                return nullptr;
            }

            if (memory.top().symbol == "DECLARACION") inDeclaration = true;

            Production symbols = parserTable[std::make_pair(memory.top().symbol, flowOfTokens.at(index).first)];

            std::cout << memory.top().symbol << " Produce: ";
            for (const auto& symbol : symbols) {
                std::cout << symbolFormat(symbol) << " ";
            }
            std::cout << "con " << symbolFormat(flowOfTokens[index].first) << std::endl;

            memory.pop();
            std::vector<ParserState> reverseStates;
            for(const std::string& symbol : symbols) {
                std::shared_ptr<SyntaxNode> newNode = std::make_shared<SyntaxNode>(symbol);
                currentState.node->children.push_back(newNode);
                reverseStates.emplace_back(symbol, newNode);
            }

            std::reverse(reverseStates.begin(), reverseStates.end());
            for (const auto& state : reverseStates) {
                memory.emplace(state);
            }
        }
        if (memory.top().symbol == flowOfTokens.at(index).first) {
            memory.top().node->value = symbolFormat(flowOfTokens.at(index).second);

            // En declaracion
            if (inDeclaration){
                if (memory.top().symbol == "identificador") {
                    // Es la variable a declarar
                    if (idName == "0") {
                        idName = flowOfTokens.at(index).second;
                        if (idTypes.find(idName) != idTypes.end()) {
                            std::cout << "Variable " << idName << " already declared" << std::endl;
                        }
                    }
                    // Usar el tipo de la variable si no es string
                    else {
                        if (idTypes.count(flowOfTokens.at(index).second) > 0) {
                            if (dataType != STRING) dataType = idTypes[flowOfTokens.at(index).second];
                        } else {
                            std::cout<<"Usage of undeclared variable: "<<flowOfTokens.at(index).second<<std::endl;
                        }
                    }
                }
                else if (flowOfTokens.at(index).first == "\n") {
                    if (idTypes.find(idName) == idTypes.end()) {
                        idTypes[idName] = dataType;
                        std::cout << idName << " es un "<< dataType << std::endl;
                        dataType = NUMBER;
                        inDeclaration = false;
                        idName = "0";
                    }
                    std::cout << "Variable " << idName << " already declared" << std::endl;
                }
            }

            memory.pop();
            index++;
        }
        else if (memory.top().symbol == "∈Σ-'" && flowOfTokens.at(index).first != "'") {
            memory.top().node->value = symbolFormat(flowOfTokens.at(index).second);
            memory.pop();
            index++;
            dataType = STRING;
        }
        else if (memory.top().symbol == "ε") {
            memory.top().node->value = "ε";
            memory.pop();
        }
    }

    if (memory.top().symbol == "EOF") return rootNode;
    if (memory.empty()) return rootNode;
    return nullptr;
}
