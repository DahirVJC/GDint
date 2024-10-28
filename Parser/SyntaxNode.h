#ifndef SYNTAXNODE_H
#define SYNTAXNODE_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct SyntaxNode {
    std::string value;
    std::vector<std::shared_ptr<SyntaxNode>> children;
    explicit SyntaxNode(std::string val) : value(std::move(val)) {}
};

struct ParserState {
    std::string symbol;
    std::shared_ptr<SyntaxNode> node;
    ParserState(std::string sym, std::shared_ptr<SyntaxNode> n)
        : symbol(std::move(sym)), node(std::move(n)) {}
};


inline void printSyntaxTree(const std::shared_ptr<SyntaxNode>& node, int depth = 0) {
    if (node){
        std::cout << std::string(depth * 2, ' ') << node->value << std::endl;
        for (const auto& child : node->children) {
            printSyntaxTree(child, depth + 1);
        }
    }
}

#endif //SYNTAXNODE_H
