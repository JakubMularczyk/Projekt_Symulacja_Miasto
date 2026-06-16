#include "Building.h"
#include <iostream>

Building::Building(int maxDurability)
    : maxDurability(maxDurability), durability(0), isConstructed(false) {
}

bool Building::build(ResourceManager* resourceManager) {
    if (isConstructed) return true;

    if (!resourceManager) return false;

    for (const auto& cost : constructionCost) {
        if (resourceManager->getResourceAmount(cost.first) < cost.second) {
            std::cout << "Brakuje surowcow do budowy: " << getName() << std::endl;
            return false;
        }
    }

    for (const auto& cost : constructionCost) {
        resourceManager->consumeResource(cost.first, cost.second);
    }

    durability = maxDurability;
    isConstructed = true;
    std::cout << "Zbudowano: " << getName() << std::endl;
    return true;
}

void Building::takeDamage(int amount) {
    if (amount > 0) {
        durability -= amount;
        if (durability <= 0) {
            durability = 0;
            isConstructed = false;
            std::cout << getName() << " zostal zniszczony!" << std::endl;
        }
    }
}

int Building::getDurability() const {
    return durability;
}

bool Building::getIsConstructed() const {
    return isConstructed;
}

}
