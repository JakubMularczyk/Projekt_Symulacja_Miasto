#pragma once
#include "Building.h"

class City;

class Barracks : public Building {
private:
    int safetyBonus;
    City* city;

public:
    Barracks(int safetyBonus, City* city);
    void operate() override;
    std::string getName() const override;
};
