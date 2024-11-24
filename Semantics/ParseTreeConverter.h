

#ifndef PARSETREECONVERTER_H
#define PARSETREECONVERTER_H

#include <algorithm>

#include "ASTNodes.h"
#include "SemanticToken.h"
#include "../Parser/SyntaxNode.h"
class ParseTreeConverter {
public:
    std::unique_ptr<Node> convertTree(const std::shared_ptr<SyntaxNode>& root) {
        if (!root || root->productionName != "CODIGO") {
            std::cerr<<("CODIGO debe ser la raiz del parse");
            return nullptr;
        }

        auto program = std::make_unique<ProgramNode>();

        if (!root->children.empty()) {
            convertCodigo(root, program.get());
        }

        return program;
    }
    ParseTreeConverter(const std::list<SyntaxToken>& symbols)
        : symbolsTable(std::make_shared<std::list<SemanticToken>>()) {
        for (const auto& syntaxToken : symbols) {
            symbolsTable->emplace_back(
                syntaxToken.name,
                syntaxToken.tokenType,
                syntaxToken.line,
                syntaxToken.usageLines,
                syntaxToken.dataType
            );
        }
    }
    std::shared_ptr<std::list<SemanticToken>> getSymbolsTable() {
        return symbolsTable;
    }

private:
    std::shared_ptr<std::list<SemanticToken>> symbolsTable;
    SemanticToken* findTokenPtr(const std::string& name) {
        if (!symbolsTable) return nullptr;

        auto it = std::find_if(symbolsTable->begin(), symbolsTable->end(),
            [name](const SemanticToken& token) {
                return token.name == name;
            });

        if (it != symbolsTable->end()) {
            return &(*it);
        }

        return nullptr;
    }
    void convertCodigo(const std::shared_ptr<SyntaxNode>& codigoNode, ProgramNode* program) {
        if (!codigoNode || !program) return;

        if (!codigoNode->children.empty()) {
            convertBloque(codigoNode->children[0], program);
        }

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

        if (!bloqueNode->children.empty()) {
            auto accionNode = bloqueNode->children[0];
            if (accionNode && accionNode->productionName == "INSTRUCCION") {
                auto instrNode = convertDeclaracion(accionNode->children[0]);
                if (instrNode) {
                    program->addInstruction(instrNode.release());
                }
            }
        }

        if (bloqueNode->children.size() > 1) {
            auto bloquePrime = bloqueNode->children[1];
            while (bloquePrime && bloquePrime->productionName == "BLOQUE'" &&
                   !bloquePrime->children.empty()) {
                if (bloquePrime->children.size() >= 2) {
                    auto accionNode = bloquePrime->children[1];
                    if (accionNode && accionNode->productionName == "INSTRUCCION") {
                        auto instrNode = convertDeclaracion(accionNode->children[0]);
                        if (instrNode) {
                            program->addInstruction(instrNode.release());
                        }
                    }
                }

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

        auto result = convertTerm(node->children[0]);

        if (node->children.size() > 1) {
            auto expPrime = node->children[1];
            while (expPrime && expPrime->productionName == "EXP'" &&
                   expPrime->children.size() >= 4) {

                auto opNode = expPrime->children[1];
                auto termNode = expPrime->children[3];

                auto rightTerm = convertTerm(termNode);
                if (result && rightTerm) {
                    result = std::make_unique<BinaryOperationNode>(
                        result.release(),
                        rightTerm.release(),
                        opNode->children[0]->token.name
                    );
                }

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

        auto result = convertFactor(node->children[0]);

        if (node->children.size() > 1) {
            auto termPrime = node->children[1];
            while (termPrime && termPrime->productionName == "TERM'" &&
                   termPrime->children.size() >= 2) {

                auto op = termPrime->children[0]->token.name;
                auto rightFactor = convertFactor(termPrime->children[1]);

                if (result && rightFactor) {
                    result = std::make_unique<BinaryOperationNode>(
                        result.release(),
                        rightFactor.release(),
                        op
                    );
                }

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

        if (firstChild->token.name == "(") {
            if (node->children.size() >= 3) {
                return convertExpression(node->children[1]);
            }
            return nullptr;
        }

        if (firstChild->token.tokenType == "Identifier") {
            return std::make_unique<IdentifierNode>(
                firstChild->token.name,
                findTokenPtr(firstChild->token.name)
            );
        }

        if (firstChild->token.tokenType == "Constant") {
            return std::make_unique<NumberNode>(
                firstChild->token.name,
                firstChild->token.dataType
            );
        }

        if (firstChild->productionName == "STRING") {
            return convertString(firstChild);
        }

        return nullptr;
    }

    std::unique_ptr<Node> convertDeclaracion(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.size() < 7) return nullptr;

        auto identifierNode = node->children[2];
        if (!identifierNode) return nullptr;

        auto identifier = std::make_unique<IdentifierNode>(
            identifierNode->token.name,
            findTokenPtr(identifierNode->token.name)
        );

        auto expNode = node->children[6];
        auto expression = expNode ? convertExpression(expNode) : nullptr;

        return std::make_unique<DeclarationNode>(
            identifier.release(),
            expression.release()
        );
    }
};

#endif //PARSETREECONVERTER_H
