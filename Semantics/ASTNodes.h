#ifndef ASTNODES_H
#define ASTNODES_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Node {
protected:
    std::string name;

public:
    Node() = default;
    explicit Node(const std::string& node_name) : name(node_name) {}
    virtual ~Node() = default;

    virtual void print(int depth = 0) const {
        std::string indent(depth * 2, ' ');
        std::cout << indent << name << std::endl;
    }

    // Base evaluate function - leaf nodes return true by default
    virtual bool evaluate() const {
        return true;
    }
};

// Identifier Node - Leaf node
class IdentifierNode : public Node {
private:
    std::string identifier;
    std::string dataType;

public:
    IdentifierNode(const std::string& id, const std::string& type)
        : Node(id), identifier(id), dataType(type) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "Identifier: " << identifier << " (Type: " << dataType << ")" << std::endl;
    }

    // Leaf node returns true
    bool evaluate() const override {
        return true;
    }
};

// Number Node - Leaf node
class NumberNode : public Node {
private:
    std::string value;
    std::string dataType;

public:
    NumberNode(const std::string& val, const std::string& type)
        : Node(val), value(val), dataType(type) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "Number: " << value << " (Type: " << dataType << ")" << std::endl;
    }

    // Leaf node returns true
    bool evaluate() const override {
        return true;
    }
};

class StringNode : public Node {
private:
    std::string value;
    std::string dataType;
public:
    StringNode(const std::string& id, const std::string& type)
        : Node(id), value(id), dataType(type) {}
    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "String: " << value << " (Type: " << dataType << ")" << std::endl;
    }

    // Leaf node returns true
    bool evaluate() const override {
        return true;
    }
};

// Binary Operation Node
class BinaryOperationNode : public Node {
private:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::string operation;

public:
    BinaryOperationNode(Node* left_node, Node* right_node, const std::string& op)
        : Node(op), left(left_node), right(right_node), operation(op) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "BinaryOp: " << operation << std::endl;
        if (left) {
            std::cout << indent << "  Left:" << std::endl;
            left->print(depth + 2);
        }
        if (right) {
            std::cout << indent << "  Right:" << std::endl;
            right->print(depth + 2);
        }
    }

    // Evaluates to true if both children evaluate to true
    bool evaluate() const override {
        bool leftEval = left ? left->evaluate() : false;
        bool rightEval = right ? right->evaluate() : false;
        return leftEval && rightEval;
    }
};

// Declaration Node
class DeclarationNode : public Node {
private:
    std::unique_ptr<IdentifierNode> variable;
    std::unique_ptr<Node> expression;

public:
    DeclarationNode(IdentifierNode* var, Node* expr)
        : Node("Declaration"), variable(var), expression(expr) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "Declaration:" << std::endl;
        if (variable) {
            std::cout << indent << "  Variable:" << std::endl;
            variable->print(depth + 2);
        }
        if (expression) {
            std::cout << indent << "  Value:" << std::endl;
            expression->print(depth + 2);
        }
    }

    // Evaluates to true if both variable and expression evaluate to true
    bool evaluate() const override {
        bool varEval = variable ? variable->evaluate() : false;
        bool exprEval = expression ? expression->evaluate() : false;
        return varEval && exprEval;
    }
};

// Program Node
class ProgramNode : public Node {
private:
    std::vector<std::unique_ptr<Node>> declarations;

public:
    ProgramNode() : Node("Program") {}

    void addDeclaration(Node* decl) {
        if (decl) {
            declarations.push_back(std::unique_ptr<Node>(decl));
        }
    }

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "Program:" << std::endl;
        for (const auto& decl : declarations) {
            if (decl) {
                decl->print(depth + 1);
            }
        }
    }

    // Evaluates to true if all declarations evaluate to true
    bool evaluate() const override {
        for (const auto& decl : declarations) {
            if (!decl || !decl->evaluate()) {
                return false;
            }
        }
        return true;
    }
};

#endif //ASTNODES_H
