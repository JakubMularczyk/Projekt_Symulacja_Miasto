#pragma once
#include "Citizen.h"

class Farmer : public Citizen {
private:
    int const foodProduction;

public:
    Farmer(int happinessLevel = 100, int age = 0, int healthLevel = 100, ResourceManager* resourceManager = nullptr, int foodProduction = 10);
    
    void work() override;
};