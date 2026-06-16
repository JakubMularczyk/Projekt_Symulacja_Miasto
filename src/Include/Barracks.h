#pragma once
#include "Building.h"
#include "City.h"

class Barracks : public Building {
private:
    int safetyBonus;
    City* city;

public:
    Barracks(City* city = nullptr, int safetyBonus = 10);
    void operate() override;
    std::string getName() const override;
};
