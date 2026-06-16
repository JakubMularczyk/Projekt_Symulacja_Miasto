#pragma once
#include "Building.h"

class ResourceManager;

class Marketplace : public Building {
private:
    int goldProduction;
    ResourceManager* resourceManager;

public:
    Marketplace(int goldProduction, ResourceManager* resourceManager);
    void operate() override;
    std::string getName() const override;
};
