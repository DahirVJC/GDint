//
// Created by Dahir on 06/09/2024.
//

#include "Automata.h"

int Automata::processTransition(const int state, const char symbol) {
    if (transitionTable[state].find(symbol) != transitionTable[state].end()) {
        return transitionTable[state][symbol];
    }
    return -1;
}
