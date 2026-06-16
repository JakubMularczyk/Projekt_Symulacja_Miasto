#include "Barracks.h"
#include <iostream>

Barracks::Barracks(City* city, int safetyBonus)
    : Building(150), city(city), safetyBonus(safetyBonus) {
    constructionCost[ResourceType::WOOD] = 40;
    constructionCost[ResourceType::STONE] = 30;
}

void Barracks::operate() {
    if (isConstructed && city) {
        if ((city->getSafety() + safetyBonus) <= 100) {
            city->changeSafety(safetyBonus);
        }
    }
}

std::string Barracks::getName() const {
    return "Barracks";
}