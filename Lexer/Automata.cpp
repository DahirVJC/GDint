//
// Created by Dahir on 06/09/2024.
//

#include "Automata.h"

// Determine the next state given a state and a symbol. Returns -1 if it is an error state
int Automata::processTransition(const int state, const char symbol) {
    if (transitionTable[state].find(symbol) != transitionTable[state].end()) {
        return transitionTable[state][symbol];
    }
    return -1;
}
