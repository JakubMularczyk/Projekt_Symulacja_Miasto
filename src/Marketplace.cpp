#include "Marketplace.h"
#include <iostream>

Marketplace::Marketplace(ResourceManager* resourceManager, int goldProduction)
    : Building(120), resourceManager(resourceManager), goldProduction(goldProduction) {
    constructionCost[ResourceType::WOOD] = 25;
    constructionCost[ResourceType::STONE] = 20;
    constructionCost[ResourceType::GOLD] = 10;
}

void Marketplace::operate() {
    if (isConstructed && resourceManager) {
        resourceManager->addResource(ResourceType::GOLD, goldProduction);
    }
}

std::string Marketplace::getName() const {
    return "Marketplace";
}