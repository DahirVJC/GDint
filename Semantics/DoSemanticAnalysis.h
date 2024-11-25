
#ifndef DOSEMANTICANALYSIS_H
#define DOSEMANTICANALYSIS_H
#include <memory>

#include "ASTNodes.h"
#include "ParseTreeConverter.h"
#include "../Parser/SyntaxNode.h"

std::pair<std::shared_ptr<std::list<SemanticToken>>, std::unique_ptr<Node>> doSemanticAnalysis(std::shared_ptr<SyntaxNode> root, std::list<SyntaxToken> symbols) {
    ParseTreeConverter converter(symbols);
    try {
        std::unique_ptr<Node> astTree = converter.convertTree(root);
        std::cout << "Arbol creado" << std::endl;

        astTree->print();
        bool isValid = astTree->evaluate();
        if(isValid) {
            std::cout << "Semantica valida" << std::endl;
            astTree->resolve();
            astTree->print();
            std::shared_ptr<std::list<SemanticToken>> symbolsTable = converter.getSymbolsTable();
            assignAddresses(*symbolsTable);
            printSemanticTokens(*symbolsTable);
            return {symbolsTable, std::move(astTree)};
        }
        std::cout << "El arbol no es valido" << std::endl;
    // Asistido por: ChatGPT
    } catch (const std::exception& e) {
        std::cerr << "Error al convertir el arbol Parse a AST: " << e.what() << std::endl;
    }
    // Fin Asistencia
    return {nullptr, nullptr};
}

#endif //DOSEMANTICANALYSIS_H
