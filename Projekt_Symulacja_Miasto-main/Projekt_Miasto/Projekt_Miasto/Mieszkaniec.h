#pragma once



class Mieszkaniec
{
protected:
	int poziomZadowolenia;
	int wiek;
    int poziomZdrowia;


public:
    Mieszkaniec(int poziomZadowolenia = 0, int wiek = 0, int poziomZdrowia = 0);
  

    virtual ~Mieszkaniec() = default;

    virtual void pracuj() = 0;
    virtual void zuzyj() = 0;

};

