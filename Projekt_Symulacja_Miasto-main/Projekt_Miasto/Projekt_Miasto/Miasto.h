#pragma once
#include <vector>
#include <memory>
#include "Mieszkaniec.h"


#include "MenedzerZasobow.h"

class Miasto {
private:
    MenedzerZasobow menedzerZasobow;
    int bezpieczenstwo;
    int turyBezJedzenia;
    int turyBezZlota;
    int turyBezBezpieczenstwa;
    std::vector<std::unique_ptr<Mieszkaniec>> mieszkancy;

public:
    // 
    Miasto();

    // 
    MenedzerZasobow& getMenedzerZasobow();
    const MenedzerZasobow& getMenedzerZasobow() const;
    int getBezpieczenstwo() const;
    //
    void dodajMieszkanca(std::unique_ptr<Mieszkaniec> mieszkaniec);
    void wykonajAkcjeMieszkancow();

    // 
    void zmienBezpieczenstwo(int ilosc);
    void aktualizujTurydoUpadku();
    bool sprawdzWarunkiUpadku();
};

