#include "Woodcutter.h"

Woodcutter::Woodcutter(int happinessLevel, int age, int healthLevel, ResourceManager* resourceManager, int woodProduction, int foodConsumption)
    : Citizen(happinessLevel, age, healthLevel),
      resourceManager(resourceManager),
      woodProduction(woodProduction),
      foodConsumption(foodConsumption) {
}

void Woodcutter::work() {
    if (resourceManager) {
        int effectiveProduction = static_cast<int>(woodProduction * getProductionMultiplier());
        resourceManager->addResource(ResourceType::WOOD, effectiveProduction);
    }
}

void Woodcutter::consume() {
    if (resourceManager) {
        if (!resourceManager->consumeResource(ResourceType::FOOD, foodConsumption)) {
            happinessLevel -= 10;
        }
    }
}
