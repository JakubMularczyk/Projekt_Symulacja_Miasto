#include "City.h"
#include <utility>
#include <iostream> // Dodane do obslugi std::cout

City::City() :
    safety(10),
    turnsWithoutFood(0),
    turnsWithoutGold(0),
    turnsWithoutSafety(0) {
}

int City::getSafety() const {
    return safety;
}

void City::changeSafety(int amount) {
    safety += amount;
}

void City::updateTurnsToCollapse(const ResourceManager& resourceManager) {
    if (resourceManager.getResourceAmount(ResourceType::FOOD) <= 0) {
        turnsWithoutFood++;
    }
    else {
        turnsWithoutFood = 0;
    }

    if (resourceManager.getResourceAmount(ResourceType::GOLD) <= 0) {
        turnsWithoutGold++;
    }
    else {
        turnsWithoutGold = 0;
    }

    if (safety <= 0) {
        turnsWithoutSafety++;
    }
    else {
        turnsWithoutSafety = 0;
    }
}

bool City::checkCollapseConditions() {

    if (turnsWithoutFood >= 3) {
        std::cout << "\n======================================================\n";
        std::cout << " [KONIEC GRY] MIASTO UPADLO!\n";
        std::cout << " Przyczyna: Brak zywnosci przez 3 tury z rzedu.\n";
        std::cout << " Mieszkancy zmarli z glodu lub opuscili miasto w poszukiwaniu jedzenia.\n";
        std::cout << "======================================================\n";
        return true;
    }

    if (turnsWithoutGold >= 3) {
        std::cout << "\n======================================================\n";
        std::cout << " [KONIEC GRY] MIASTO UPADLO!\n";
        std::cout << " Przyczyna: Brak zlota przez 3 tury z rzedu.\n";
        std::cout << " Skarb miasta swieci pustkami, a gospodarka calkowicie runela.\n";
        std::cout << "======================================================\n";
        return true;
    }

    if (turnsWithoutSafety >= 3) {
        std::cout << "\n======================================================\n";
        std::cout << " [KONIEC GRY] MIASTO UPADLO!\n";
        std::cout << " Przyczyna: Brak bezpieczenstwa przez 3 tury z rzedu.\n";
        std::cout << " Miasto zostalo opanowane przez bandytow i ogarniete przez anarchie.\n";
        std::cout << "======================================================\n";
        return true;
    }

    // trwa dalej
    return false;
}

PopulationManager& City::getPopulationManager()
{
    return populationManager;
}

const PopulationManager& City::getPopulationManager() const
{
    return populationManager;
}

BuildingManager& City::getBuildingManager()
{
    return buildingManager;
}

const BuildingManager& City::getBuildingManager() const
{
    return buildingManager;
}
