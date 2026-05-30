#include "City.h"
#include <utility>

City::City() :
    safety(10),
    turnsWithoutFood(0),
    turnsWithoutGold(0),
    turnsWithoutSafety(0) {
}

// Resources:
ResourceManager& City::getResourceManager() {
    return resourceManager;
}

const ResourceManager& City::getResourceManager() const {
    return resourceManager;
}

int City::getSafety() const {
    return safety;
}

void City::changeSafety(int amount) {
    safety += amount;
}

// Collapse:
void City::updateTurnsToCollapse() {
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

// Citizens:
void City::addCitizen(std::unique_ptr<Citizen> citizen) {
    citizens.push_back(std::move(citizen));
}

void City::executeCitizenActions() {
    for (auto& citizen : citizens) {
        citizen->work();
        citizen->consume();
    }
}