#include "Marketplace.h"
#include "ResourceManager.h"
#include <iostream>

Marketplace::Marketplace(int goldProduction, ResourceManager* resourceManager)
    : Building(100), goldProduction(goldProduction), resourceManager(resourceManager) {
    constructionCost[ResourceType::WOOD] = 15;
    constructionCost[ResourceType::STONE] = 15;
}

void Marketplace::operate() {
    resourceManager->addResource(ResourceType::GOLD, goldProduction);
    std::cout << "Targowisko produkuje " << goldProduction << " złota." << std::endl;
}

std::string Marketplace::getName() const {
    return "Targowisko";
}
