#pragma once

#include <vector>
#include <memory>
#include "Citizen.h"
#include "ResourceManager.h"
#include "Building.h" 

class City {
private:
    ResourceManager resourceManager;
    int safety;
    int turnsWithoutFood;
    int turnsWithoutGold;
    int turnsWithoutSafety;
    
    std::vector<std::unique_ptr<Citizen>> citizens;
    std::vector<std::unique_ptr<Building>> buildings;

public:
    City();

    ResourceManager& getResourceManager();
    const ResourceManager& getResourceManager() const;
    int getSafety() const;

    void addCitizen(std::unique_ptr<Citizen> citizen);
    void executeCitizenActions();

    void addBuilding(std::unique_ptr<Building> building);

    void changeSafety(int amount);
    void updateTurnsToCollapse();
    bool checkCollapseConditions();
};
