
#ifndef SEMANTICTOKEN_H
#define SEMANTICTOKEN_H
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <iomanip>

struct SemanticToken {
    std::string name;
    std::string tokenType;
    std::string value;// Por defecto es "0"
    int declarationLine;
    std::vector<int> usageLines;
    std::string dataType;
    int size;// Atributo calculado con dataType y value. Por defecto es 1
    int dimension;// Siempre es 1
    std::string scope;// Siempre es global
    std::string address;// Por defecto es ""
    SemanticToken(std::string n, std::string t, const int decline, std::vector<int>uselines, std::string d, std::string val = "0")
        : name(std::move(n)),
        tokenType(std::move(t)),
        value(std::move(val)),
        declarationLine(decline),
        usageLines(std::move(uselines)),
        dataType(std::move(d)),
        size(1),
        dimension(1),
        scope("Global")
    {}
};

// Generado por: ChatGPT
int calculateSize(const std::string & dataType, const std::string & value) {
    if (dataType == "Number") return sizeof(int);
    return static_cast<int>(value.length() + 1);
}
// Fin Generacion

// Generado por: ChatGPT
void assignAddresses(std::list<SemanticToken>& tokens) {
    unsigned int currentAddress = 0x1000;
    for (auto& token : tokens) {
        std::stringstream ss;
        ss << "0x" << std::hex << std::uppercase << currentAddress;
        token.address = ss.str();
        currentAddress += token.size;
    }
}
// Fin Generacion

// Asistido por: ChatGPT
inline void printSemanticToken(const SemanticToken &token) {
    std::cout << "Token(name: " << token.name
              << ", token type: " << token.tokenType
              << ", final value: " << token.value
              << ", declaration line: " << token.declarationLine
              << ", usage lines: [";
    for (size_t i = 0; i < token.usageLines.size(); ++i) {
        std::cout << token.usageLines[i];
        if (i < token.usageLines.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "], data type: " << token.dataType
              << ", size: " << token.size << " bytes"
              << ", dimension: " << token.dimension
              << ", scope: " << token.scope
              << ", address: " << token.address
              << ")" << std::endl;
}
// Fin Asistencia

inline void printSemanticTokens(const std::list<SemanticToken> &tokens) {
    for (const SemanticToken& token : tokens) {
        printSemanticToken(token);
    }
}
#endif //SEMANTICTOKEN_H
