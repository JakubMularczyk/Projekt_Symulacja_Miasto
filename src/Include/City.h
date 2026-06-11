#pragma once

#include <vector>
#include <memory>
#include "Citizen.h"
#include "Building.h"
#include "ResourceManager.h" 

class City {
private:
    int safety;
    int turnsWithoutFood;
    int turnsWithoutGold;
    int turnsWithoutSafety;
    std::vector<std::unique_ptr<Citizen>> citizens;
    std::vector<std::unique_ptr<Building>> buildings;

public:
    City();

    int getSafety() const;
    void changeSafety(int amount);

    void updateTurnsToCollapse(const ResourceManager& resourceManager);
    bool checkCollapseConditions();

    void addCitizen(std::unique_ptr<Citizen> citizen);
    void executeCitizenActions();
    void addBuilding(std::unique_ptr<Building> building);
};
