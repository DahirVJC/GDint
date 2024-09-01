#include <iostream>
#include "FileHandler.hpp"
#include "CleanCharacters.hpp"

int main() {

    std::string filePath = "example.gdi";
    std::string content = readFileToString(filePath);
    if(content.empty()) std::cout<<"No content found.";
    content = cleanCharacters(content);
    std::cout<<content;
    writeStringToFile(content, "output");
}
