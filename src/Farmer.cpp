#include "Farmer.h"

Farmer::Farmer(int happinessLevel, int age, ResourceManager* resourceManager, int foodProduction, int foodConsumption)
    : Citizen(happinessLevel, age), resourceManager(resourceManager), foodProduction(foodProduction), foodConsumption(foodConsumption) {
}

void Farmer::work() {
    resourceManager->addResource(ResourceType::FOOD, foodProduction);
}

void Farmer::consume() {
    bool ateSuccessfully = resourceManager->consumeResource(ResourceType::FOOD, foodConsumption);

    if (ateSuccessfully) {
        happinessLevel += 5;

        if (happinessLevel > 100) {
            happinessLevel = 100;
        }
    }
    else {
        happinessLevel -= 10;

        if (happinessLevel < 0) {
            happinessLevel = 0;
        }
    }
}