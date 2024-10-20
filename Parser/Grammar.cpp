
#include "Grammar.h"

#include <iostream>
#include <algorithm>

// Precondicion: La gramatica sigue con el consenso de escritura. El nombre de la regla como parametro.
// Postcondicion: Regresa true si la regla es no terminal y false si es terminal. Esto se define apartir del consenso.
bool Grammar::isNonTerminal(const std::string &rule) {
    for (char c : rule) {
        if (std::isupper(c)) {
            return true;
        }
        else if (c != '\'') {
            return false;
        }
    }
}

bool Grammar::hasEpsilon(const std::string &rule) {
    const std::vector<std::vector<std::string>> productions = getProductions(rule);
    for (auto production : productions) {
        if(production.at(0) == "ε") return true;
    }
    return false;
}

std::vector<std::vector<std::string>> Grammar::getProductions(const std::string& ruleName) {
    for(const auto& rule : this->rules) {
        if(rule.first == ruleName) {
            return rule.second;
        }
    }
    return {};
}

std::vector<std::pair<std::string, std::vector<std::vector<std::string>>>> Grammar::getProducerRules(const std::string& ruleName) {
    std::vector<std::pair<std::string, std::vector<std::vector<std::string>>>> producerRules;

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
    std::vector<std::vector<std::string>> productions = this->getProductions(symbol);
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
                                if (hasEpsilon(production[i + 1])) follow(followSym, production[i + 1]);
                            }
                            else {
                                followSym.insert(production[i + 1]);
                            }
                        }
                        else {
                            follow(followSym, rule.first);
                        }
                        break;
                    }
                }
            }
        }
    }
}

Grammar Grammar::createToRightRecursion() {
    Grammar newGrammar;

    for (const auto& rule : this->rules) { // Para cada regla...
        std::string nonTerminal = rule.first; //Obtener el no terminal
        const std::vector<std::vector<std::string>>& productions = rule.second; //Obtener lo que produce

        std::vector<std::vector<std::string>> alpha, beta;

        for (const std::vector<std::string>& production : productions) { // Para cada produccion
            if (production[0] == nonTerminal) { // Si el primer simbolo es recursivo
                // Insertar los siguientes simbolos
                // Source: https://www.geeksforgeeks.org/how-to-extract-a-subvector-from-a-vector-in-cpp/
                std::vector<std::string> alphaProduction(production.begin() + 1, production.end());
                alpha.push_back(alphaProduction);
            } else {
                // Sino, inserta a simbolos beta
                beta.push_back(production);
            }
        }

        if (!alpha.empty()) { // Comprobar que hay simbolos alfa para verificar la recursion
            std::string nonTerminalPrime = nonTerminal + "\'";

            // Aplicar x = beta x'
            for (std::vector<std::string>& betaProd : beta) { // Para cada todas las producciones beta
                betaProd.push_back(nonTerminalPrime); // Agregar el simbolo no terminal
                newGrammar.getRules().push_back({nonTerminal, {betaProd}}); // Establecer nuevas producciones de x
            }

            // Aplicar x' = alfa 1 x' | alfa 2 x' | ... | alfa n x'
            std::vector<std::vector<std::string>> primeProductions;
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
                if (symbol == "\n") std::cout << R"(\n)";
                else if (symbol == " ") std::cout << "space";
                else std::cout << symbol;
                std::cout << " ";
            }

            if (i < rule.second.size() - 1) {
                std::cout << "| "; // Si aun es la produccion final, imprime el simbolo de o (|)
            }
        }
        std::cout << std::endl;
    }
}

void Grammar::printFirst(std::string symbol) {
    std::vector<std::string> firstSym;
    firstSym = doFirst(symbol);
    for(const std::string& sym : firstSym) {
        if (sym == "\n") std::cout << R"(\n)";
        else if (sym == " ") std::cout << "space";
        else std::cout << sym;
        std::cout << " ";
    }
}

void Grammar::printFollow(std::string symbol) {
    std::set<std::string> followSym;
    followSym = doFollow(symbol);
    for(const std::string& sym : followSym) {
        if (sym == "\n") std::cout << R"(\n)";
        else if (sym == " ") std::cout << "space";
        else std::cout << sym;
        std::cout << " ";
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
        std::set<std::string> followSym;
        followSym = doFollow(rule.first);
        std::cout << rule.first <<" = ";
        for(const std::string& symbol : followSym) {
            if (symbol == "\n") std::cout << R"(\n)";
            else if (symbol == " ") std::cout << "space";
            else std::cout << symbol;
            std::cout << " ";
        }
        std::cout<<std::endl;
    }
}
