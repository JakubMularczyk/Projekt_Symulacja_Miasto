#pragma once
#include <vector>
#include <memory>

class Building;
class ResourceManager;

class BuildingManager {
private:
    std::vector<std::unique_ptr<Building>> buildings;

public:
    void addBuilding(std::unique_ptr<Building> building);
    void operateAll();
    void handleExpansion(int currentTurn, ResourceManager& resourceManager);
};
