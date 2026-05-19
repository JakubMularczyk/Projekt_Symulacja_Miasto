#pragma once
#ifndef Miasta_h
#define Miasto_h

#include "MenedzerZasobow.h"

class Miasto {
private:
    MenedzerZasobow menedzerZasobow;
    int bezpieczenstwo; 
    
    int turyBezJedzenia;
    int turyBezZlota;
    int turyBezBezpieczenstwa;

public:
    Miasto() : 
        bezpieczenstwo(10), 
        turyBezJedzenia(0), 
        turyBezZlota(0), 
        turyBezBezpieczenstwa(0) {}

    MenedzerZasobow& getMenedzerZasobow() {
        return menedzerZasobow;
    }

    int getBezpieczenstwo() const { return bezpieczenstwo; }
    void zmienBezpieczenstwo(int ilosc) { bezpieczenstwo += ilosc; }
    
    // trzeba później dodac sprawdzanie warunków upadku [cite: 18, 19, 20, 21]
};

#endif
