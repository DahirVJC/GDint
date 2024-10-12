//
// Created by Dahir on 11/10/2024.
//

#ifndef PREPARSER_H
#define PREPARSER_H
#include <list>
#include <map>
#include <string>

class Preparser {
private:
    std::list<std::map<std::string, std::list<std::string>>> CFGs;
public:
    std::map<std::string, std::list<std::string>> convertLeftToRightRecursive;
};



#endif //PREPARSER_H
