
#ifndef DOSEMANTICANALYSIS_H
#define DOSEMANTICANALYSIS_H
#include <memory>

#include "ASTNodes.h"
#include "ParseTreeConverter.h"
#include "../Parser/SyntaxNode.h"

void doSemanticAnalysis(std::shared_ptr<SyntaxNode> root) {
    ParseTreeConverter converter;
    try {
        std::unique_ptr<Node> ast = converter.convertTree(root);

        // Test the evaluation
        bool isValid = ast->evaluate();
        std::cout << "\nAST evaluation result: " << (isValid ? "Valid" : "Invalid") << std::endl;
        //ast->resolve();
        std::cout << "Parse tree converted to AST successfully:\n";
        ast->print();

    } catch (const std::exception& e) {
        std::cout << "Error converting parse tree: " << e.what() << std::endl;
    }
}

#endif //DOSEMANTICANALYSIS_H
