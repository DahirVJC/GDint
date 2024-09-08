//
// Created by hij555 on 9/8/24.
//

#ifndef DOPREPROCCESING_H
#define DOPREPROCCESING_H
#include <iostream>
#include "../Tools/FileHandler.hpp"
#include "CleanCharacters.hpp"

inline void DoPreprocessing(std::string content) {
    content = cleanCharacters(content);
    std::cout<<content;
    writeStringToFile(content, "../output/Preprocessing_Code.txt");
}

#endif //DOPREPROCCESING_H
