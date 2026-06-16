#pragma once
#include "Building.h"
#include "ResourceManager.h"

class Marketplace : public Building {
private:
    int goldProduction;
    ResourceManager* resourceManager;

public:
    Marketplace(ResourceManager* resourceManager = nullptr, int goldProduction = 8);
    void operate() override;
    std::string getName() const override;
};
