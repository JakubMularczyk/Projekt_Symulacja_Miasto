#pragma once
#include "Building.h"
#include "ResourceManager.h"

class Sawmill : public Building {
private:
    int woodProduction;
    ResourceManager* resourceManager;

public:
    Sawmill(ResourceManager* resourceManager = nullptr, int woodProduction = 10);
    void operate() override;
    std::string getName() const override;
};
