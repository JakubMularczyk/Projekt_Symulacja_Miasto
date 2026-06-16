#include "Quarry.h"
#include "ResourceManager.h"
#include <iostream>

Quarry::Quarry(int stoneProduction, ResourceManager* resourceManager)
    : Building(120), stoneProduction(stoneProduction), resourceManager(resourceManager) {
    constructionCost[ResourceType::WOOD] = 15;
    constructionCost[ResourceType::STONE] = 5;
}

void Quarry::operate() {
    resourceManager->addResource(ResourceType::STONE, stoneProduction);
    std::cout << "Kamieniołom produkuje " << stoneProduction << " kamienia." << std::endl;
}

std::string Quarry::getName() const {
    return "Kamieniołom";
}
