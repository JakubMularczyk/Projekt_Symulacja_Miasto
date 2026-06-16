#include "Sawmill.h"
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/main
