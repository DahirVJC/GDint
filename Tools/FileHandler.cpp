#include <fstream>
#include <string>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <list>

std::string readFileToString(const std::string& filePath) {
    std::ifstream in_file(filePath);
    if (!in_file) {
        std::cerr << "Error: Could not open file '" << filePath << "'. ";
        std::cerr << "Reason: " << strerror(errno) << std::endl;
        return "";
    }
    std::string content;
    std::string line;

    while (std::getline(in_file, line)) {
        content += line;
        content += "\n";
    }
    in_file.close();
    return content;
}

void writeStringToFile(const std::string& content, const std::string& fileName){
    std::ofstream out_file(fileName);
    if (!out_file) {  // Check if the file was opened successfully
        std::cerr << "Error: Could not open or create the file " << fileName << std::endl;
        return;
    }
    out_file << content;
    out_file.close();
}