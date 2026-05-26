#pragma once

#include "Mieszkaniec.h"
#include "MenedzerZasobow.h"
#include "Miasto.h"

class menedzerZasobow;
class Straznik : public Mieszkaniec
{
private:
	MenedzerZasobow* menedzerZasobow;
	int  const produkcjaBezpieczenstwa;
	int  const zuzycieZywnosci;
	Miasto* miasto;

public:
	Straznik(int poziomZadowolenia = 0, int wiek = 0, int poziomZdrowia = 0, Miasto* miasto = nullptr, MenedzerZasobow* menedzerZasobow = nullptr, int produkcjaBezpieczenstwa = 10, int zuzycieZywnosci = 1);
	void pracuj() override;
	void zuzyj() override;
};