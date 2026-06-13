#include "Guard.h"

Guard::Guard(int happinessLevel, int age, ResourceManager* rm, int foodConsumption, int safetyProduction, City* city)
    : Citizen(happinessLevel, age), resourceManager(rm), foodConsumption(foodConsumption),
    safetyProduction(safetyProduction), city(city) { // city jest teraz poprawnie zainicjowane
}

void Guard::work() {
    if ((city->getSafety() + safetyProduction) <= 100) {
        city->changeSafety(safetyProduction);
    }
}

void Guard::consume() {
    resourceManager->consumeResource(ResourceType::FOOD, foodConsumption);
}