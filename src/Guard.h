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
    Guard(int happinessLevel = 0, int age = 0, int healthLevel = 0, City* city = nullptr, ResourceManager* resourceManager = nullptr, int safetyProduction = 10, int foodConsumption = 1);
    void work() override;
    void consume() override;
};