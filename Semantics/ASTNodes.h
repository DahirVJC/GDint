#ifndef ASTNODES_H
#define ASTNODES_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "SemanticToken.h"

// Autor: (Ling, 2024) [Inspiracion de los nodos AST]
// Asistido por: ChatGPT [Inspiracion de tener las funciones de validacion y reglas gramaticas en los nodos]
// Generado por: Claude
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
// Fin Generacion
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

class ConstantNode : public Node {
private:
    std::string value;
    std::string dataType;

public:
    ConstantNode(const std::string& val, const std::string& type)
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
// Generado por: Claude
class BinaryOperationNode : public Node {
private:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::string operation;
    std::string dataType;
    int line;

public:
    BinaryOperationNode(Node* left_node, Node* right_node, const std::string& op, int l)
        : Node(op), left(left_node), right(right_node), operation(op), dataType("Unknown"), line(l) {}

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
// Fin Generacion
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
            std::cerr << "Error semantico: tipos de datos incompatibles entre si en " << name << ". Linea: " << line << std::endl;
            exit(0);
        }

        if (leftType == "String") {
            if (operation != "+" && operation != "==") {
                std::cerr << "Error semantico: no se permite la operacion " << operation << " en " << leftType << ". Linea: " << line << std::endl;
                exit(0);
            }
        }
        else if (leftType == "Number") {
            if (operation != "+" && operation != "-" && operation != "*" && operation != "/" && operation != "==" && operation != "<" && operation != ">") {
                std::cerr << "Error semantico: no se permite la operacion " << operation << " en " << leftType << ". Linea: " << line << std::endl;
                exit(0);
            }
        }
        else if (leftType == "Bool") {
            if (operation != "&&" && operation != "||") {
                std::cerr << "Error semantico: no se permite la operacion " << operation << " en " << leftType << ". Linea: " << line << std::endl;
                exit(0);
            }
        }

        if (operation == "&&" || operation == "||" || operation == "==" || operation == ">" || operation == "<") {
            dataType = "Bool";
        }
        else {
            dataType = leftType;
        }

        return leftValid && rightValid;
    }

    std::string resolve() override {
        std::string leftStrValue = left ? left->resolve() : "0";
        std::string rightStrValue = right ? right->resolve() : "0";
        if (left->getDataType() == "Number") {
            std::unique_ptr<Node> newLeft= std::make_unique<ConstantNode>(
                left->resolve(),
                left->getDataType()
            );
            left = std::move(newLeft);
            std::unique_ptr<Node> newRight= std::make_unique<ConstantNode>(
                right->resolve(),
                right->getDataType()
            );
            right = std::move(newRight);
// Asistido por: ChatGPT
            int leftValue = std::stoi(leftStrValue);
            int rightValue = std::stoi(rightStrValue);
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
                    std::string errorMessage = "No se puede dividir entre 0. Linea: " + std::to_string(line);
                    throw std::runtime_error(errorMessage);// Es un error de runtime porque el 0 puede salir de EXP como 2 - 2
                }
                return std::to_string(leftValue / rightValue);
            }
            if (operation == "==") {
                return leftValue == rightValue ? "true" : "false";
            }
            if (operation == ">") {
                return leftValue > rightValue ? "true" : "false";
            }
            if (operation == "<") {
                return leftValue < rightValue ? "true" : "false";
            }
        }
// Fin Asistencia
        else if (left->getDataType() == "String") {
            std::unique_ptr<Node> newLeft= std::make_unique<ConstantNode>(
                left->resolve(),
                left->getDataType()
            );
            left = std::move(newLeft);
            std::unique_ptr<Node> newRight= std::make_unique<ConstantNode>(
                right->resolve(),
                right->getDataType()
            );
            right = std::move(newRight);
            return leftStrValue + rightStrValue;
        }
        else if (left->getDataType() == "Bool") {
            std::unique_ptr<Node> newLeft= std::make_unique<ConstantNode>(
                left->resolve(),
                left->getDataType()
            );
            left = std::move(newLeft);
            std::unique_ptr<Node> newRight= std::make_unique<ConstantNode>(
                right->resolve(),
                right->getDataType()
            );
            right = std::move(newRight);
            if (operation == "&&") {
                return (leftStrValue == "true" && rightStrValue == "true") ? "true" : "false";
            }
            if (operation == "||") {
                return (leftStrValue == "true" || rightStrValue == "true") ? "true" : "false";
            }
        }
        return "";
    }
};
// Generado por: Claude
class DeclarationNode : public Node {
private:
    std::unique_ptr<IdentifierNode> variable;
    std::unique_ptr<Node> expression;
    int line;

public:
    DeclarationNode(IdentifierNode* var, Node* expr, int l)
        : Node("Declaration"), variable(var), expression(expr), line(l) {}

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
// Fin Generacion
    bool evaluate() override {
        if (!variable) {
            std::cerr << "Error en fase semantica: no existe la variable o es invalida. Linea: " << line << std::endl;
            exit(0);
        }
        if (!expression) {
            std::cerr << "Error en fase semantica: no existe la expresion o es invalida. Linea: " << line << std::endl;
            exit(0);
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
    int line;

public:
    AssignmentNode(IdentifierNode* var, Node* expr, int l)
        : Node("Assignment"), variable(var), expression(expr), line(l) {}

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
        if (!variable) {
            std::cerr << "Error en fase semantica: no existe la variable o es invalida. Linea: " << line << std::endl;
            exit(0);
        }
        if (!expression) {
            std::cerr << "Error en fase semantica: no existe la expresion o es invalida. Linea: " << line << std::endl;
            exit(0);
        }

        bool varValid = variable->evaluate();
        bool varExp = expression->evaluate();

        if(variable->getDataType() != expression->getDataType()) {
            std::cerr << "Error semantico: se puede asignar " << expression->getDataType() << " a " << variable->getDataType() << ". Linea: " << line << std::endl;
            exit(0);
        }
        return varValid && varExp;
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
    int line;

public:
    GetHttpNode(Node* end, Node* key, int l)
        : Node("GetHttp"), endpoint(end), apiKey(key), line(l) {}

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
            std::cerr << "Error en fase semantica: no existe el endpoint o es invalido. Linea: " << line << std::endl;
            exit(0);
        }
        if(endpoint->getDataType() != "String") {
            std::cerr << "Error semantico: el url debe ser String en " << name << ". Linea: " << line << std::endl;
            exit(0);
        }
        if (apiKey) {
            if(apiKey->getDataType() != "String") {
                std::cerr << "Error semantico: la clave de API debe ser String en " << name << ". Linea: " << line << std::endl;
                exit(0);
            }
            return endpoint->evaluate() && apiKey->evaluate();
        }
        return endpoint->evaluate();
    }
    std::string resolve() override {
        std::unique_ptr<Node> newEndpoint= std::make_unique<ConstantNode>(
                endpoint->resolve(),
                endpoint->getDataType()
                );
        endpoint = std::move(newEndpoint);
        if (apiKey) {
            std::unique_ptr<Node> newApiKey= std::make_unique<ConstantNode>(
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
    int line;

public:
    PostHttpNode(Node* end, Node* content, Node* key, int l)
        : Node("PostHttp"), endpoint(end), body(content), apiKey(key), line(l) {}

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
            std::cerr << "Error en fase semantica: no existe el endpoint o es invalido. Linea: " << line << std::endl;
            exit(0);
        }
        if(endpoint->getDataType() != "String") {
            std::cerr << "Error semantico: el url debe ser String en " << name << ". Linea: " << line << std::endl;
            exit(0);
        }
        if(body->getDataType() != "String") {
            std::cerr << "Error semantico: el cuerpo debe ser String en " << name << ". Linea: " << line << std::endl;
            exit(0);
        }
        if (apiKey) {
            if(apiKey->getDataType() != "String") {
                std::cerr << "Error semantico: la clave de API debe ser String en " << name << ". Linea: " << line << std::endl;
                exit(0);
            }
            return endpoint->evaluate() && body->evaluate() && apiKey->evaluate();
        }
        return endpoint->evaluate() && body->evaluate();
    }

    std::string resolve() override {
        std::unique_ptr<Node> newEndpoint= std::make_unique<ConstantNode>(
                endpoint->resolve(),
                endpoint->getDataType()
                );
        endpoint = std::move(newEndpoint);
        std::unique_ptr<Node> newBody= std::make_unique<ConstantNode>(
                body->resolve(),
                body->getDataType()
                );
        body = std::move(newBody);
        if (apiKey) {
            std::unique_ptr<Node> newApiKey= std::make_unique<ConstantNode>(
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
    int line;

public:
    PutHttpNode(Node* end, Node* idRes, Node* content, Node* key, int l)
        : Node("PutHttp"), endpoint(end), id(idRes), body(content), apiKey(key), line(l) {}

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
            std::cerr << "Error en fase semantica: no existe el endpoint o es invalido. Linea: " << line << std::endl;
            exit(0);
        }
        if(endpoint->getDataType() != "String") {
            std::cerr << "Error semantico: el url debe ser String en " << name << ". Linea: " << line << std::endl;
            exit(0);
        }
        if(body->getDataType() != "String") {
            std::cerr << "Error semantico: el cuerpo debe ser String en " << name << ". Linea: " << line << std::endl;
            exit(0);
        }
        if (apiKey) {
            if(apiKey->getDataType() != "String") {
                std::cerr << "Error semantico: la clave de API debe ser String en " << name << ". Linea: " << line << std::endl;
                exit(0);
            }
            return endpoint->evaluate() && id->evaluate() && body->evaluate() && apiKey->evaluate();
        }
        return endpoint->evaluate() && id->evaluate() && body->evaluate();
    }

    std::string resolve() override {
        std::unique_ptr<Node> newEndpoint= std::make_unique<ConstantNode>(
                endpoint->resolve(),
                endpoint->getDataType()
                );
        endpoint = std::move(newEndpoint);
        std::unique_ptr<Node> newId= std::make_unique<ConstantNode>(
                id->resolve(),
                id->getDataType()
                );
        id = std::move(newId);
        std::unique_ptr<Node> newBody= std::make_unique<ConstantNode>(
                body->resolve(),
                body->getDataType()
                );
        body = std::move(newBody);
        if (apiKey) {
            std::unique_ptr<Node> newApiKey= std::make_unique<ConstantNode>(
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
    int line;

public:
    DeleteHttpNode(Node* end, Node* idRes, Node* key, int l)
        : Node("DeleteHttp"), endpoint(end), id(idRes), apiKey(key), line(l) {}

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
            std::cerr << "Error en fase semantica: no existe el endpoint o es invalido. Linea: " << line << std::endl;
            exit(0);
        }
        if(endpoint->getDataType() != "String") {
            std::cerr << "Error semantico: el url debe ser String en " << name  << ". Linea: " << line<< std::endl;
            exit(0);
        }
        if (apiKey) {
            if(apiKey->getDataType() != "String") {
                std::cerr << "Error semantico: la clave de API debe ser String en " << name << ". Linea: " << line << std::endl;
                exit(0);
            }
            return endpoint->evaluate() && apiKey->evaluate();
        }
        return endpoint->evaluate();
    }

    std::string resolve() override {
        std::unique_ptr<Node> newEndpoint= std::make_unique<ConstantNode>(
                endpoint->resolve(),
                endpoint->getDataType()
                );
        endpoint = std::move(newEndpoint);
        std::unique_ptr<Node> newId= std::make_unique<ConstantNode>(
                id->resolve(),
                id->getDataType()
                );
        id = std::move(newId);
        if (apiKey) {
            std::unique_ptr<Node> newApiKey= std::make_unique<ConstantNode>(
                    apiKey->resolve(),
                    apiKey->getDataType()
                    );
            apiKey = std::move(newApiKey);
        }
        return "";
    }
};
// Generado por: Claude
class ProgramNode : public Node {
private:
    std::vector<std::unique_ptr<Node>> instructions;
    int line;

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
                std::cerr<<"No existen la instruccion o es invalida.";
                exit(0);
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
// Fin Generacion


class ConditionalNode : public Node {
private:
    std::unique_ptr<BinaryOperationNode> comparison;
    std::unique_ptr<ProgramNode> thenBlock;
    std::unique_ptr<ProgramNode> elseBlock;

public:
    ConditionalNode(BinaryOperationNode* com, ProgramNode* thenB, ProgramNode* elseB)
        : Node("Condicional"), comparison(com), thenBlock(thenB), elseBlock(elseB) {}

    void print(int depth = 0) const override {
        std::string indent(depth * 2, ' ');
        std::cout << indent << name << ":" << std::endl;
        if (comparison) {
            std::cout << indent << "  Comparison:" << std::endl;
            comparison->print(depth + 2);
        }
        if (thenBlock) {
            std::cout << indent << "  Then Block:" << std::endl;
            thenBlock->print(depth + 2);
        }
        if (elseBlock) {
            std::cout << indent << "  Else Block:" << std::endl;
            elseBlock->print(depth + 2);
        }
    }

    bool evaluate() override {
        if (!comparison || !thenBlock) {
            return false;
        }
        if (elseBlock) {
            return comparison->evaluate() && thenBlock->evaluate() && elseBlock->evaluate();
        }
        return comparison->evaluate() && thenBlock->evaluate();
    }

    std::string resolve() override {
        std::string result = comparison->resolve();
        if (result == "true") {
            thenBlock->resolve();
            elseBlock = nullptr;
        }
        else {
            if (elseBlock) {
                elseBlock->resolve();
            }
            thenBlock = nullptr;
        }
        return result;
    }
};
// Fin Asistencia [Inspiracion de tener las funciones de validacion y reglas gramaticas en los nodos]
// Fin Autor [Inspiracion de los nodos AST]

#endif //ASTNODES_H
