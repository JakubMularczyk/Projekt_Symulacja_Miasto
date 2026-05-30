#include "Straznik.h"

Straznik::Straznik(int poziomZadowolenia, int wiek, int poziomZdrowia, Miasto* miasto, MenedzerZasobow* menedzerZasobow, int produkcjaBezpieczenstwa, int zuzycieZywnosci)
    : Mieszkaniec(poziomZadowolenia, wiek, poziomZdrowia), miasto(miasto), menedzerZasobow(menedzerZasobow), produkcjaBezpieczenstwa(produkcjaBezpieczenstwa), zuzycieZywnosci(zuzycieZywnosci)
{
}
void Straznik::pracuj() {
    if ((miasto->getBezpieczenstwo() + produkcjaBezpieczenstwa) <= 100) {
        miasto->zmienBezpieczenstwo(produkcjaBezpieczenstwa);
    }

}
void Straznik::zuzyj() {
    menedzerZasobow->zuzyjZasob(TypZasobu::FOOD, zuzycieZywnosci);
}