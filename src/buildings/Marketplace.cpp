#include "Marketplace.h"
#include <iostream>

Marketplace::Marketplace(ResourceManager* resourceManager, int goldProduction)
    : Building(100), resourceManager(resourceManager), goldProduction(goldProduction) {
    constructionCost[ResourceType::WOOD] = 15;
    constructionCost[ResourceType::STONE] = 15;
}

void Marketplace::operate() {
    if (isConstructed && resourceManager) {
        resourceManager->addResource(ResourceType::GOLD, goldProduction);
    }
}

std::string Marketplace::getName() const {
    return "Marketplace";
}
