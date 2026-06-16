#include "BuildingFactory.h"
#include "BuildingManager.h"
#include "Farm.h"
#include "Sawmill.h"
#include "Quarry.h"
#include "Barracks.h"
#include "Marketplace.h"

#define FARM_PRODUCTION 15
#define SAWMILL_PRODUCTION 10
#define QUARRY_PRODUCTION 10
#define BARRACKS_SAFETY 10
#define MARKETPLACE_GOLD 8

void BuildingFactory::createStartingBuildings(BuildingManager& buildingManager, City& city, ResourceManager& resourceManager) {
    auto farm = std::make_unique<Farm>(&resourceManager, FARM_PRODUCTION);
    farm->build(&resourceManager);
    buildingManager.addBuilding(std::move(farm));

    auto sawmill = std::make_unique<Sawmill>(&resourceManager, SAWMILL_PRODUCTION);
    sawmill->build(&resourceManager);
    buildingManager.addBuilding(std::move(sawmill));

    auto quarry = std::make_unique<Quarry>(&resourceManager, QUARRY_PRODUCTION);
    quarry->build(&resourceManager);
    buildingManager.addBuilding(std::move(quarry));

    auto barracks = std::make_unique<Barracks>(&city, BARRACKS_SAFETY);
    barracks->build(&resourceManager);
    buildingManager.addBuilding(std::move(barracks));

    auto marketplace = std::make_unique<Marketplace>(&resourceManager, MARKETPLACE_GOLD);
    marketplace->build(&resourceManager);
    buildingManager.addBuilding(std::move(marketplace));
}