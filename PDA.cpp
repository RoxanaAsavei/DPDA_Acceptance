#include "PDA.h"
#include "descriereInstantanee.h"
#include <fstream>
#include <queue>

/**
 * Se citesc productiile de forma (stareInit, literaCuvant, literaStiva) -> (stareFinala, cuvant)
 * Lambda se va reprezenta prin # (grija sa nu fie conflict cu simbolul initial de pe stiva)
 * */

void PDA::citestePDA() {
    std::ifstream fin("date.in");
    fin >> nrStari;
    stari.resize(nrStari);
    for(int i = 0; i < nrStari; ++i) {
        fin >> stari[i];
    }
    fin >> lgAlfabetIntrare;
    alfabetIntrare.resize(lgAlfabetIntrare);
    for(int i = 0; i < lgAlfabetIntrare; ++i) {
        fin >> alfabetIntrare[i];
    }
    fin >> stareInit;
    fin >> nrStariFinale;
    stariFinale.resize(nrStariFinale);
    for(int i = 0; i < nrStariFinale; ++i) {
        fin >> stariFinale[i];
    }
    fin >> nrProductii;
    int stare1;
    char literaCuvant, literaStiva;
    std::string cuvantPush;
    int stare2;
    for(int i = 0; i < nrProductii; ++i) {
        fin >> stare1 >> literaCuvant >> literaStiva;
        leftProd.emplace_back(stare1, literaCuvant, literaStiva);
        fin >> stare2 >> cuvantPush;
        rightProd.emplace_back(stare2, cuvantPush);
    }

    // prima productie e compusa din leftProd[0] si rightProd[0]

    fin >> lgAlfabetStiva;
    alfabetStiva.resize(lgAlfabetStiva);
    for(int i = 0; i < lgAlfabetStiva; ++i) {
        fin >> alfabetStiva[i];
    }
    fin >> simbolInitial;
}
// lambda se va reprezenta prin #
bool PDA::acceptaCuvant(std::string cuvant) {
    std::stack<char> stiva;
    stiva.emplace(simbolInitial);
    int stare_curenta = stareInit;
    int poz_cuvant = 0;
    while(poz_cuvant < cuvant.length()){
        /// stare_curenta, cuvant[poz_cuvant] / sau lambda , stiva.top()
        int idx = Cauta(stare_curenta, cuvant[poz_cuvant], stiva.top());
        if(idx != -1) { // am gasit o productie chiar cu litera din cuvant
            stiva.pop();
            stare_curenta = rightProd[idx].first;
            std::string cuvant1 = rightProd[idx].second;
            adaugaCuvant(stiva, cuvant1);
            poz_cuvant++;
        }
        else {
            idx = lambdaTranzitie(stare_curenta, stiva.top());
            if(idx != -1) { // macar avem o lambda tranzitie
                stiva.pop();
                stare_curenta = rightProd[idx].first;
                std::string cuvant1 = rightProd[idx].second;
                adaugaCuvant(stiva, cuvant1);
             }
            else return 0;
        }
    }

    if(stiva.empty() || eFinala(stare_curenta))
        return true;
    return false;

}

int PDA::Cauta(int stare, char litCuvant, char simbolStiva) {
    for(int i = 0; i < nrProductii; ++i) {
        if(leftProd[i] == std::make_tuple(stare, litCuvant, simbolStiva))
            return i;
    }
    return -1;
}

void PDA::adaugaCuvant(std::stack<char> &stiva, std::string &cuvant) {
    if(cuvant != "#") {
        for(int i = cuvant.length() - 1; i >= 0; --i) {
            stiva.emplace(cuvant[i]);
        }
    }
}

bool PDA::eFinala(int stare) {
    for(auto s : stariFinale) {
        if(s == stare) return true;
    }
    return false;
}

int PDA::lambdaTranzitie(int stare, char simbolStiva) {
    for(int i = 0; i < nrProductii; ++i) {
        if(leftProd[i] == std::make_tuple(stare, '#', simbolStiva))
            return i;
    }

    return -1;
}



