#pragma once
#ifndef SILNIK_H
#define SILNIK_H

#include "../city/Miasto.h"

class Silnik {
private:
    Miasto miasto;
    int aktualnaTura;
    bool czyDziałaSymulacja;

    void wykonajTure();
    void wyswietlRaport() const;
    void pokazMenu();

public:
    Silnik();
    void uruchom();
};

#endif
