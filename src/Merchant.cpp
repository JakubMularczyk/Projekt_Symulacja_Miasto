#include "Merchant.h"

Merchant::Merchant(int happinessLevel, int age, ResourceManager* rm, int foodConsumption)
    : Citizen(happinessLevel, age), resourceManager(rm), foodConsumption(foodConsumption) {
}

void Merchant::work() {
    if (resourceManager->getResourceAmount(ResourceType::FOOD) > 50) {
        resourceManager->consumeResource(ResourceType::FOOD, 2);
        resourceManager->addResource(ResourceType::GOLD, 8);
    }
}

void Merchant::consume() {
    resourceManager->consumeResource(ResourceType::FOOD, foodConsumption);
}