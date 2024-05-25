#ifndef PDA_ACCEPTANCE_DESCRIEREINSTANTANEE_H
#define PDA_ACCEPTANCE_DESCRIEREINSTANTANEE_H


#include <stack>

class descriereInstantanee {
    int stare;
    int pozCuvant;
    std::stack<char> stiva;
public:
    descriereInstantanee(int stare, int pozCuvant, const std::stack<char> &stiva);
    descriereInstantanee(int stare, int pozCuvant);
    void initStiva(char simbol);
};


#endif //PDA_ACCEPTANCE_DESCRIEREINSTANTANEE_H
