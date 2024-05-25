#include "descriereInstantanee.h"

descriereInstantanee::descriereInstantanee(int stare, int pozCuvant, const std::stack<char> &stiva) : stare(stare),
                                                                                                      pozCuvant(
                                                                                                              pozCuvant),
                                                                                                      stiva(stiva) {}

void descriereInstantanee::initStiva(char simbol) {
    while(!stiva.empty())
        stiva.pop();
    stiva.push(simbol);
}

descriereInstantanee::descriereInstantanee(int stare, int pozCuvant) : stare(stare), pozCuvant(pozCuvant) {}
