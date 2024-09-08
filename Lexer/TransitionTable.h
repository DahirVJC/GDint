//
// Created by hij555 on 9/7/24.
//

#ifndef TRANSITIONTABLE_H
#define TRANSITIONTABLE_H
#include <map>
// The transition table defines the transitions of an automata
// Structure: {CurrentState, {{Symbol, NextState}}}
extern std::map<int, std::map<char, int>> transitionTableDFA;
    #endif //TRANSITIONTABLE_H
