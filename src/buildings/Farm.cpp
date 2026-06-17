#include "Farm.h"
#include <iostream>

Farm::Farm(ResourceManager* resourceManager, int foodProduction)
    : Building(100), resourceManager(resourceManager), foodProduction(foodProduction) {
    constructionCost[ResourceType::WOOD] = 20;
    constructionCost[ResourceType::STONE] = 10;
}

void Farm::operate() {
    if (isConstructed && resourceManager) {
        resourceManager->addResource(ResourceType::FOOD, foodProduction);
    }
}

std::string Farm::getName() const {
    return "Farm";
}
