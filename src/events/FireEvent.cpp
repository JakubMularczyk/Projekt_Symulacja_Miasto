#include "FireEvent.h"
#include "City.h"
#include <iostream>
#include "ResourceManager.h"
#include "Resources.h"
#include "Logger.h"
#include <cmath>

FireEvent::FireEvent()
	:RandomEvent(30, "Fire is destroying the city!!!!", "Fire") {

}

void FireEvent::execute(City& city, ResourceManager& resourceManager) {
	const double woodLossRatio = 0.3;
	const int safetyLoss = 25;
	
	std::cout << "Random Event: " << getName() << " --->" << getDescription() << std::endl;

	if (resourceManager.getResourceAmount(ResourceType::WOOD) < 50) {
		int woodLoss = resourceManager.getResourceAmount(ResourceType::WOOD);
		resourceManager.consumeResource(ResourceType::WOOD,woodLoss);
		logMessage("[RANDOMEVENT] Fire destroyed " + std::to_string(woodLoss) + " WOOD.");
	}
	else
	{
		int woodLoss = std::round(resourceManager.getResourceAmount(ResourceType::WOOD) * woodLossRatio);
		resourceManager.consumeResource(ResourceType::WOOD, woodLoss);
		logMessage("[RANDOMEVENT] Fire destroyed " + std::to_string(woodLoss) + " WOOD.");
		
	}
	if (city.getSafety() < safetyLoss) {
		int safetyLossLower = city.getSafety();
		city.changeSafety(-safetyLossLower);
		logMessage("[EVENT] Safety decreased by " + std::to_string(safetyLossLower) + ".");

	}
	else
	{
		city.changeSafety(-safetyLoss);
		logMessage("[EVENT] Safety decreased by " + std::to_string(safetyLoss) + ".");
	}


};