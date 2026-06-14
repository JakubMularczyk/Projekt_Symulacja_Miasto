#include "PopulationFactory.h"
#include "PopulationManager.h"
#include "Farmer.h"
#include "Merchant.h"
#include "Guard.h"
#include "Woodcutter.h"
#include "Stonecutter.h"

#define HAPPINESS_LEVEL 40
#define AGE 30
#define HEALTH_LEVEL 100

#define FARMER_PRODUCTION 10
#define FARMER_CONSUMPTION 2

#define MERCHANT_PROD_LOW 2
#define MERCHANT_PROD_HIGH 6

#define WOODCUTTER_PRODUCTION 6
#define STONECUTTER_PRODUCTION 6

#define GUARD_PRODUCTION 10
#define GUARD_CONSUMPTION 1


void PopulationFactory::createStartingPopulation(PopulationManager& populationManager, City& city, ResourceManager& resourceManager) {
	city.getPopulationManager().addCitizen(std::make_unique<Farmer>(HAPPINESS_LEVEL, AGE, HEALTH_LEVEL, &resourceManager, FARMER_PRODUCTION, FARMER_CONSUMPTION));
	city.getPopulationManager().addCitizen(std::make_unique<Farmer>(HAPPINESS_LEVEL, AGE, HEALTH_LEVEL, &resourceManager, FARMER_PRODUCTION, FARMER_CONSUMPTION));
	city.getPopulationManager().addCitizen(std::make_unique<Farmer>(HAPPINESS_LEVEL, AGE, HEALTH_LEVEL, &resourceManager, FARMER_PRODUCTION, FARMER_CONSUMPTION));
	city.getPopulationManager().addCitizen(std::make_unique<Farmer>(HAPPINESS_LEVEL, AGE, HEALTH_LEVEL, &resourceManager, FARMER_PRODUCTION, FARMER_CONSUMPTION));
	city.getPopulationManager().addCitizen(std::make_unique<Farmer>(HAPPINESS_LEVEL, AGE, HEALTH_LEVEL, &resourceManager, FARMER_PRODUCTION, FARMER_CONSUMPTION));

	city.getPopulationManager().addCitizen(std::make_unique<Merchant>(HAPPINESS_LEVEL, AGE, HEALTH_LEVEL, &resourceManager, MERCHANT_PROD_LOW));
	city.getPopulationManager().addCitizen(std::make_unique<Merchant>(HAPPINESS_LEVEL, AGE, HEALTH_LEVEL, &resourceManager, MERCHANT_PROD_HIGH));

	city.getPopulationManager().addCitizen(std::make_unique<Woodcutter>(HAPPINESS_LEVEL, AGE, HEALTH_LEVEL, &resourceManager, WOODCUTTER_PRODUCTION));
	city.getPopulationManager().addCitizen(std::make_unique<Stonecutter>(HAPPINESS_LEVEL, AGE, HEALTH_LEVEL, &resourceManager, STONECUTTER_PRODUCTION));

	city.getPopulationManager().addCitizen(std::make_unique<Guard>(HAPPINESS_LEVEL, AGE, HEALTH_LEVEL, &city, &resourceManager, GUARD_PRODUCTION, GUARD_CONSUMPTION));

}