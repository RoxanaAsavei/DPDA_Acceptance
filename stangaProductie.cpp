#include "stangaProductie.h"
#include <fstream>

void stangaProductie::citeste() {
    std::ifstream fin("date.in");
    fin >> stare >> litera >> simbolStiva;
}

bool stangaProductie::operator==(const stangaProductie &rhs) const {
    return stare == rhs.stare &&
           litera == rhs.litera &&
           simbolStiva == rhs.simbolStiva;
}

bool stangaProductie::operator!=(const stangaProductie &rhs) const {
    return !(rhs == *this);
}
