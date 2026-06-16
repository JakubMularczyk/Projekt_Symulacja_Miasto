#pragma once
#include "Building.h"
<<<<<<< HEAD

class ResourceManager;
=======
#include "ResourceManager.h"
>>>>>>> origin/main

class Sawmill : public Building {
private:
    int woodProduction;
    ResourceManager* resourceManager;
<<<<<<< HEAD

public:
    Sawmill(int woodProduction, ResourceManager* resourceManager);
    void operate() override;
    std::string getName() const override;
};
=======
public:
    Sawmill(ResourceManager* resourceManager = nullptr, int woodProduction = 10);
    void operate() override;
    std::string getName() const override;
};
>>>>>>> origin/main
