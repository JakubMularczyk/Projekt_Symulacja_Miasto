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
    if (foodPerCitizen >= 25) {
        happinessLevel += 5;
    } else if (foodPerCitizen >= 12) {
        happinessLevel += 1;
    } else if (foodPerCitizen < 6) {
        happinessLevel -= 15;
    } else {
        happinessLevel -= 8;
    }

    if (goldPerCitizen >= 15) {
        happinessLevel += 5;
    } else if (goldPerCitizen >= 6) {
        happinessLevel += 1;
    } else {
        happinessLevel -= 8;
    }

    if (safety >= 70) {
        happinessLevel += 5;
    } else if (safety >= 40) {
        happinessLevel += 1;
    } else if (safety < 15) {
        happinessLevel -= 15;
    } else {
        happinessLevel -= 8;
    }

    happinessLevel = std::clamp(happinessLevel, 0, 100);
}
