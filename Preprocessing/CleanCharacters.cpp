#include <string>
#include <sstream>
#include "BlankCharacters.hpp"

inline bool isBlank(const char c) {
    return //c == Space ||
           c == HorizontalTab ||
           c == CarriageReturn ||
           c == VerticalTab ||
           c == FormFeed;
}

// Generado por: ChatGPT
std::string removeSpaces(const std::string& input) {
    std::istringstream iss(input);
    std::ostringstream oss;
    std::string line;

    while (std::getline(iss, line)) {
        line.erase(0, line.find_first_not_of(" "));
        line.erase(line.find_last_not_of(" ") + 1);
        oss << line << "\n";
    }

    return oss.str();
}
// Fin Generacion

std::string cleanCharacters(const std::string& str){
    std::string output;
    for(char c : str){
        if(!isBlank(c)) output += tolower(c);
    }
    return removeSpaces(output);
}