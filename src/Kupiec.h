#pragma once
#include "Mieszkaniec.h"
#include "MenedzerZasobow.h"


class Kupiec : public Mieszkaniec
{
private:
	MenedzerZasobow* menedzerZasobow;
	int  const zuzycieZywnosci;
public:
	Kupiec(int poziomZadowolenia = 0, int wiek = 0, int poziomZdrowia = 0, MenedzerZasobow* menedzerZasobow = nullptr, int zuzycieZywnosci = 1);
	void pracuj() override;
	void zuzyj() override;


};