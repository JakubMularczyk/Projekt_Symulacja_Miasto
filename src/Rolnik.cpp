#include "Rolnik.h"

Rolnik::Rolnik(int poziomZadowolenia, int wiek, int poziomZdrowia, MenedzerZasobow* menedzerZasobow , int produkcjaZywnosci, int zuzycieZywnosci)
    : Mieszkaniec(poziomZadowolenia, wiek, poziomZdrowia), menedzerZasobow(menedzerZasobow), produkcjaZywnosci(produkcjaZywnosci), zuzycieZywnosci(zuzycieZywnosci)
{
}
void Rolnik::pracuj() {
    menedzerZasobow->dodajZasob(TypZasobu::FOOD, produkcjaZywnosci);

}
void Rolnik::zuzyj() {
    menedzerZasobow->zuzyjZasob(TypZasobu::FOOD, zuzycieZywnosci);
}