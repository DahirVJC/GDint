#include <fstream>
#include <string>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <list>

#include "paths.h"

// Asistido por: ChatGPT
std::string readFileToString(const std::string& filePath) {
    std::ifstream in_file(filePath);
    if (!in_file) {
        std::cerr << "Error: no se pudo abrir el archio '" << filePath << "'. ";
        std::cerr << "Motivo: " << strerror(errno) << std::endl;
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
    if (!out_file) {
        std::cerr << "Error: No se pudo abrir o modificar el archivo " << fileName << std::endl;
        return;
    }
    out_file << content;
    out_file.close();
}
bool logOn() {
    std::ifstream file(inputPath+R"(/Config.txt)");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << inputPath+R"(/Config.txt)" << std::endl;
        return false;
    }

    while (std::getline(file, line)) {
        if (line.find("LOG=TRUE") != std::string::npos) {
            return true;
        }
        if (line.find("LOG=FALSE") != std::string::npos) {
            return false;
        }
    }
    return false;
}

// Fin Asistencia