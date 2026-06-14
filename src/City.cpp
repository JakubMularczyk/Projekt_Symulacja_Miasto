#include "City.h"
#include <utility>

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
    if (turnsWithoutFood >= 3 || turnsWithoutGold >= 3 || turnsWithoutSafety >= 3) {
        return true;
    }
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
