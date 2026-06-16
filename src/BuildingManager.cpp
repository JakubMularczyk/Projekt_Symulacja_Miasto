#include "BuildingManager.h"
#include "Building.h"
#include "ResourceManager.h"

void BuildingManager::addBuilding(std::unique_ptr<Building> building) {
    buildings.push_back(std::move(building));
}

void BuildingManager::operateAll() {
    for (auto& building : buildings) {
        if (building->getIsConstructed()) {
            building->operate();
        }
    }
}

void BuildingManager::buildAll(ResourceManager* resourceManager) {
    for (auto& building : buildings) {
        building->build(resourceManager);
    }
}

int BuildingManager::getBuildingCount() const {
    return buildings.size();
}