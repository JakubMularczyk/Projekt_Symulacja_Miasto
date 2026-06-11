#pragma once
#include "Citizen.h"
#include "ResourceManager.h"

class Merchant : public Citizen {
private:
    ResourceManager* resourceManager;
    int const foodConsumption;

public:
    Merchant(int happinessLevel = 0, int age = 0, int healthLevel = 0, ResourceManager* resourceManager = nullptr, int foodConsumption = 1);
    void work() override;
    void consume() override;
};