#pragma once

class City;
class ResourceManager;

class BuildingFactory {
public:
    static void createStartingBuildings(City& city, ResourceManager& resourceManager);
};
