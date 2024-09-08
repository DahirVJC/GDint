//
// Created by Dahir on 06/09/2024.
//

#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <map>


class Automata {
    std::map<int, std::map<char, int>> transitionTable;
    public:
    Automata(const std::map<int, std::map<char, int>>& transitions)
        : transitionTable(transitions){}
    int processTransition(int state, char symbol);
};



#endif //AUTOMATA_H
