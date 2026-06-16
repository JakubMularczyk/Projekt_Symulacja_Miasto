#include "Sawmill.h"
#include <iostream>

Sawmill::Sawmill(ResourceManager* resourceManager, int woodProduction)
    : Building(100), resourceManager(resourceManager), woodProduction(woodProduction) {
    constructionCost[ResourceType::WOOD] = 30;
    constructionCost[ResourceType::STONE] = 15;
}

void Sawmill::operate() {
    if (isConstructed && resourceManager) {
        resourceManager->addResource(ResourceType::WOOD, woodProduction);
    }
}

std::string Sawmill::getName() const {
    return "Sawmill";
}