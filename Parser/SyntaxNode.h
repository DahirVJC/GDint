#ifndef SYNTAXNODE_H
#define SYNTAXNODE_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "SyntaxToken.h"
#include "../Tools/util.h"

// Asistido por: Claude
struct SyntaxNode {
    std::string productionName;
    SyntaxToken token;
    std::vector<std::shared_ptr<SyntaxNode>> children;
    explicit SyntaxNode(SyntaxToken SynToken) : productionName(std::move("")), token(std::move(SynToken)) {}
    explicit SyntaxNode(std::string name) : productionName(std::move(name)), token(SyntaxToken("NULL", "NULL", -1, "NULL")) {}
};

struct ParserState {
    std::string symbol;
    std::shared_ptr<SyntaxNode> node;
    ParserState(std::string sym, std::shared_ptr<SyntaxNode> n)
        : symbol(std::move(sym)), node(std::move(n)) {}
};

inline void printSyntaxTree(const std::shared_ptr<SyntaxNode>& node, int depth = 0) {
    if (node){
        std::cout << std::string(depth * 2, ' ');
        if (node->token.line != -1) printToken(node->token);
        else std::cout<<symbolFormat(node->productionName)<<std::endl;
        for (const auto& child : node->children) {
            printSyntaxTree(child, depth + 1);
        }
    }
}
// Fin Asistencia

#endif //SYNTAXNODE_H
