
#include "Grammar.h"

#include <iostream>

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
            std::string nonTerminalPrime = nonTerminal + "'";

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
