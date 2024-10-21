#include <iostream>
#include <list>
#include "../Preprocessing/DoPreproccesing.h"
#include "../Lexer/DoLexicalAnalysis.h"
#include "../Lexer/TokenStruct.h"
#include "../Tools/paths.h"
#include "../Parser/DoSyntaxAnalysis.h"

int main () {
    std::string filePath = inputPath+R"(/example.gdi)";
    std::string content = readFileToString(filePath);
    if(content.empty()) {
        std::cout<<"No content found.\n";
        return 1;
    }
    DoPreprocessing(content);

    filePath = outputPath+R"(/Preprocessing_Code.txt)";
    content = readFileToString(filePath);
    if(content.empty()) {
        std::cout<<"No content found.";
        return 1;
    }
    std::list<LexerToken> LexerTokens = DoLexicalAnalysis(content);

    DoSyntaxAnalysis(LexerTokens);

    return 0;
}
