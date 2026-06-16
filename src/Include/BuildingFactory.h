#pragma once

class BuildingManager;
class City;
class ResourceManager;

class BuildingFactory {
public:
    static void createStartingBuildings(BuildingManager& buildingManager, City& city, ResourceManager& resourceManager);
};