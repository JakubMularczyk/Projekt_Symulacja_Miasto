#pragma once

#include <vector>
#include <memory>
#include "Citizen.h"
#include "ResourceManager.h"

class City {
private:
    ResourceManager resourceManager;
    int safety;
    int turnsWithoutFood;
    int turnsWithoutGold;
    int turnsWithoutSafety;
    std::vector<std::unique_ptr<Citizen>> citizens;

public:
    City();

    // Resources and Safety Getters
    ResourceManager& getResourceManager();
    const ResourceManager& getResourceManager() const;
    int getSafety() const;

    // Citizens Management
    void addCitizen(std::unique_ptr<Citizen> citizen);
    void executeCitizenActions();

    // Simulation State Updates
    void changeSafety(int amount);
    void updateTurnsToCollapse();
    bool checkCollapseConditions();
};