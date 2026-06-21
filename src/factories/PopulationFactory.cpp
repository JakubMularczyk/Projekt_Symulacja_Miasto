#include "PopulationFactory.h"
#include "PopulationManager.h"
#include "Farmer.h"
#include "Merchant.h"
#include "Guard.h"
#include "Woodcutter.h"
#include "Stonecutter.h"

#define HAPPINESS_LEVEL 40

#define FARMER_PRODUCTION 10
#define FARMER_CONSUMPTION 1

#define MERCHANT_PROD_LOW 2
#define MERCHANT_PROD_HIGH 2

#define WOODCUTTER_PRODUCTION 6
#define STONECUTTER_PRODUCTION 6

#define GUARD_PRODUCTION 5
#define GUARD_CONSUMPTION 1


void PopulationFactory::createStartingPopulation(City& city, ResourceManager& resourceManager) {
	//Farmers
	city.getPopulationManager().addCitizen(std::make_unique<Farmer>(HAPPINESS_LEVEL, &resourceManager, FARMER_PRODUCTION, FARMER_CONSUMPTION));
	city.getPopulationManager().addCitizen(std::make_unique<Farmer>(HAPPINESS_LEVEL, &resourceManager, FARMER_PRODUCTION, FARMER_CONSUMPTION));
	city.getPopulationManager().addCitizen(std::make_unique<Farmer>(HAPPINESS_LEVEL, &resourceManager, FARMER_PRODUCTION, FARMER_CONSUMPTION));
	city.getPopulationManager().addCitizen(std::make_unique<Farmer>(HAPPINESS_LEVEL, &resourceManager, FARMER_PRODUCTION, FARMER_CONSUMPTION));
	city.getPopulationManager().addCitizen(std::make_unique<Farmer>(HAPPINESS_LEVEL, &resourceManager, FARMER_PRODUCTION, FARMER_CONSUMPTION));
	//Merchant
	city.getPopulationManager().addCitizen(std::make_unique<Merchant>(HAPPINESS_LEVEL, &resourceManager, MERCHANT_PROD_LOW));
	city.getPopulationManager().addCitizen(std::make_unique<Merchant>(HAPPINESS_LEVEL, &resourceManager, MERCHANT_PROD_HIGH));
	//Woodcutters
	city.getPopulationManager().addCitizen(std::make_unique<Woodcutter>(HAPPINESS_LEVEL, &resourceManager, WOODCUTTER_PRODUCTION));
	//Stonecutters
	city.getPopulationManager().addCitizen(std::make_unique<Stonecutter>(HAPPINESS_LEVEL, &resourceManager, STONECUTTER_PRODUCTION));
	//Guards
	city.getPopulationManager().addCitizen(std::make_unique<Guard>(HAPPINESS_LEVEL, &city, &resourceManager, GUARD_PRODUCTION, GUARD_CONSUMPTION));
	city.getPopulationManager().addCitizen(std::make_unique<Guard>(HAPPINESS_LEVEL, &city, &resourceManager, GUARD_PRODUCTION, GUARD_CONSUMPTION));


}