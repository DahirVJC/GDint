#ifndef ASTNODES_H
#define ASTNODES_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "SemanticToken.h"

struct SemanticToken;

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

    virtual bool evaluate() {
        return true;
    }

    virtual std::string resolve() {
        return "-";
    }

    virtual std::string getDataType() const {
        return "Unknown";
    }
};

class IdentifierNode : public Node {
private:
    SemanticToken* symbolToken;

public:
    IdentifierNode(const std::string& id, SemanticToken* token)
        : Node(id),
          symbolToken(token) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << symbolToken->name << " (Type: " << symbolToken->dataType << ")" << std::endl;
    }
    std::string resolve() override {
        return symbolToken->value;
    }
    void setValue(const std::string &value) {
        symbolToken->value = value;
        int newSize = calculateSize(symbolToken->dataType,value);
        symbolToken->size = newSize>symbolToken->size ? newSize : symbolToken->size;
    }
    std::string getDataType() const override {
        return symbolToken->dataType;
    }
};

class NumberNode : public Node {
private:
    std::string value;
    std::string dataType;

public:
    NumberNode(const std::string& val, const std::string& type)
        : Node(val), value(val), dataType(type) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << value << " (Type: " << dataType << ")" << std::endl;
    }
    std::string resolve() override {
        return value;
    }
    std::string getDataType() const override {
        return dataType;
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
        std::cout << indent << value << " (Type: " << dataType << ")" << std::endl;
    }
    std::string resolve() override {
        return value;
    }
    std::string getDataType() const override {
        return dataType;
    }
};

class BinaryOperationNode : public Node {
private:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::string operation;
    std::string dataType;

public:
    BinaryOperationNode(Node* left_node, Node* right_node, const std::string& op)
        : Node(op), left(left_node), right(right_node), operation(op), dataType("Unknown") {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << operation << std::endl;
        if (left) {
            std::cout << indent << "  Left:" << std::endl;
            left->print(depth + 2);
        }
        if (right) {
            std::cout << indent << "  Right:" << std::endl;
            right->print(depth + 2);
        }
    }
    std::string getDataType() const override {
        return dataType;
    }

    bool evaluate() override {
        if (!left || !right) {
            return false;
        }
        bool leftValid = left->evaluate();
        bool rightValid = right->evaluate();

        const std::string& leftType = left->getDataType();
        const std::string& rightType = right->getDataType();

        if (leftType != rightType) {
            std::cerr << "Error semantico: tipos de datos incompatibles" << std::endl;
            return false;
        }

        dataType = leftType;

        if (dataType == "String") {
            if (operation != "+") {
                std::cerr << "Error semantico: no se permite la operacion " << operation << " en " << dataType << std::endl;
                return false;
            }
        }

        return leftValid && rightValid;
    }

    std::string resolve() override {
        std::string varValue = left ? left->resolve() : "0";
        std::string expValue = right ? right->resolve() : "0";
        if (left->getDataType() == "Number") {
            int leftValue = std::stoi(varValue);
            int rightValue = std::stoi(expValue);
            if (operation == "+") {
                return std::to_string(leftValue + rightValue);
            }
            if (operation == "-") {
                return std::to_string(leftValue - rightValue);
            }
            if (operation == "*") {
                return std::to_string(leftValue * rightValue);
            }
            if (operation == "/") {
                if (rightValue == 0) {
                    throw std::runtime_error("No se puede dividir entre 0");// Es un error de runtime porque el 0 puede salir de EXP como 2 - 2
                }
                return std::to_string(leftValue / rightValue);
            }
        }
        else {
            return varValue + expValue;
        }
        return "";
    }
};

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

    bool evaluate() override {
        if (!variable || !expression) {
            return false;
        }
        return variable->evaluate() && expression->evaluate();
    }

    std::string resolve() override {
        std::string varValue = expression->resolve();
        variable->setValue(varValue);
        return varValue;
    }

};

class AssignmentNode : public Node {
private:
    std::unique_ptr<IdentifierNode> variable;
    std::unique_ptr<Node> expression;

public:
    AssignmentNode(IdentifierNode* var, Node* expr)
        : Node("Assignment"), variable(var), expression(expr) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "Assignment:" << std::endl;
        if (variable) {
            std::cout << indent << "  Variable:" << std::endl;
            variable->print(depth + 2);
        }
        if (expression) {
            std::cout << indent << "  Value:" << std::endl;
            expression->print(depth + 2);
        }
    }

    bool evaluate() override {
        if (!variable || !expression) {
            return false;
        }
        return variable->evaluate() && expression->evaluate();
    }

    std::string resolve() override {
        std::string varValue = expression->resolve();
        variable->setValue(varValue);
        return varValue;
    }

};

class ProgramNode : public Node {
private:
    std::vector<std::unique_ptr<Node>> instructions;

public:
    ProgramNode() : Node("Program") {}

    void addInstruction(Node* inst) {
        if (inst) {
            instructions.push_back(std::unique_ptr<Node>(inst));
        }
    }

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << "Program:" << std::endl;
        for (const auto& inst : instructions) {
            if (inst) {
                inst->print(depth + 1);
            }
        }
    }

    bool evaluate() override {
        for (const auto& inst : instructions) {
            if (!inst || !inst->evaluate()) {
                return false;
            }
        }
        return true;
    }

    std::string resolve() override {
        for (const auto& inst : instructions) {
            inst->resolve();
        }
        return "";
    }
};

#endif //ASTNODES_H
