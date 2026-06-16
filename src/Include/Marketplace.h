#pragma once
#include "Building.h"
<<<<<<< HEAD

class ResourceManager;
=======
#include "ResourceManager.h"
>>>>>>> origin/main

class Marketplace : public Building {
private:
    int goldProduction;
    ResourceManager* resourceManager;
<<<<<<< HEAD

public:
    Marketplace(int goldProduction, ResourceManager* resourceManager);
    void operate() override;
    std::string getName() const override;
};
=======
public:
    Marketplace(ResourceManager* resourceManager = nullptr, int goldProduction = 8);
    void operate() override;
    std::string getName() const override;
};
>>>>>>> origin/main
