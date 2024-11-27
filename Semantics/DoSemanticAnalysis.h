
#ifndef DOSEMANTICANALYSIS_H
#define DOSEMANTICANALYSIS_H
#include <memory>

#include "ASTNodes.h"
#include "ParseTreeConverter.h"
#include "../Parser/SyntaxNode.h"

std::pair<std::shared_ptr<std::list<SemanticToken>>, std::unique_ptr<Node>> doSemanticAnalysis(std::shared_ptr<SyntaxNode> root, std::list<SyntaxToken> symbols) {
    ParseTreeConverter converter(symbols);
    try {
        bool logIsOn = logOn();

        std::unique_ptr<Node> astTree = converter.convertTree(root);
        if (logIsOn) std::cout << "Arbol creado" << std::endl;

        if (logIsOn) astTree->print();
        bool isValid = astTree->evaluate();
        if(isValid) {
            if (logIsOn) std::cout << "Semantica valida" << std::endl;
            astTree->resolve();
            if (logIsOn) astTree->print();
            std::shared_ptr<std::list<SemanticToken>> symbolsTable = converter.getSymbolsTable();
            assignAddresses(*symbolsTable);
            if (logIsOn) printSemanticTokens(*symbolsTable);
            return {symbolsTable, std::move(astTree)};
        }
        std::cerr << "El arbol no es valido" << std::endl;
    // Asistido por: ChatGPT
    } catch (const std::exception& e) {
        std::cerr << "Error de runtime en la fase semantica: " << e.what() << std::endl;
    }
    // Fin Asistencia
    return {nullptr, nullptr};
}

#endif //DOSEMANTICANALYSIS_H
