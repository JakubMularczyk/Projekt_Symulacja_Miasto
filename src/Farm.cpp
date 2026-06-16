#include "Farm.h"
#include "ResourceManager.h"
#include <iostream>

Farm::Farm(ResourceManager* resourceManager, int foodProduction)
    : Building(100), foodProduction(foodProduction), resourceManager(resourceManager) {
    constructionCost[ResourceType::WOOD] = 10;
    constructionCost[ResourceType::STONE] = 5;
}

void Farm::operate() {
    resourceManager->addResource(ResourceType::FOOD, foodProduction);
    std::cout << "Farma produuje " << foodProduction << " jedzenia." << std::endl;
}

std::string Farm::getName() const {
    return "Farma";
}
