#include "Farm.h"
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/main
