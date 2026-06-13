#include "Citizen.h"
#include <iostream>

Citizen::Citizen(int happinessLevel, int age, int healthLevel, ResourceManager* rm)
    : happinessLevel(happinessLevel), age(age), healthLevel(healthLevel), resourceManager(rm) {
}

void Citizen::work() {}

void Citizen::consume() {
    if (!resourceManager) return;

    int availableFood = resourceManager->getResourceAmount(ResourceType::FOOD);
    int availableGold = resourceManager->getResourceAmount(ResourceType::GOLD);

    int highFoodThreshold = 100;
    int lowFoodThreshold = 40;

    if (availableFood > highFoodThreshold) {
        resourceManager->consumeResource(ResourceType::FOOD, 2);

        if (availableGold > 50) {
            happinessLevel += 5;
        }
        else {
            happinessLevel += 2;
        }
    }
    else if (availableFood > lowFoodThreshold) {
        resourceManager->consumeResource(ResourceType::FOOD, 1);
    }
    else {
        happinessLevel -= 10;
    }

    if (happinessLevel > 100) happinessLevel = 100;
    if (happinessLevel < 0) happinessLevel = 0;
}