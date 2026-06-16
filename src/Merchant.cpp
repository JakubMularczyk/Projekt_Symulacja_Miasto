#include "Merchant.h"

Merchant::Merchant(int happinessLevel, int age, int healthLevel, ResourceManager* resourceManager, int foodConsumption)
    : Citizen(happinessLevel, age, healthLevel), resourceManager(resourceManager), foodConsumption(foodConsumption) {
}

void Merchant::work() {
    if (resourceManager->getResourceAmount(ResourceType::FOOD) > 50) {
        int goldProduction = static_cast<int>(8 * getProductionMultiplier());
        resourceManager->consumeResource(ResourceType::FOOD, 2);
        resourceManager->addResource(ResourceType::GOLD, goldProduction);
    }
}

void Merchant::consume() {
    resourceManager->consumeResource(ResourceType::FOOD, foodConsumption);
}
