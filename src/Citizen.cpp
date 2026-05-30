#include "Citizen.h"
#include "ResourceManager.h"
#include <iostream>

Citizen::Citizen(int happinessLevel, int age, int healthLevel)
    : happinessLevel(happinessLevel), age(age), healthLevel(healthLevel) {
}

void Citizen::work() {}

void Citizen::consume() {}