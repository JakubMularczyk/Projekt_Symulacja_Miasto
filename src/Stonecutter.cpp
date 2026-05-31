#include "Stonecutter.h"
#include <iostream>

Stonecutter::Stonecutter(int happinessLevel, int age, int healthLevel, ResourceManager* resourceManager, int stoneProduction, int foodConsumption)
    : Citizen(happinessLevel, age, healthLevel), 
      resourceManager(resourceManager), 
      stoneProduction(stoneProduction), 
      foodConsumption(foodConsumption) {
}

void Stonecutter::work() {
    if (resourceManager) {
        resourceManager->addResource(ResourceType::STONE, stoneProduction);
    }
}

void Stonecutter::consume() {
    if (resourceManager) {
        if (resourceManager->consumeResource(ResourceType::FOOD, foodConsumption)) {
            
        } else {
            happinessLevel -= 10;
            healthLevel -= 5;
        }
    }
}