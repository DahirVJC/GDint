//
// Created by hij555 on 10/13/24.
//

#ifndef UTIL_H
#define UTIL_H
#include <list>
#include <string>
#include <vector>
#include "../Lexer/TokenStruct.h"

std::vector<std::string> splitByChar(const std::string &str, char c);
std::string symbolFormat(std::string symbol);
std::vector<char> butCharGetAllChars(char excluded);
void getFirstLexerToken(const std::list<LexerToken> &tokens, const std::string &tokenName, LexerToken &output);
#endif //UTIL_H
