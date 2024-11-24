
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
    // Si es la primera regla insertar EOF ($)
    if (rules.at(0).first == symbol) followSym.insert("EOF");

    // Buscar todas las reglas en las que aparece
    for (const auto& rule : this->rules) {
        if (rule.first != symbol) {
            for (const auto& production : rule.second) {
                for (int i = 0; i < production.size(); i++) {
                    const auto& sym = production[i];

                    if (sym == symbol) {
                        // Revisar si hay un simbolo que le sigue
                        if (i + 1 < production.size()) {
                            if(isNonTerminal(production[i + 1])) {
                                // Follow(sym) Union = First(sym siguiente) - {ε}
                                firstNoEpsilon(followSym, production[i + 1]);
                                // Si ε pertence al first del siguiente simbolo
                                std::vector<std::string> firstSig = doFirst(production[i + 1]);
                                // Si es asi, Follow(sym) Union = Follow(rule)
                                if (std::find(firstSig.begin(), firstSig.end(), "ε") != firstSig.end()) follow(followSym, rule.first);
                            }
                            else {
                                followSym.insert(production[i + 1]);
                            }
                        }
                        else {
                            // Follow(sym) Union = Follow(rule)
                            follow(followSym, rule.first);
                        }
                        // Seguir revisando mas ocurrencias de sym en la misma regla
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

        // Como Follow sirve para asignar epsilons, hay que omitir aquellos simbolo que no produzcan epsilon
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

// Generado por: ChatGPT
Grammar Grammar::createToRightRecursion() {
    Grammar newGrammar;

    for (const auto& rule : this->rules) { // Para cada regla...
        std::string nonTerminal = rule.first; //Obtener el no terminal
        const Productions& productions = rule.second; //Obtener lo que produce
        Productions alpha, beta;

        for (const Production& production : productions) { // Para cada produccion
            if (production[0] == nonTerminal) { // Si el primer simbolo es recursivo
                // Insertar los siguientes simbolos
                // Autor: Anuragvbj79
                Production alphaProduction(production.begin() + 1, production.end());
                // Fin Autor
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
// Fin Generacion

std::vector<std::pair<std::string, std::vector<std::vector<std::string>>>>  & Grammar::getRules() {
    return rules;
}

// Generado por: ChatGPT
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
// Fin Generacion

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

// Algoritmo por: Neso Academy
std::pair<std::shared_ptr<SyntaxNode>,std::list<SyntaxToken>> Grammar::syntaxAnalysis(std::list<LexerToken> tokens) {
    createParserTable();

    std::stack<ParserState> memory;
    memory.emplace("EOF", nullptr); // Start with $
    std::shared_ptr<SyntaxNode> rootNode = std::make_shared<SyntaxNode>(rules.at(0).first);
    memory.emplace(rules.at(0).first, rootNode); // Add S

    std::vector<std::pair<std::string,LexerToken>> flowOfTokens;
    for (const auto& token : tokens) {
        flowOfTokens.push_back(std::make_pair(usedToken(token), token));
    }
    flowOfTokens.push_back(std::make_pair("EOF",  LexerToken("EOF",PUNCTUATION,-1)));

    int index = 0;

    bool inDeclaration = false;
    const std::string NUMBER = "Number";
    const std::string STRING = "String";
    std::string dataType = NUMBER;
    std::string idName = "0";
    SyntaxToken* idPlaceholder;
    std::unordered_map<std::string,std::string> idTypes;
    std::list<SyntaxToken> valuesTable;

    std::unordered_map<std::string,std::vector<int>> usageLines;

    while (index < flowOfTokens.size()) {
        if (index == flowOfTokens.size() - 1 && memory.top().symbol == "EOF") break;

        if (isNonTerminal(memory.top().symbol)) {
            ParserState currentState = memory.top();
            if (parserTable[std::make_pair(memory.top().symbol, flowOfTokens.at(index).first)].empty()) {
                std::cerr << "Error de sintaxis" << std::endl;
                return {nullptr, {}};
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
            if (memory.top().symbol != "identificador") {
                LexerToken aux = flowOfTokens.at(index).second;
                if (memory.top().symbol == "constante") {
                    memory.top().node->token = SyntaxToken(aux.name,aux.type,aux.line,NUMBER);
                }
                else memory.top().node->token = SyntaxToken(aux.name,aux.type,aux.line,"-");
            }
            if (memory.top().node->token.name == "'") {
                LexerToken aux = flowOfTokens.at(index).second;
                memory.top().node->token = SyntaxToken(aux.name,aux.type,aux.line,STRING);
            }

            // En declaracion
            if (inDeclaration){
                if (memory.top().symbol == "identificador") {
                    // Es la variable a declarar
                    if (idName == "0") {
                        idName = flowOfTokens.at(index).second.name;
                        if (idTypes.find(idName) != idTypes.end()) {
                            std::cerr << "La variable '" << idName << "' ya fue declarada previamente" << std::endl;
                            return {nullptr, {}};
                        }
                        memory.top().node->token = SyntaxToken("NULL","NULL",-1,"NULL");
                        idPlaceholder = &memory.top().node->token;
                    }
                    // Usar el tipo de la variable si no es string
                    else {
                        if (idTypes.find(flowOfTokens.at(index).second.name) != idTypes.end()) {
                            if (dataType != STRING) dataType = idTypes[flowOfTokens.at(index).second.name];
                            LexerToken aux = flowOfTokens.at(index).second;
                            usageLines[aux.name].push_back(aux.line);
                            memory.top().node->token = SyntaxToken(aux.name,aux.type,aux.line,idTypes[flowOfTokens.at(index).second.name]);
                        } else {
                            std::cerr<<"Uso de una variable no declarada: "<<flowOfTokens.at(index).second.name<<std::endl;
                            return {nullptr, {}};
                        }
                    }
                }
                // Guardar Token con el Follow de DECLARACION \n
                else if (flowOfTokens.at(index).first == "\n") {
                    if (idTypes.find(idName) == idTypes.end()) {
                        idTypes[idName] = dataType;
                        std::cout << idName << " es un "<< dataType << std::endl;
                        LexerToken lexerToken = LexerToken("NULL","NULL",-1);
                        getFirstLexerToken(tokens, idName, lexerToken);
                        if (lexerToken.line != -1) {
                            valuesTable.emplace_back(lexerToken.name,lexerToken.type,lexerToken.line,dataType);
                            if(nullptr != idPlaceholder) {
                                idPlaceholder->name = lexerToken.name;
                                idPlaceholder->tokenType = lexerToken.type;
                                idPlaceholder->line = lexerToken.line;
                                idPlaceholder->dataType = dataType;
                            }
                        }
                        idPlaceholder = nullptr;
                        dataType = NUMBER;
                        inDeclaration = false;
                        idName = "0";
                    }
                    else {
                        std::cerr << "La variable '" << idName << "' ya fue declarada previamente" << std::endl;
                        return {nullptr, {}};
                    }
                }
            }
            else if (memory.top().symbol == "identificador") {
                if (idTypes.find(flowOfTokens.at(index).second.name) == idTypes.end()) {
                    std::cerr<<"Uso de una variable no declarada: "<<flowOfTokens.at(index).second.name<<std::endl;
                    return {nullptr, {}};
                }
                LexerToken aux = flowOfTokens.at(index).second;
                usageLines[aux.name].push_back(aux.line);
                memory.top().node->token = SyntaxToken(aux.name,aux.type,aux.line,idTypes[flowOfTokens.at(index).second.name]);
            }

            memory.pop();
            index++;
        }
        else if (memory.top().symbol == "∈Σ-'" && flowOfTokens.at(index).first != "'") {
            LexerToken aux = flowOfTokens.at(index).second;
            memory.top().node->token = SyntaxToken(aux.name,aux.type,aux.line,STRING);
            memory.pop();
            index++;
            dataType = STRING;
        }
        else if (memory.top().symbol == "ε") {
            memory.top().node->productionName = "ε";
            memory.pop();
        }
    }

    if (idName != "0") {
        if (idTypes.find(idName) == idTypes.end()) {
            idTypes[idName] = dataType;
            std::cout << idName << " es un "<< dataType << std::endl;
            LexerToken lexerToken = LexerToken("NULL","NULL",-1);
            getFirstLexerToken(tokens, idName, lexerToken);
            if (lexerToken.line != -1) {
                valuesTable.emplace_back(lexerToken.name,lexerToken.type,lexerToken.line,dataType);
                if(nullptr != idPlaceholder) {
                    idPlaceholder->name = lexerToken.name;
                    idPlaceholder->tokenType = lexerToken.type;
                    idPlaceholder->line = lexerToken.line;
                    idPlaceholder->dataType = dataType;
                }
            }
        }
        else {
            std::cerr << "La variable '" << idName << "' ya fue declarada previamente" << std::endl;
            return {nullptr, {}};
        }
    }

    if (memory.top().symbol == "EOF" || memory.empty()) {
        for (SyntaxToken& value : valuesTable) {
            value.usageLines = usageLines[value.name];
        }
        return std::make_pair(rootNode, valuesTable);
    }
    std::cerr << "Error de sintaxis" << std::endl;
    return {nullptr, {}};
}

// Fin Algoritmo