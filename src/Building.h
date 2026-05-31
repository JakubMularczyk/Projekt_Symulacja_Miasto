#pragma once
#include <string>
#include <map>
#include "Resources.h"
#include "ResourceManager.h"

class Building {
protected:
    std::string name;
    int durability;
    int maxDurability;
    bool isConstructed;
    std::map<ResourceType, int> constructionCost;

public:
    Building(std::string name, int maxDurability);
    virtual ~Building() = default;

    virtual bool build(ResourceManager* resourceManager);
    virtual void takeDamage(int amount);
    virtual void operate() = 0;

    std::string getName() const;
    int getDurability() const;
    bool getIsConstructed() const;
};