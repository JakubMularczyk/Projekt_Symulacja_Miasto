#include "Stonecutter.h"

Stonecutter::Stonecutter(int happinessLevel, int age, int healthLevel, ResourceManager* resourceManager, int stoneProduction, int foodConsumption)
    : Citizen(happinessLevel, age, healthLevel),
      resourceManager(resourceManager),
      stoneProduction(stoneProduction),
      foodConsumption(foodConsumption) {
}

void Stonecutter::work() {
    if (resourceManager) {
        int effectiveProduction = static_cast<int>(stoneProduction * getProductionMultiplier());
        resourceManager->addResource(ResourceType::STONE, effectiveProduction);
    }
}

void Stonecutter::consume() {
    if (resourceManager) {
        if (!resourceManager->consumeResource(ResourceType::FOOD, foodConsumption)) {
            happinessLevel -= 10;
            healthLevel -= 5;
        }
    }
}
