#include "Barracks.h"
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/main
