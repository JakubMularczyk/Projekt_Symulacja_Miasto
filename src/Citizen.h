#pragma once
#include "ResourceManager.h"
class Citizen {
protected:
    int happinessLevel;
    int age;
    int healthLevel;
    ResourceManager* resourceManager;

public:
    Citizen(int happinessLevel = 100, int age = 0, int healthLevel = 100, ResourceManager* rm = nullptr);

    virtual ~Citizen() = default;

    virtual void work() = 0;
    virtual void consume();
};