#pragma once
#include "Citizen.h"
#include "ResourceManager.h"

class Merchant : public Citizen {
private:
    ResourceManager* resourceManager;
    int const foodConsumption;

public:
    Merchant(int happinessLevel, int age, ResourceManager* rm, int foodConsumption);
    void work() override;
    void consume() override;
};