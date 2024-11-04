//
// Created by Dahir on 04/09/2024.
//
#include "Lexer.h"
#include "StatesInfo.h"
#include "TokenStruct.h"
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "../Tools/TokenTypes.h"

Lexer::Lexer() {
}

// Reads the input using the transition table of the automata
void Lexer::readInput(const std::string& code) {
    std::string word = "";
    int currentIndex = 0;
    int state = 0;
    int currentLine = 1;
    while(currentIndex < code.length()) {
        const int prevState = state;
        state = automata.processTransition(state,code[currentIndex]);
        if (state == -1) {
            state=0;
            if (std::find(std::begin(nonFinal), std::end(nonFinal), prevState) != std::end(nonFinal)) {
                std::cerr << "Lexical Error: string not recognized by the automata detected.\n";
                //return;
                exit(0);
            }
            if (!word.empty()) tokens.emplace_back(word,testState(prevState),currentLine);
            if (word == "\n") currentLine++;
            word = "";
        }
        else {
            word += code[currentIndex];
            currentIndex++;
        }
    }
}

// Identifies the token type of each state
std::string Lexer::testState(const int state) {
    if (std::find(std::begin(identifier), std::end(identifier), state) != std::end(identifier)) return IDENTIFIER;
    if (std::find(std::begin(keywords), std::end(keywords), state) != std::end(keywords)) return KEYWORD;
    if (std::find(std::begin(operation), std::end(operation), state) != std::end(operation)) return OPERATION;
    if (std::find(std::begin(punctuation), std::end(punctuation), state) != std::end(punctuation)) return PUNCTUATION;
    if (std::find(std::begin(constant), std::end(constant), state) != std::end(constant)) return CONSTANT;
    return "";
}

std::list<LexerToken> Lexer::getTokens() {
    return tokens;
}
