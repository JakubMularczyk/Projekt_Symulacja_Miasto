#pragma once
#ifndef MIASTO_H
#define MIASTO_H

#include "MenedzerZasobow.h"

class Miasto {
private:
    MenedzerZasobow menedzerZasobow;
    int bezpieczenstwo;
    int turyBezJedzenia;
    int turyBezZlota;
    int turyBezBezpieczenstwa;

public:
    // 
    Miasto();

    // 
    MenedzerZasobow& getMenedzerZasobow();
    const MenedzerZasobow& getMenedzerZasobow() const;
    int getBezpieczenstwo() const;

    // 
    void zmienBezpieczenstwo(int ilosc);
    void aktualizujTurydoUpadku();
    bool sprawdzWarunkiUpadku();
};

#endif