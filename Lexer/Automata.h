//
// Created by Dahir on 06/09/2024.
//

#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <map>

// An automata uses the transition table to determine the next state given the current state and a symbol
class Automata {
    //Process
    std::map<int, std::map<char, int>> transitionTable;
    public:
    //Constructor
    Automata(const std::map<int, std::map<char, int>>& transitions)
        : transitionTable(transitions){}
    //Process
    int processTransition(int state, char symbol);
};



#endif //AUTOMATA_H
