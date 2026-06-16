#include "Farmer.h"

Farmer::Farmer(int happinessLevel, int age, int healthLevel, ResourceManager* resourceManager, int foodProduction, int foodConsumption)
    : Citizen(happinessLevel, age, healthLevel), resourceManager(resourceManager), foodProduction(foodProduction), foodConsumption(foodConsumption) {
}

void Farmer::work() {
    resourceManager->addResource(ResourceType::FOOD, scaledProduction(foodProduction));
}

void Farmer::consume() {
    resourceManager->consumeResource(ResourceType::FOOD, foodConsumption);
}
