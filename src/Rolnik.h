#pragma once
#include "Mieszkaniec.h"
#include "MenedzerZasobow.h"

class menedzerZasobow;
class Rolnik : public Mieszkaniec
{
private:
	MenedzerZasobow* menedzerZasobow;
	int  const produkcjaZywnosci;
	int  const zuzycieZywnosci;

public:
	Rolnik(int poziomZadowolenia = 0, int wiek = 0, int poziomZdrowia = 0, MenedzerZasobow* menedzerZasobow = nullptr, int produkcjaZywnosci = 10, int zuzycieZywnosci = 1);
	void pracuj() override;
	void zuzyj() override;
	
};

