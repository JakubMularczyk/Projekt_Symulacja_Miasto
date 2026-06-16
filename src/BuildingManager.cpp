#include "BuildingManager.h"
#include "Farm.h" 
#include <utility>
#include <iostream>

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

        auto newFarm = std::make_unique<Farm>(&resourceManager, 15);
        
        if (newFarm->build(&resourceManager)) {
            
            addBuilding(std::move(newFarm));
            
            std::cout << ">>> AUTOMATIC EXPANSION: Turn " << currentTurn 
                      << ". Resources successfully invested. A new Farm has been built! <<<" << std::endl;
        } 
        else {
            std::cout << ">>> AUTOMATIC EXPANSION: Canceled in turn " << currentTurn 
                      << " due to insufficient resources in the warehouse. <<<" << std::endl;
        }
    }
}
