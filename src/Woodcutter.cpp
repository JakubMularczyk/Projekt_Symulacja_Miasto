#include "Woodcutter.h"
#include <iostream>

Woodcutter::Woodcutter(int happinessLevel, int age, int healthLevel, ResourceManager* resourceManager, int woodProduction, int foodConsumption)
    : Citizen(happinessLevel, age, healthLevel),
      resourceManager(resourceManager),
      woodProduction(woodProduction),
      foodConsumption(foodConsumption) {
}

void Woodcutter::work() {
    if (resourceManager) {
        resourceManager->addResource(ResourceType::WOOD, scaledProduction(woodProduction));
    }
}

void Woodcutter::consume() {
    if (resourceManager) {
        if (!resourceManager->consumeResource(ResourceType::FOOD, foodConsumption)) {
            happinessLevel -= 10;
        }
    }
}