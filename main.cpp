#include <iostream>
#include "PDA.h"

int main() {
    PDA a;
    a.citestePDA();
    if(a.acceptaCuvant("aaabbb"))
        std::cout << "ACCEPTAT";
    else
        std::cout << "RESPINS";
    return 0;
}