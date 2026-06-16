#include "Quarry.h"
#include <iostream>

Quarry::Quarry(ResourceManager* resourceManager, int stoneProduction)
    : Building(100), resourceManager(resourceManager), stoneProduction(stoneProduction) {
    constructionCost[ResourceType::WOOD] = 15;
    constructionCost[ResourceType::STONE] = 30;
}

void Quarry::operate() {
    if (isConstructed && resourceManager) {
        resourceManager->addResource(ResourceType::STONE, stoneProduction);
    }
}

std::string Quarry::getName() const {
    return "Quarry";
}