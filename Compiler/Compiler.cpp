#include <iostream>
#include <list>
#include "../Preprocessing/DoPreproccesing.h"
#include "../Lexer/DoLexicalAnalysis.h"
#include "../Lexer/TokenStruct.h"
#include "../Compiler/paths.h"

int main () {
    std::string filePath = inputPath+"example.gdi";
    std::string content = readFileToString(filePath);
    if(content.empty()) {
        std::cout<<"No content found.\n";
        return 1;
    }
    DoPreprocessing(content);

    filePath = outputPath+"Preprocessing_Code.txt";
    content = readFileToString(filePath);
    if(content.empty()) {
        std::cout<<"No content found.";
        return 1;
    }
    std::list<Token> LexerTokens = DoLexicalAnalysis(content);
    return 0;
}
