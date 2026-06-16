#include "Barracks.h"
#include "City.h"
#include <iostream>

Barracks::Barracks(int safetyBonus, City* city)
    : Building(150), safetyBonus(safetyBonus), city(city) {
    constructionCost[ResourceType::WOOD] = 20;
    constructionCost[ResourceType::STONE] = 20;
}

void Barracks::operate() {
    city->changeSafety(safetyBonus);
    std::cout << "Koszary zwiększają bezpieczeństwo o " << safetyBonus << "." << std::endl;
}

std::string Barracks::getName() const {
    return "Koszary";
}
