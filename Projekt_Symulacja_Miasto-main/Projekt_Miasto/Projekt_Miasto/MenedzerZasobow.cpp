#include "MenedzerZasobow.h"
MenedzerZasobow::MenedzerZasobow() {
	zasoby[TypZasobu::FOOD] = 0;
	zasoby[TypZasobu::GOLD] = 0;
	zasoby[TypZasobu::WOOD] = 0;
	zasoby[TypZasobu::STONE] = 0;
}
void MenedzerZasobow::dodajZasob(TypZasobu typ, int ilosc) {
	if (ilosc > 0) {
		zasoby[typ] += ilosc;
	}
}
bool MenedzerZasobow::zuzyjZasob(TypZasobu typ, int ilosc) {
	if (ilosc > 0 && zasoby[typ] >= ilosc) {
		zasoby[typ] -= ilosc;
		return true;
	}
	return false;
}
int MenedzerZasobow::pobierzIloscZasobu(TypZasobu typ) const {
	return zasoby.at(typ);
}





