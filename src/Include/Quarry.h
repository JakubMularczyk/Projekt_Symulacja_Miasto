#pragma once
#include "Building.h"

class ResourceManager;

class Quarry : public Building {
private:
    int stoneProduction;
    ResourceManager* resourceManager;

public:
    Quarry(int stoneProduction, ResourceManager* resourceManager);
    void operate() override;
    std::string getName() const override;
};
