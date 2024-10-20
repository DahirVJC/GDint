
#include "GrammarInterpreter.h"

#include <sstream>

#include "../Tools/FileHandler.hpp"
#include "../Tools/paths.h"
#include "../Tools/util.h"

void GrammarInterpreter::interpretGrammar(const std::vector<std::string>& grammarRules) {
    for (const std::string& rule: grammarRules) {
        const size_t arrowPos = rule.find("->");// Encontrar la posicion de la flecha

        std::string nonTerminal = (rule.substr(0, arrowPos));// Todo lo que esta antes de la flecha es no terminal
        std::string productions = (rule.substr(arrowPos + 2));// Despues de la flecha, todo es una produccion

        std::vector<std::string> productionsRules = splitByChar(productions,'|');// Estructura {"ExpTerm"},{"Term"}

        std::vector<std::vector<std::string>> productionRulesSymbols;// Estructura {{"Exp"},{"Term"}},{{"Term"}}

        for (const std::string& production: productionsRules) {// Para cada produccion...
            std::vector<std::string> symbols = splitByChar(production, ' ');// Dividir por espacios

            for (std::string& symbol : symbols) {// Cambiar operatores por su respectivo simbolo
                if (symbol == "space") symbol = " ";
                if (symbol == "salto") symbol = "\n";
                if(symbol == "or") symbol = "||";
            }
            productionRulesSymbols.push_back(symbols);// Insertar simbolos como produccion
        }
        grammar.getRules().emplace_back(nonTerminal, productionRulesSymbols); // Establecer regla
    }
}

void GrammarInterpreter::readGrammar(const std::string &filename) {
    interpretGrammar(splitByChar(readFileToString(inputPath+"/"+filename),'\n'));
}

Grammar GrammarInterpreter::getGrammar() {
    return grammar;
}
