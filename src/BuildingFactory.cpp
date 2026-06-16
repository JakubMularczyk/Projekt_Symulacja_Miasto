#include "BuildingFactory.h"
#include "City.h"
#include "Farm.h"
#include "Sawmill.h"
#include "Quarry.h"
#include "Barracks.h"
#include "Marketplace.h"

#define FARM_FOOD_PRODUCTION 15
#define SAWMILL_WOOD_PRODUCTION 10
#define QUARRY_STONE_PRODUCTION 10
#define BARRACKS_SAFETY_BONUS 10
#define MARKETPLACE_GOLD_PRODUCTION 8

void BuildingFactory::createStartingBuildings(City& city, ResourceManager& resourceManager) {
    city.getBuildingManager().addBuilding(std::make_unique<Farm>(&resourceManager, FARM_FOOD_PRODUCTION));
    city.getBuildingManager().addBuilding(std::make_unique<Sawmill>(SAWMILL_WOOD_PRODUCTION, &resourceManager));
    city.getBuildingManager().addBuilding(std::make_unique<Quarry>(QUARRY_STONE_PRODUCTION, &resourceManager));
    city.getBuildingManager().addBuilding(std::make_unique<Barracks>(BARRACKS_SAFETY_BONUS, &city));
    city.getBuildingManager().addBuilding(std::make_unique<Marketplace>(MARKETPLACE_GOLD_PRODUCTION, &resourceManager));
}
