#pragma once
#include "Building.h"
<<<<<<< HEAD

class City;
=======
#include "City.h"
>>>>>>> origin/main

class Barracks : public Building {
private:
    int safetyBonus;
    City* city;
<<<<<<< HEAD

public:
    Barracks(int safetyBonus, City* city);
    void operate() override;
    std::string getName() const override;
};
=======
public:
    Barracks(City* city = nullptr, int safetyBonus = 10);
    void operate() override;
    std::string getName() const override;
};
>>>>>>> origin/main
