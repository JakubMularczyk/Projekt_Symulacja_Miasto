#pragma once
#include <string>
#include <map>
#include "Resources.h"
#include "ResourceManager.h"

class Building {
protected:
    int durability;
    int maxDurability;
    bool isConstructed;
    std::map<ResourceType, int> constructionCost;

public:
    Building(int maxDurability);
    virtual ~Building() = default;

    virtual bool build(ResourceManager* resourceManager);
    virtual void takeDamage(int amount);
    virtual void operate() = 0;

    virtual std::string getName() const = 0;
    int getDurability() const;
    bool getIsConstructed() const;

    void handleExpansion(int currentTurn, ResourceManager& resourceManager); //nowy budynek
<<<<<<< HEAD
};
=======
};
>>>>>>> origin/main
