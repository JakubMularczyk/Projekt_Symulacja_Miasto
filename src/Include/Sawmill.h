#pragma once
#include "Building.h"

class ResourceManager;

class Sawmill : public Building {
private:
    int woodProduction;
    ResourceManager* resourceManager;

public:
    Sawmill(int woodProduction, ResourceManager* resourceManager);
    void operate() override;
    std::string getName() const override;
};
