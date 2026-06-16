#pragma once
#include "Building.h"

class ResourceManager;

class Farm : public Building {
private:
    int foodProduction;
    ResourceManager* resourceManager;

public:
    Farm(ResourceManager* resourceManager, int foodProduction);
    void operate() override;
    std::string getName() const override;
};
