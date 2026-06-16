#include "Citizen.h"
#include "ResourceManager.h"
#include <iostream>
#include <algorithm>

Citizen::Citizen(int happinessLevel, int age, int healthLevel)
    : happinessLevel(happinessLevel), age(age), healthLevel(healthLevel) {
}

void Citizen::work() {}
void Citizen::consume() {}

void Citizen::setHappiness(int value) {
    happinessLevel = std::clamp(value, 0, 100);
}

int Citizen::getHappiness() const {
    return happinessLevel;
}

float Citizen::getProductionMultiplier() const {
    return happinessLevel / 100.0f;
}

int Citizen::scaledProduction(int baseProduction) const {
    return baseProduction * happinessLevel / 100;
}

void Citizen::updateHappiness(int foodPerCitizen, int goldPerCitizen, int safety) {
    if (foodPerCitizen >= 20) {
        happinessLevel += 10;
    } else if (foodPerCitizen >= 10) {
        happinessLevel += 3;
    } else if (foodPerCitizen < 5) {
        happinessLevel -= 15;
    } else {
        happinessLevel -= 5;
    }

    if (goldPerCitizen >= 10) {
        happinessLevel += 8;
    } else if (goldPerCitizen >= 4) {
        happinessLevel += 2;
    } else {
        happinessLevel -= 4;
    }

    if (safety >= 60) {
        happinessLevel += 8;
    } else if (safety >= 30) {
        happinessLevel += 2;
    } else if (safety < 10) {
        happinessLevel -= 15;
    } else {
        happinessLevel -= 6;
    }

    happinessLevel = std::clamp(happinessLevel, 0, 100);
}
