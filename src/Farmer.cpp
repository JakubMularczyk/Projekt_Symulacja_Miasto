#include "Farmer.h"

Farmer::Farmer(int happinessLevel, int age, int healthLevel, ResourceManager* resourceManager, int foodProduction)
    : Citizen(happinessLevel, age, healthLevel, resourceManager), foodProduction(foodProduction) {
}

void Farmer::work() {
    if (!resourceManager) return;

    float happinessModifier = happinessLevel / 100.0f;

    int actualProduction = static_cast<int>(foodProduction * happinessModifier);

    if (actualProduction < 1 && happinessLevel > 0) {
        actualProduction = 1;
    }

    resourceManager->addResource(ResourceType::FOOD, actualProduction);
}