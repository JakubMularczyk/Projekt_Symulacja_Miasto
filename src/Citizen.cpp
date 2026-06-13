#include "Citizen.h"
#include "ResourceManager.h"
#include <iostream>

Citizen::Citizen(int happinessLevel, int age)
    : happinessLevel(happinessLevel), age(age) {
}

void Citizen::work() {}

void Citizen::consume() {}