#pragma once
#include "Citizen.h"
#include "ResourceManager.h"
#include "City.h"

class Guard : public Citizen {
private:
    ResourceManager* resourceManager;
    int const safetyProduction;
    int const foodConsumption;
    City* city;

public:
    Guard(int happinessLevel, int age, ResourceManager* rm, int foodConsumption, int safetyProduction, City* city);
    void work() override;
    void consume() override;
};