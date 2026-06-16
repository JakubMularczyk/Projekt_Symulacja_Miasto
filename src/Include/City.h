#pragma once

#include <vector>
#include <memory>
#include "Citizen.h"
#include "Building.h"
#include "ResourceManager.h"
#include "PopulationManager.h"
#include "BuildingManager.h"

class City {
private:
    int safety;
    int turnsWithoutFood;
    int turnsWithoutGold;
    int turnsWithoutSafety;

    PopulationManager populationManager;
    BuildingManager buildingManager;

public:
    City();

    int getSafety() const;
    void changeSafety(int amount);

    void updateTurnsToCollapse(const ResourceManager& resourceManager);
    bool checkCollapseConditions();

    PopulationManager& getPopulationManager();
    const PopulationManager& getPopulationManager() const;

    BuildingManager& getBuildingManager();
    const BuildingManager& getBuildingManager() const;
};
