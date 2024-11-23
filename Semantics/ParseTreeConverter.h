

#ifndef PARSETREECONVERTER_H
#define PARSETREECONVERTER_H

#include "ASTNodes.h"
#include "../Parser/SyntaxNode.h"
class ParseTreeConverter {
public:
    std::unique_ptr<Node> convertTree(const std::shared_ptr<SyntaxNode>& root) {
        if (!root || root->productionName != "CODIGO") {
            throw std::runtime_error("Expected CODIGO at root");
        }

        auto program = std::make_unique<ProgramNode>();

        // Handle initial BLOQUE and recursive CODIGO'
        if (!root->children.empty()) {
            convertCodigo(root, program.get());
        }

        return program;
    }

private:
    void convertCodigo(const std::shared_ptr<SyntaxNode>& codigoNode, ProgramNode* program) {
        if (!codigoNode || !program) return;

        // Process first BLOQUE
        if (!codigoNode->children.empty()) {
            convertBloque(codigoNode->children[0], program);
        }

        // Process CODIGO' recursively
        if (codigoNode->children.size() > 1) {
            auto codigoPrime = codigoNode->children[1];
            while (codigoPrime && codigoPrime->productionName == "CODIGO'" &&
                   !codigoPrime->children.empty()) {
                convertBloque(codigoPrime->children[0], program);
                if (codigoPrime->children.size() > 1) {
                    codigoPrime = codigoPrime->children[1];
                } else {
                    break;
                }
            }
        }
    }

    void convertBloque(const std::shared_ptr<SyntaxNode>& bloqueNode, ProgramNode* program) {
        if (!bloqueNode || !program) return;

        // Process initial ACCION
        if (!bloqueNode->children.empty()) {
            auto accionNode = bloqueNode->children[0];
            if (accionNode && accionNode->productionName == "ACCION") {
                auto instrNode = convertInstruccion(accionNode->children[0]);
                if (instrNode) {
                    program->addDeclaration(instrNode.release());
                }
            }
        }

        // Process BLOQUE' recursively
        if (bloqueNode->children.size() > 1) {
            auto bloquePrime = bloqueNode->children[1];
            while (bloquePrime && bloquePrime->productionName == "BLOQUE'" &&
                   !bloquePrime->children.empty()) {
                // Skip newline token and process ACCION
                if (bloquePrime->children.size() >= 2) {
                    auto accionNode = bloquePrime->children[1];
                    if (accionNode && accionNode->productionName == "ACCION") {
                        auto instrNode = convertInstruccion(accionNode->children[0]);
                        if (instrNode) {
                            program->addDeclaration(instrNode.release());
                        }
                    }
                }

                // Move to next BLOQUE' if it exists
                if (bloquePrime->children.size() > 2) {
                    bloquePrime = bloquePrime->children[2];
                } else {
                    break;
                }
            }
        }
    }

    std::unique_ptr<Node> convertExpression(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.empty()) return nullptr;

        // Process TERM
        auto result = convertTerm(node->children[0]);

        // Process EXP' recursively
        if (node->children.size() > 1) {
            auto expPrime = node->children[1];
            while (expPrime && expPrime->productionName == "EXP'" &&
                   expPrime->children.size() >= 4) {
                // Skip ESPACIO nodes
                auto opNode = expPrime->children[1];  // OPSIMP node
                auto termNode = expPrime->children[3]; // TERM node

                auto rightTerm = convertTerm(termNode);
                if (result && rightTerm) {
                    result = std::make_unique<BinaryOperationNode>(
                        result.release(),
                        rightTerm.release(),
                        opNode->children[0]->token.name  // + or -
                    );
                }

                // Move to next EXP'
                if (expPrime->children.size() > 4) {
                    expPrime = expPrime->children[4];
                } else {
                    break;
                }
            }
        }

        return result;
    }

    std::unique_ptr<Node> convertTerm(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.empty()) return nullptr;

        // Process initial FACTOR
        auto result = convertFactor(node->children[0]);

        // Process TERM' recursively
        if (node->children.size() > 1) {
            auto termPrime = node->children[1];
            while (termPrime && termPrime->productionName == "TERM'" &&
                   termPrime->children.size() >= 2) {
                // Get operator (* or /)
                auto op = termPrime->children[0]->token.name;
                auto rightFactor = convertFactor(termPrime->children[1]);

                if (result && rightFactor) {
                    result = std::make_unique<BinaryOperationNode>(
                        result.release(),
                        rightFactor.release(),
                        op
                    );
                }

                // Move to next TERM'
                if (termPrime->children.size() > 2) {
                    termPrime = termPrime->children[2];
                } else {
                    break;
                }
            }
        }

        return result;
    }

    std::string toCadena(const std::shared_ptr<SyntaxNode> & node) {
        if (!node || node->children.empty() || node->children.size() <= 1) return "";
        auto cadenaPrime = toCadena(node->children[1]);
        return node->children[0]->token.name+cadenaPrime;
    }

    std::unique_ptr<Node> convertString(const std::shared_ptr<SyntaxNode>& node) {
        std::string value = toCadena(node->children[1]);
        return std::make_unique<StringNode>(
                value,
                "String"
            );
    }

    std::unique_ptr<Node> convertFactor(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.empty()) return nullptr;

        auto firstChild = node->children[0];

        // Handle parenthesized expression
        if (firstChild->token.name == "(") {
            if (node->children.size() >= 3) {
                return convertExpression(node->children[1]);
            }
            return nullptr;
        }

        // Handle identifier
        if (firstChild->token.tokenType == "Identifier") {
            return std::make_unique<IdentifierNode>(
                firstChild->token.name,
                firstChild->token.dataType
            );
        }

        if (firstChild->token.tokenType == "Constant") {
            return std::make_unique<IdentifierNode>(
                firstChild->token.name,
                firstChild->token.dataType
            );
        }

        if (firstChild->productionName == "STRING") {
            return convertString(firstChild);
        }

        return nullptr;
    }

    std::unique_ptr<Node> convertInstruccion(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.empty()) return nullptr;
        return convertDeclaracion(node->children[0]);
    }

    std::unique_ptr<Node> convertDeclaracion(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.size() < 7) return nullptr;

        // Get identifier (skip ESPACIO nodes)
        auto identifierNode = node->children[2];
        if (!identifierNode) return nullptr;

        auto identifier = std::make_unique<IdentifierNode>(
            identifierNode->token.name,
            identifierNode->token.dataType
        );

        // Get expression (skip ESPACIO nodes)
        auto expNode = node->children[6];
        auto expression = expNode ? convertExpression(expNode) : nullptr;

        return std::make_unique<DeclarationNode>(
            identifier.release(),
            expression.release()
        );
    }
};

#endif //PARSETREECONVERTER_H
