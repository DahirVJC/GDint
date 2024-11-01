

#include "util.h"

#include <iostream>
#include <sstream>

// Source: https://www.geeksforgeeks.org/split-string-by-space-into-vector-in-cpp-stl/
std::vector<std::string> splitByChar(const std::string &str, const char c) {
    std::string s;
    std::stringstream ss(str);
    std::vector<std::string> v;
    while (getline(ss, s, c)) {
        v.push_back(s);
    }
    return v;
}

std::string symbolFormat(std::string symbol) {
    if (symbol == "\n") return  R"(\n)";
    if (symbol == " ") return  "space";
    return symbol;
}

std::vector<char> butCharGetAllChars(char excluded) {
    std::vector<char> butExcludedAllChar;
    for (int i = 32; i < 127; ++i) {
        unsigned char c = static_cast<unsigned char>(i);
        if (c != excluded) butExcludedAllChar.emplace_back(c);
    }
    return butExcludedAllChar;
}

void getFirstLexerToken(const std::list<LexerToken> &tokens, const std::string &tokenName, LexerToken &output) {
    for (LexerToken token : tokens ) {
        if (token.name == tokenName) {
            output = token;
            return;
        }
    }
}
