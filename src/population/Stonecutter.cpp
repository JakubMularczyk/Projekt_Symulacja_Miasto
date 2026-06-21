#include "Stonecutter.h"

Stonecutter::Stonecutter(int happinessLevel, ResourceManager* resourceManager, int stoneProduction, int foodConsumption)
    : Citizen(happinessLevel),
      resourceManager(resourceManager),
      stoneProduction(stoneProduction),
      foodConsumption(foodConsumption) {
}

void Stonecutter::work() {
    if (resourceManager) {
        resourceManager->addResource(ResourceType::STONE, scaledProduction(stoneProduction));
    }
}

void Stonecutter::consume() {
    if (resourceManager) {
        if (!resourceManager->consumeResource(ResourceType::FOOD, foodConsumption)) {
            happinessLevel -= 10;
        }
    }
}
