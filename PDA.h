#ifndef PDA_ACCEPTANCE_PDA_H
#define PDA_ACCEPTANCE_PDA_H
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include "stangaProductie.h"

class PDA {
    int nrStari;
    std::vector<int> stari;
    int lgAlfabetIntrare;
    std::vector<char> alfabetIntrare;
    int stareInit;
    int nrStariFinale;
    std::vector<int> stariFinale;
    int nrProductii;
    std::vector<std::tuple<int, char, char>> leftProd;
    std::vector<std::pair<int, std::string>> rightProd;
    /// se citeste productia stare1, literaCuvant, literaStiva, stare2, cuvantPush
    /// (stare1, literaCuvant, literaStiva) - primeste un indice p => se afla in stangaProd[p]
    /// mai departe dreaptaProd[p] = (stare2, cuvantPush)
    /**
     * DPDA = dintr o stare cu o anumita litera din alfabet si cu un anumit caracter din stiva
     *          merg intr o singura stare (am o singura varianta)
     * */

    int lgAlfabetStiva;
    std::vector<char> alfabetStiva;
    char simbolInitial;

public:
    PDA() = default;
    void citestePDA();
    bool acceptaCuvant(std::string cuvant);
    int Cauta(int stare, char litCuvant, char simbolStiva);
    void adaugaCuvant(std::stack<char>& stiva, std::string& cuvant);
    bool eFinala(int stare);
    int lambdaTranzitie(int stare, char simbolStiva);
};


#endif //PDA_ACCEPTANCE_PDA_H
