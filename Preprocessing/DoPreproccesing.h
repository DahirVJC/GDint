//
// Created by hij555 on 9/8/24.
//

#ifndef DOPREPROCCESING_H
#define DOPREPROCCESING_H
#include <iostream>
#include "../Tools/FileHandler.hpp"
#include "CleanCharacters.hpp"
#include "../Tools/paths.h"

inline void DoPreprocessing(std::string content) {
    content = cleanCharacters(content);
    std::cout<<content;
    std::string filePath = outputPath+"/Preprocessing_Code.txt";
    writeStringToFile(content, filePath );
}

#endif //DOPREPROCCESING_H
