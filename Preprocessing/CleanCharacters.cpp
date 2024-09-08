#include <string>
#include "BlankCharacters.hpp"

inline bool isBlank(const char c) {
    return //c == Space ||
           c == HorizontalTab ||
           c == CarriageReturn ||
           c == VerticalTab ||
           c == FormFeed;
}

std::string cleanCharacters(const std::string& str){
    std::string output;
    for(char c : str){
        if(!isBlank(c)) output += c;
    }
    return output;
}