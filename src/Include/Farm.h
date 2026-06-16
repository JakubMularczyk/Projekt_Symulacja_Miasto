#pragma once
#include "Building.h"
#include "ResourceManager.h"

class Farm : public Building {
private:
    int foodProduction;
    ResourceManager* resourceManager;

public:
    Farm(ResourceManager* resourceManager = nullptr, int foodProduction = 15);
    void operate() override;
    std::string getName() const override;
};
