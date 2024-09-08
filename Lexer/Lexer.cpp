//
// Created by Dahir on 04/09/2024.
//
#include "Lexer.h"
#include "StatesInfo.h"
#include "TokenStruct.h"
#include <list>
#include <algorithm>
#include <iterator>

Lexer::Lexer() {
    automata = transitionTable;
    line = 1;
}

// Reads the input using the transition table of the automata
void Lexer::ReadInput(const std::string& code) {
    std::string word = "";
    int currentIndex = 0;
    int state = 0;
    while(currentIndex < code.length()) {
        const int prevState = state;
        state = automata.processTransition(state,code[currentIndex]);
        if (state == -1) {
            state=0;
            if (!word.empty()) tokens.emplace_back(word,testState(prevState),line);
            if (word == "\n") line++;
        }
        else {
            word += code[currentIndex];
            currentIndex++;
        }
    }
}

// Identifies the token type of each state
std::string Lexer::testState(int state) {
    if (std::find(std::begin(identifier), std::end(identifier), state) != std::end(identifier)) return "Identifier";
    if (std::find(std::begin(keywords), std::end(keywords), state) != std::end(keywords)) return "Keyword";
    if (std::find(std::begin(operation), std::end(operation), state) != std::end(operation)) return "Operation";
    if (std::find(std::begin(punctuation), std::end(punctuation), state) != std::end(punctuation)) return "Punctuation";
    if (std::find(std::begin(constant), std::end(constant), state) != std::end(constant)) return "Constant";
    return "";
}

std::list<Token> Lexer::getTokens() {
    return tokens;
}
