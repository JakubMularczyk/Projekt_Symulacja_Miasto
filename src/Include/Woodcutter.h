#pragma once
#include "Citizen.h"
#include "ResourceManager.h"

class Woodcutter : public Citizen {
private:
    ResourceManager* resourceManager;
    int const woodProduction;
    int const foodConsumption;

public:
    Woodcutter(int happinessLevel = 0, ResourceManager* resourceManager = nullptr, int woodProduction = 10, int foodConsumption = 1);
    
    void work() override;
    void consume() override;
};