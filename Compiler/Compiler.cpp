#include <iostream>
#include <list>
#include "../Preprocessing/DoPreproccesing.h"
#include "../Lexer/DoLexicalAnalysis.h"
#include "../Lexer/TokenStruct.h"
#include "../Tools/paths.h"
#include "../Parser/DoSyntaxAnalysis.h"
#include "../Semantics/DoSemanticAnalysis.h"

int main () {
    std::string filePath = inputPath+R"(/example.gdi)";
    std::string content = readFileToString(filePath);
    if(content.empty()) {
        std::cout<<"No content found.\n";
        return 1;
    }
    doPreprocessing(content);

    filePath = outputPath+R"(/Preprocessing_Code.txt)";
    content = readFileToString(filePath);
    if(content.empty()) {
        std::cout<<"No content found.";
        return 1;
    }
    std::list<LexerToken> LexerTokens = doLexicalAnalysis(content);

    std::pair<std::shared_ptr<SyntaxNode>,std::list<SyntaxToken>> syntaxProducts = doSyntaxAnalysis(LexerTokens);
    if(nullptr == syntaxProducts.first) exit(0);

    std::pair<std::shared_ptr<std::list<SemanticToken>>, std::unique_ptr<Node>> semanticProducts = doSemanticAnalysis(syntaxProducts.first, syntaxProducts.second);
    if(nullptr == semanticProducts.first) exit(0);

    return 0;
}
