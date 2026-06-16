#pragma once
#include "Building.h"
#include "ResourceManager.h"

class Quarry : public Building {
private:
    int stoneProduction;
    ResourceManager* resourceManager;

public:
    Quarry(ResourceManager* resourceManager = nullptr, int stoneProduction = 10);
    void operate() override;
    std::string getName() const override;
};
