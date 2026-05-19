#pragma once
#ifndef Miasta_h
#define Miasto_h

#include "MenedzerZasobow.h"

class Miasto {
private:
    MenedzerZasobow menedzerZasobow;
    int bezpieczenstwo; // Odpowiednik parametru SECURITY 
    
    // Liczniki potrzebne do weryfikacji warunków upadku miasta 
    int turyBezJedzenia;
    int turyBezZlota;
    int turyBezBezpieczenstwa;

public:
    Miasto() : 
        bezpieczenstwo(10), 
        turyBezJedzenia(0), 
        turyBezZlota(0), 
        turyBezBezpieczenstwa(0) {}

    // Dostęp do menedżera zasobów przez referencję
    MenedzerZasobow& getMenedzerZasobow() {
        return menedzerZasobow;
    }

    // Gettery i settery dla statystyki bezpieczeństwa
    int getBezpieczenstwo() const { return bezpieczenstwo; }
    void zmienBezpieczenstwo(int ilosc) { bezpieczenstwo += ilosc; }
    
    // W tym miejscu w pliku .cpp zaimplementujemy później sprawdzanie warunków upadku [cite: 18, 19, 20, 21]
};

#endif
