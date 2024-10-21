

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
