#include "BuildingManager.h"
#include "Farm.h"
#include "Barracks.h"
#include "Marketplace.h"
#include "Quarry.h"
#include "Sawmill.h"
#include <utility>
#include <iostream>
#include <cstdlib> 

void BuildingManager::addBuilding(std::unique_ptr<Building> building) {
    buildings.push_back(std::move(building));
}

void BuildingManager::operateAll() {
    for (auto& building : buildings) {
        building->operate();
    }
}

void BuildingManager::handleExpansion(int currentTurn, ResourceManager& resourceManager) {
    if (currentTurn > 0 && currentTurn % 10 == 0) {

        std::unique_ptr<Building> newBuilding = nullptr;
        std::string buildingName = "";

        int randomChoice = std::rand() % 5;

        switch (randomChoice) {
            case 0:
                newBuilding = std::make_unique<Farm>(&resourceManager, 15);
                buildingName = "Farm";
                break;
            case 1:
                newBuilding = std::make_unique<Barracks>(&resourceManager, 20);
                buildingName = "Barracks";
                break;
            case 2:
                newBuilding = std::make_unique<Marketplace>(&resourceManager, 25);
                buildingName = "Marketplace";
                break;
            case 3:
                newBuilding = std::make_unique<Quarry>(&resourceManager, 12);
                buildingName = "Quarry";
                break;
            case 4:
                newBuilding = std::make_unique<Sawmill>(&resourceManager, 12);
                buildingName = "Sawmill";
                break;
            default:
                newBuilding = std::make_unique<Farm>(&resourceManager, 15);
                buildingName = "Farm";
                break;
        }

        if (newBuilding && newBuilding->build(&resourceManager)) {
            addBuilding(std::move(newBuilding));

            std::cout << ">>> AUTOMATIC EXPANSION: Turn " << currentTurn
                      << ". Resources successfully invested. A new " << buildingName << " has been built! <<<" << std::endl;
        }
        else {
            std::cout << ">>> AUTOMATIC EXPANSION: Canceled in turn " << currentTurn
                      << " due to insufficient resources to build a " << buildingName << ". <<<" << std::endl;
        }
    }
}
