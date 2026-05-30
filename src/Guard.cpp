#include "Guard.h"

Guard::Guard(int happinessLevel, int age, int healthLevel, City* city, ResourceManager* resourceManager, int safetyProduction, int foodConsumption)
    : Citizen(happinessLevel, age, healthLevel), city(city), resourceManager(resourceManager), safetyProduction(safetyProduction), foodConsumption(foodConsumption) {
}

void Guard::work() {
    if ((city->getSafety() + safetyProduction) <= 100) {
        city->changeSafety(safetyProduction);
    }
}

void Guard::consume() {
    resourceManager->consumeResource(ResourceType::FOOD, foodConsumption);
}