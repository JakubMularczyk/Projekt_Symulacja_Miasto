#ifndef MenedzerZasobow_h
#define MenedzerZasobow_h

#include <map>
#include "Zasoby.h"

class MenedzerZasobow {
private:
    std::map<TypZasobu, int> zasoby;

public:
    MenedzerZasobow() {
        zasoby[TypZasobu::FOOD] = 0;
        zasoby[TypZasobu::GOLD] = 0;
        zasoby[TypZasobu::WOOD] = 0;
        zasoby[TypZasobu::STONE] = 0;
    }

    void dodajZasob(TypZasobu typ, int ilosc) {
        if (ilosc > 0) {
            zasoby[typ] += ilosc;
        }
    }

    bool zuzyjZasob(TypZasobu typ, int ilosc) {
        if (ilosc > 0 && zasoby[typ] >= ilosc) {
            zasoby[typ] -= ilosc;
            return true; 
        }
        return false; 
    }

    int pobierzIloscZasobu(TypZasobu typ) const {
        return zasoby.at(typ); 
    }
};

#endif
