#pragma once
#include "Building.h"
<<<<<<< HEAD

class ResourceManager;
=======
#include "ResourceManager.h"
>>>>>>> origin/main

class Farm : public Building {
private:
    int foodProduction;
    ResourceManager* resourceManager;
<<<<<<< HEAD

public:
    Farm(ResourceManager* resourceManager, int foodProduction);
    void operate() override;
    std::string getName() const override;
};
=======
public:
    Farm(ResourceManager* resourceManager = nullptr, int foodProduction = 15);
    void operate() override;
    std::string getName() const override;
};
>>>>>>> origin/main
