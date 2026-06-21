#include "Guard.h"

Guard::Guard(int happinessLevel, City* city, ResourceManager* resourceManager, int safetyProduction, int foodConsumption)
    : Citizen(happinessLevel), city(city), resourceManager(resourceManager), safetyProduction(safetyProduction), foodConsumption(foodConsumption) {
}

void Guard::work() {
    int production = scaledProduction(safetyProduction);
    if ((city->getSafety() + production) <= 100) {
        city->changeSafety(production);
    }
}

void Guard::consume() {
    resourceManager->consumeResource(ResourceType::FOOD, foodConsumption);
}
