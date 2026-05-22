#include "Miasto.h"


Miasto::Miasto() :
    bezpieczenstwo(10),
    turyBezJedzenia(0),
    turyBezZlota(0),
    turyBezBezpieczenstwa(0) {
}

MenedzerZasobow& Miasto::getMenedzerZasobow() {
    return menedzerZasobow;
}

const MenedzerZasobow& Miasto::getMenedzerZasobow() const {
    return menedzerZasobow;
}

int Miasto::getBezpieczenstwo() const {
    return bezpieczenstwo;
}

void Miasto::zmienBezpieczenstwo(int ilosc) {
    bezpieczenstwo += ilosc;
}

void Miasto::aktualizujTurydoUpadku() {
    if (menedzerZasobow.pobierzIloscZasobu(TypZasobu::FOOD) <= 0) {
        turyBezJedzenia++;
    }
    else {
        turyBezJedzenia = 0;
    }

    if (menedzerZasobow.pobierzIloscZasobu(TypZasobu::GOLD) <= 0) {
        turyBezZlota++;
    }
    else {
        turyBezZlota = 0;
    }

    if (bezpieczenstwo <= 0) {
        turyBezBezpieczenstwa++;
    }
    else {
        turyBezBezpieczenstwa = 0;
    }
}

bool Miasto::sprawdzWarunkiUpadku() {
    if (turyBezJedzenia >= 3 || turyBezZlota >= 3 || turyBezBezpieczenstwa >= 3) {
        return true;
    }
    return false;
}