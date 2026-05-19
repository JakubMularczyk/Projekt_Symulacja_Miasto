#pragma once
#ifndef Miasto_h
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
    
    bool sprawdzWarunkiUpadku() {
        if (menedzerZasobow.pobierzIloscZasobu(TypZasobu::FOOD) <= 0) {
        turyBezJedzenia++; [cite: 18]
    } else {
        turyBezJedzenia = 0;
    }
        if (menedzerZasobow.pobierzIloscZasobu(TypZasobu::GOLD) <= 0) {
        turyBezZlota++; [cite: 19]
    } else {
        turyBezZlota = 0;
    }
        if (bezpieczenstwo <= 0) {
        turyBezBezpieczenstwa++; [cite: 20]
    } else {
        turyBezBezpieczenstwa = 0;
    }
        if (turyBezJedzenia >= 3 || turyBezZlota >= 3 || turyBezBezpieczenstwa >= 3) {
        return true; 
    }
    return false;
};

#endif
