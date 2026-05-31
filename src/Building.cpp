#include "Building.h"
#include <iostream>

Building::Building(std::string name, int maxDurability)
    : name(name), maxDurability(maxDurability), durability(0), isConstructed(false) {
}

bool Building::build(ResourceManager* resourceManager) {
    if (isConstructed) return true;

    if (!resourceManager) return false;

    for (const auto& cost : constructionCost) {
        if (resourceManager->getResourceAmount(cost.first) < cost.second) {
            std::cout << "Brakuje surowcow do budowy: " << name << std::endl;
            return false;
        }
    }

    for (const auto& cost : constructionCost) {
        resourceManager->consumeResource(cost.first, cost.second);
    }

    durability = maxDurability;
    isConstructed = true;
    std::cout << "Zbudowano: " << name << std::endl;
    return true;
}

void Building::takeDamage(int amount) {
    if (amount > 0) {
        durability -= amount;
        if (durability <= 0) {
            durability = 0;
            isConstructed = false;
            std::cout << name << " zostal zniszczony!" << std::endl;
        }
    }
}

std::string Building::getName() const {
    return name;
}

int Building::getDurability() const {
    return durability;
}

bool Building::getIsConstructed() const {
    return isConstructed;
}