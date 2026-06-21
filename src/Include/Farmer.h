#pragma once
#include "Citizen.h"
#include "ResourceManager.h"

class Farmer : public Citizen {
private:
    ResourceManager* resourceManager;
    int const foodProduction;
    int const foodConsumption;

public:
    Farmer(int happinessLevel = 0, ResourceManager* resourceManager = nullptr, int foodProduction = 10, int foodConsumption = 1);
    void work() override;
    void consume() override;
};