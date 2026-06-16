#include "Guard.h"

Guard::Guard(int happinessLevel, int age, int healthLevel, City* city, ResourceManager* resourceManager, int safetyProduction, int foodConsumption)
    : Citizen(happinessLevel, age, healthLevel), city(city), resourceManager(resourceManager), safetyProduction(safetyProduction), foodConsumption(foodConsumption) {
}

void Guard::work() {
    int effectiveProduction = static_cast<int>(safetyProduction * getProductionMultiplier());
    if ((city->getSafety() + effectiveProduction) <= 100) {
        city->changeSafety(effectiveProduction);
    }
}

void Guard::consume() {
    resourceManager->consumeResource(ResourceType::FOOD, foodConsumption);
}
