
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

        bool isValid = astTree->evaluate();
        if(isValid) {
            std::cout << "\nSemantica " << "valida" << std::endl;
            astTree->resolve();
            astTree->print();
            std::shared_ptr<std::list<SemanticToken>> symbolsTable = converter.getSymbolsTable();
            assignAddresses(*symbolsTable);
            printSemanticTokens(*symbolsTable);
            return {symbolsTable, std::move(astTree)};
        }
    } catch (const std::exception& e) {
        std::cerr << "Error al convertir el arbol Parse a AST: " << e.what() << std::endl;
    }
    return {nullptr, nullptr};
}

#endif //DOSEMANTICANALYSIS_H