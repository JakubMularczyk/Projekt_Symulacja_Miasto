#include "Kupiec.h"
Kupiec::Kupiec(int poziomZadowolenia, int wiek, int poziomZdrowia, MenedzerZasobow* menedzerZasobow, int zuzycieZywnosci)
	: Mieszkaniec(poziomZadowolenia, wiek, poziomZdrowia), menedzerZasobow(menedzerZasobow), zuzycieZywnosci(zuzycieZywnosci)
{
}
void Kupiec::pracuj(){
	//if(menedzerZasobow->pobierzIloscZasobu(TypZasobu::FOOD =! 0))
	if (menedzerZasobow->pobierzIloscZasobu(TypZasobu::FOOD) > 50) {
		menedzerZasobow->zuzyjZasob(TypZasobu::FOOD, 2);
		menedzerZasobow->dodajZasob(TypZasobu::GOLD, 8);
	}
}
void Kupiec::zuzyj() {
	menedzerZasobow->zuzyjZasob(TypZasobu::FOOD,zuzycieZywnosci);
}