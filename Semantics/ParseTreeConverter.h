

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
            auto instruccionNode = bloqueNode->children[0];
            if (instruccionNode && instruccionNode->productionName == "INSTRUCCION") {
                convertInstruccion(instruccionNode->children[0], program);
            }
        }

        if (bloqueNode->children.size() > 1) {
            auto bloquePrime = bloqueNode->children[1];
            while (bloquePrime && bloquePrime->productionName == "BLOQUE'" &&
                  !bloquePrime->children.empty()) {

                if (bloquePrime->children.size() >= 2) {
                    auto instruccionNode = bloquePrime->children[1];
                    if (instruccionNode && instruccionNode->productionName == "INSTRUCCION") {
                        convertInstruccion(instruccionNode->children[0], program);
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

    void convertInstruccion(const std::shared_ptr<SyntaxNode>& instruccionNode, ProgramNode* program) {
        if(instruccionNode->productionName == "DECLARACION") {
            auto instrNode = convertDeclaracion(instruccionNode);
            if (instrNode) {
                program->addInstruction(instrNode.release());
            }
        }
        else if(instruccionNode->productionName == "ASIGNACION") {
            auto instrNode = convertAsignacion(instruccionNode);
            if (instrNode) {
                program->addInstruction(instrNode.release());
            }
        }
        else if(instruccionNode->productionName == "OBTENER") {
            auto instrNode = convertObtener(instruccionNode);
            if (instrNode) {
                program->addInstruction(instrNode.release());
            }
        }
        else if(instruccionNode->productionName == "PUBLICAR") {
            auto instrNode = convertPublicar(instruccionNode);
            if (instrNode) {
                program->addInstruction(instrNode.release());
            }
        }
        else if(instruccionNode->productionName == "CAMBIAR") {
            auto instrNode = convertCambiar(instruccionNode);
            if (instrNode) {
                program->addInstruction(instrNode.release());
            }
        }
        else if(instruccionNode->productionName == "CONDICIONAL") {
            auto instrNode = convertCondicional(instruccionNode);
            if (instrNode) {
                program->addInstruction(instrNode.release());
            }
        }
    }

    std::unique_ptr<Node> convertObtener(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.size() < 5) return nullptr;

        auto endpointNode = convertStrParam(node->children[2]);
        std::unique_ptr<Node> apiKeyNode = nullptr;
        apiKeyNode = convertStrParam(node->children[4]->children[0]);

        return std::make_unique<GetHttpNode>(
            endpointNode.release(),
            apiKeyNode ? apiKeyNode.release() : nullptr
        );
    }

    std::unique_ptr<Node> convertPublicar(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.size() < 7) return nullptr;

        auto endpointNode = convertStrParam(node->children[2]);
        auto bodyNode = convertStrParam(node->children[4]);
        std::unique_ptr<Node> apiKeyNode = nullptr;
        apiKeyNode = convertStrParam(node->children[6]->children[0]);

        return std::make_unique<PostHttpNode>(
            endpointNode.release(),
            bodyNode.release(),
            apiKeyNode ? apiKeyNode.release() : nullptr
        );
    }

    std::unique_ptr<Node> convertCambiar(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.size() < 9) return nullptr;

        auto endpointNode = convertStrParam(node->children[2]);
        auto idNode = convertDato(node->children[4]->children[0]);
        auto bodyNode = convertStrParam(node->children[6]);
        std::unique_ptr<Node> apiKeyNode = nullptr;
        apiKeyNode = convertStrParam(node->children[8]->children[0]);

        return std::make_unique<PutHttpNode>(
            endpointNode.release(),
            idNode.release(),
            bodyNode.release(),
            apiKeyNode ? apiKeyNode.release() : nullptr
        );
    }

    std::unique_ptr<Node> convertBorrar(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.size() < 7) return nullptr;

        auto endpointNode = convertStrParam(node->children[2]);
        auto idNode = convertDato(node->children[4]->children[0]);
        std::unique_ptr<Node> apiKeyNode = nullptr;
        apiKeyNode = convertStrParam(node->children[6]->children[0]);

        return std::make_unique<DeleteHttpNode>(
            endpointNode.release(),
            idNode.release(),
            apiKeyNode ? apiKeyNode.release() : nullptr
        );
    }

    std::unique_ptr<Node> convertStrParam(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.size() < 1) return nullptr;
        return convertDato(node->children[0]);
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


    std::unique_ptr<Node> convertAsignacion(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.size() < 5) return nullptr;

        auto identifierNode = node->children[0];
        if (!identifierNode) return nullptr;

        auto identifier = std::make_unique<IdentifierNode>(
            identifierNode->token.name,
            findTokenPtr(identifierNode->token.name)
        );

        auto expNode = node->children[4];
        auto expression = expNode ? convertExpression(expNode) : nullptr;

        return std::make_unique<AssignmentNode>(
            identifier.release(),
            expression.release()
        );
    }

    std::unique_ptr<Node> convertCondicional(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.size() < 8) return nullptr;

        auto conditionNode = node->children[2];
        if (!conditionNode) return nullptr;

        auto condition = convertCondition(conditionNode);
        if (!condition) return nullptr;

        auto thenBlockNode = node->children[6];
        if (!thenBlockNode) return nullptr;

        auto thenProgram = std::make_unique<ProgramNode>();
        convertAnidado(thenBlockNode, thenProgram.get());

        auto sinoNode = node->children[7];
        std::unique_ptr<ProgramNode> elseProgram = nullptr;

        if (sinoNode->children.size() >= 2) {
            auto elseBlockNode = sinoNode->children[2];
            if (elseBlockNode) {
                elseProgram = std::make_unique<ProgramNode>();
                convertAnidado(elseBlockNode, elseProgram.get());
            }
        }

        return std::make_unique<ConditionalNode>(
            static_cast<BinaryOperationNode*>(condition.release()),
            thenProgram.release(),
            elseProgram ? elseProgram.release() : nullptr
        );
    }

    void convertAnidado(const std::shared_ptr<SyntaxNode>& anidadoNode, ProgramNode* program) {
        if (!anidadoNode || !program) return;

        if (!anidadoNode->children.empty()) {
            auto instBloqNode = anidadoNode->children[0];
            if (instBloqNode) {
                convertInstruccion(instBloqNode->children[0], program);
            }
        }

        if (anidadoNode->children.size() > 2) {
            auto anidadoPrime = anidadoNode->children[2];
            while (anidadoPrime && anidadoPrime->productionName == "ANIDADO'" &&
                   !anidadoPrime->children.empty()) {

                if (anidadoPrime->children.size() >= 1) {
                    auto instBloqNode = anidadoPrime->children[0];
                    if (instBloqNode->children.size() > 0) {
                        convertInstruccion(instBloqNode->children[0], program);
                    }
                }

                if (anidadoPrime->children.size() > 2) {
                    anidadoPrime = anidadoPrime->children[2];
                } else {
                    break;
                }
            }
        }
    }

    std::unique_ptr<Node> convertCondition(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.empty()) return nullptr;

        auto result = convertComparison(node->children[0]);

        if (node->children.size() > 1) {
            auto conditionPrime = node->children[1];
            while (conditionPrime && conditionPrime->productionName == "CONDICION'" &&
                   !conditionPrime->children.empty()) {

                if (conditionPrime->children.size() >= 2) {
                    auto op = conditionPrime->children[0]->token.name;
                    auto rightComparison = convertComparison(conditionPrime->children[1]);

                    if (result && rightComparison) {
                        result = std::make_unique<BinaryOperationNode>(
                            result.release(),
                            rightComparison.release(),
                            op
                        );
                    }
                }

                if (conditionPrime->children.size() > 2) {
                    conditionPrime = conditionPrime->children[2];
                } else {
                    break;
                }
            }
        }

        return result;
    }

    std::unique_ptr<Node> convertComparison(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.empty()) return nullptr;

        auto result = convertBool(node->children[0]);

        if (node->children.size() > 1) {
            auto comparisonPrime = node->children[1];
            while (comparisonPrime && comparisonPrime->productionName == "COMPARACION'" &&
                   !comparisonPrime->children.empty()) {

                if (comparisonPrime->children.size() >= 2) {
                    auto op = comparisonPrime->children[0]->token.name;
                    auto rightBool = convertBool(comparisonPrime->children[1]);

                    if (result && rightBool) {
                        result = std::make_unique<BinaryOperationNode>(
                            result.release(),
                            rightBool.release(),
                            op
                        );
                    }
                }

                if (comparisonPrime->children.size() > 2) {
                    comparisonPrime = comparisonPrime->children[2];
                } else {
                    break;
                }
            }
        }

        return result;
    }

    std::unique_ptr<Node> convertBool(const std::shared_ptr<SyntaxNode>& node) {
        if (!node || node->children.empty()) return nullptr;

        auto child = node->children[0];
        return convertDato(child);
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
        return std::make_unique<ConstantNode>(
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

        return convertDato(firstChild);
    }

    std::unique_ptr<Node> convertDato(const std::shared_ptr<SyntaxNode>& child) {
        if (child->token.tokenType == "Identifier") {
            return std::make_unique<IdentifierNode>(
                child->token.name,
                findTokenPtr(child->token.name)
            );
        }

        if (child->token.tokenType == "Constant") {
            return std::make_unique<ConstantNode>(
                child->token.name,
                child->token.dataType
            );
        }

        if (child->productionName == "STRING") {
            return convertString(child);
        }

        return nullptr;
    }
};

#endif //PARSETREECONVERTER_H
