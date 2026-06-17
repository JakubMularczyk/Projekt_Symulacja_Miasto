#include "Barracks.h"
#include "City.h"
#include <iostream>

Barracks::Barracks(City* city, int safetyBonus)
    : Building(150), city(city), safetyBonus(safetyBonus) {
    constructionCost[ResourceType::WOOD] = 20;
    constructionCost[ResourceType::STONE] = 20;
}

void Barracks::operate() {
    if (isConstructed && city) {
        city->changeSafety(safetyBonus);
    }
}

std::string Barracks::getName() const {
    return "Barracks";
}
