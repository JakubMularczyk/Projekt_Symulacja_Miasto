#pragma once
#include "Building.h"
<<<<<<< HEAD

class ResourceManager;
=======
#include "ResourceManager.h"
>>>>>>> origin/main

class Quarry : public Building {
private:
    int stoneProduction;
    ResourceManager* resourceManager;
<<<<<<< HEAD

public:
    Quarry(int stoneProduction, ResourceManager* resourceManager);
    void operate() override;
    std::string getName() const override;
};
=======
public:
    Quarry(ResourceManager* resourceManager = nullptr, int stoneProduction = 10);
    void operate() override;
    std::string getName() const override;
};
>>>>>>> origin/main
