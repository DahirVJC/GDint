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
            std::cerr << "Error semantico: tipos de datos incompatibles entre si en " << name << std::endl;
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
            std::unique_ptr<Node> newLeft= std::make_unique<NumberNode>(
                left->resolve(),
                left->getDataType()
            );
            left = std::move(newLeft);
            std::unique_ptr<Node> newRight= std::make_unique<NumberNode>(
                right->resolve(),
                right->getDataType()
            );
            right = std::move(newRight);

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
            std::unique_ptr<Node> newLeft= std::make_unique<StringNode>(
                left->resolve(),
                left->getDataType()
            );
            left = std::move(newLeft);
            std::unique_ptr<Node> newRight= std::make_unique<StringNode>(
                right->resolve(),
                right->getDataType()
            );
            right = std::move(newRight);
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

class GetHttpNode : public Node {
private:
    std::unique_ptr<Node> endpoint;
    std::unique_ptr<Node> apiKey;

public:
    GetHttpNode(Node* end, Node* key)
        : Node("GetHttp"), endpoint(end), apiKey(key) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << name << ":" << std::endl;
        if (endpoint) {
            std::cout << indent << "  Endpoint:";
            std::cout << std::endl;
            endpoint->print(depth + 2);
        }
        if (apiKey) {
            std::cout << indent << "  ApiKey:" << std::endl;
            apiKey->print(depth + 2);
        }
    }

    bool evaluate() override {
        if (!endpoint) {
            return false;
        }
        if(endpoint->getDataType() != "String") {
            std::cerr << "Error semantico: el url debe ser String " << name << std::endl;
            return false;
        }
        if (apiKey) {
            if(apiKey->getDataType() != "String") {
                std::cerr << "Error semantico: la clave de API debe ser String " << name << std::endl;
                return false;
            }
            return endpoint->evaluate() && apiKey->evaluate();
        }
        return endpoint->evaluate();
    }
    std::string resolve() override {
        std::unique_ptr<Node> newEndpoint= std::make_unique<StringNode>(
                endpoint->resolve(),
                endpoint->getDataType()
                );
        endpoint = std::move(newEndpoint);
        if (apiKey) {
            std::unique_ptr<Node> newApiKey= std::make_unique<StringNode>(
                    apiKey->resolve(),
                    apiKey->getDataType()
                    );
            apiKey = std::move(newApiKey);
        }
        return "";
    }
};

class PostHttpNode : public Node {
private:
    std::unique_ptr<Node> endpoint;
    std::unique_ptr<Node> body;
    std::unique_ptr<Node> apiKey;

public:
    PostHttpNode(Node* end, Node* content, Node* key)
        : Node("PostHttp"), endpoint(end), body(content), apiKey(key) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << name << ":" << std::endl;
        if (endpoint) {
            std::cout << indent << "  Endpoint:" << std::endl;
            endpoint->print(depth + 2);
        }
        if (body) {
            std::cout << indent << "  Body:" << std::endl;
            body->print(depth + 2);
        }
        if (apiKey) {
            std::cout << indent << "  ApiKey:" << std::endl;
            apiKey->print(depth + 2);
        }
    }

    bool evaluate() override {
        if (!endpoint) {
            return false;
        }
        if(endpoint->getDataType() != "String") {
            std::cerr << "Error semantico: el url debe ser String en " << name << std::endl;
            return false;
        }
        if(body->getDataType() != "String") {
            std::cerr << "Error semantico: el cuerpo debe ser String " << name << std::endl;
            return false;
        }
        if (apiKey) {
            if(apiKey->getDataType() != "String") {
                std::cerr << "Error semantico: la clave de API debe ser String " << name << std::endl;
                return false;
            }
            return endpoint->evaluate() && body->evaluate() && apiKey->evaluate();
        }
        return endpoint->evaluate() && body->evaluate();
    }

    std::string resolve() override {
        std::unique_ptr<Node> newEndpoint= std::make_unique<StringNode>(
                endpoint->resolve(),
                endpoint->getDataType()
                );
        endpoint = std::move(newEndpoint);
        std::unique_ptr<Node> newBody= std::make_unique<StringNode>(
                body->resolve(),
                body->getDataType()
                );
        body = std::move(newBody);
        if (apiKey) {
            std::unique_ptr<Node> newApiKey= std::make_unique<StringNode>(
                    apiKey->resolve(),
                    apiKey->getDataType()
                    );
            apiKey = std::move(newApiKey);
        }
        return "";
    }
};

class PutHttpNode : public Node {
private:
    std::unique_ptr<Node> endpoint;
    std::unique_ptr<Node> id;
    std::unique_ptr<Node> body;
    std::unique_ptr<Node> apiKey;

public:
    PutHttpNode(Node* end, Node* idRes, Node* content, Node* key)
        : Node("PutHttp"), endpoint(end), id(idRes), body(content), apiKey(key) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << name << ":" << std::endl;
        if (endpoint) {
            std::cout << indent << "  Endpoint:" << std::endl;
            endpoint->print(depth + 2);
        }
        if (id) {
            std::cout << indent << "  Id:" << std::endl;
            id->print(depth + 2);
        }
        if (body) {
            std::cout << indent << "  Body:" << std::endl;
            body->print(depth + 2);
        }
        if (apiKey) {
            std::cout << indent << "  ApiKey:" << std::endl;
            apiKey->print(depth + 2);
        }
    }

    bool evaluate() override {
        if (!endpoint) {
            return false;
        }
        if(endpoint->getDataType() != "String") {
            std::cerr << "Error semantico: el url debe ser String en " << name << std::endl;
            return false;
        }
        if(body->getDataType() != "String") {
            std::cerr << "Error semantico: el cuerpo debe ser String " << name << std::endl;
            return false;
        }
        if (apiKey) {
            if(apiKey->getDataType() != "String") {
                std::cerr << "Error semantico: la clave de API debe ser String " << name << std::endl;
                return false;
            }
            return endpoint->evaluate() && id->evaluate() && body->evaluate() && apiKey->evaluate();
        }
        return endpoint->evaluate() && id->evaluate() && body->evaluate();
    }

    std::string resolve() override {
        std::unique_ptr<Node> newEndpoint= std::make_unique<StringNode>(
                endpoint->resolve(),
                endpoint->getDataType()
                );
        endpoint = std::move(newEndpoint);
        std::unique_ptr<Node> newId= std::make_unique<StringNode>(
                id->resolve(),
                id->getDataType()
                );
        id = std::move(newId);
        std::unique_ptr<Node> newBody= std::make_unique<StringNode>(
                body->resolve(),
                body->getDataType()
                );
        body = std::move(newBody);
        if (apiKey) {
            std::unique_ptr<Node> newApiKey= std::make_unique<StringNode>(
                    apiKey->resolve(),
                    apiKey->getDataType()
                    );
            apiKey = std::move(newApiKey);
        }
        return "";
    }
};

class DeleteHttpNode : public Node {
private:
    std::unique_ptr<Node> endpoint;
    std::unique_ptr<Node> id;
    std::unique_ptr<Node> apiKey;

public:
    DeleteHttpNode(Node* end, Node* idRes, Node* key)
        : Node("DeleteHttp"), endpoint(end), id(idRes), apiKey(key) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << name << ":" << std::endl;
        if (endpoint) {
            std::cout << indent << "  Endpoint:" << std::endl;
            endpoint->print(depth + 2);
        }
        if (id) {
            std::cout << indent << "  Id:" << std::endl;
            id->print(depth + 2);
        }
        if (apiKey) {
            std::cout << indent << "  ApiKey:" << std::endl;
            apiKey->print(depth + 2);
        }
    }

    bool evaluate() override {
        if (!endpoint) {
            return false;
        }
        if(endpoint->getDataType() != "String") {
            std::cerr << "Error semantico: el url debe ser String en " << name << std::endl;
            return false;
        }
        if (apiKey) {
            if(apiKey->getDataType() != "String") {
                std::cerr << "Error semantico: la clave de API debe ser String " << name << std::endl;
                return false;
            }
            return endpoint->evaluate() && apiKey->evaluate();
        }
        return endpoint->evaluate();
    }

    std::string resolve() override {
        std::unique_ptr<Node> newEndpoint= std::make_unique<StringNode>(
                endpoint->resolve(),
                endpoint->getDataType()
                );
        endpoint = std::move(newEndpoint);
        std::unique_ptr<Node> newId= std::make_unique<StringNode>(
                id->resolve(),
                id->getDataType()
                );
        id = std::move(newId);
        if (apiKey) {
            std::unique_ptr<Node> newApiKey= std::make_unique<StringNode>(
                    apiKey->resolve(),
                    apiKey->getDataType()
                    );
            apiKey = std::move(newApiKey);
        }
        return "";
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
