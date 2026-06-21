#include "Farmer.h"

Farmer::Farmer(int happinessLevel, ResourceManager* resourceManager, int foodProduction, int foodConsumption)
    : Citizen(happinessLevel), resourceManager(resourceManager), foodProduction(foodProduction), foodConsumption(foodConsumption) {
}

void Farmer::work() {
    resourceManager->addResource(ResourceType::FOOD, scaledProduction(foodProduction));
}

void Farmer::consume() {
    resourceManager->consumeResource(ResourceType::FOOD, foodConsumption);
}
