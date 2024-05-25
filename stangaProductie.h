
#ifndef PDA_ACCEPTANCE_STANGAPRODUCTIE_H
#define PDA_ACCEPTANCE_STANGAPRODUCTIE_H

class stangaProductie {
    int stare;
    char litera;
    char simbolStiva;

public:
    stangaProductie() = default;

    bool operator==(const stangaProductie &rhs) const;

    bool operator!=(const stangaProductie &rhs) const;

    void citeste();
};


#endif //PDA_ACCEPTANCE_STANGAPRODUCTIE_H
