#pragma once
#include "Citizen.h"
#include "ResourceManager.h"

class Stonecutter : public Citizen {
private:
    ResourceManager* resourceManager;
    int const stoneProduction;
    int const foodConsumption;

public:
    Stonecutter(int happinessLevel = 0, int age = 0, int healthLevel = 0, ResourceManager* resourceManager = nullptr, int stoneProduction = 5, int foodConsumption = 1);
    
    void work() override;
    void consume() override;
};