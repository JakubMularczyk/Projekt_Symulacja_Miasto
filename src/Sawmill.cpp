#include "Sawmill.h"
#include "ResourceManager.h"
#include <iostream>

Sawmill::Sawmill(int woodProduction, ResourceManager* resourceManager)
    : Building(100), woodProduction(woodProduction), resourceManager(resourceManager) {
    constructionCost[ResourceType::WOOD] = 5;
    constructionCost[ResourceType::STONE] = 10;
}

void Sawmill::operate() {
    resourceManager->addResource(ResourceType::WOOD, woodProduction);
    std::cout << "Tartak produkuje " << woodProduction << " drewna." << std::endl;
}

std::string Sawmill::getName() const {
    return "Tartak";
}
