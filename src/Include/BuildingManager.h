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
<<<<<<< HEAD
    void handleExpansion(int currentTurn, ResourceManager& resourceManager);
};
=======
    void buildAll(ResourceManager* resourceManager);
    int getBuildingCount() const;
};
>>>>>>> origin/main
