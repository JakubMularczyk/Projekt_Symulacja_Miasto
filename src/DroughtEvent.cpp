#include "DroughtEvent.h"
#include "City.h"
#include <iostream>
#include "ResourceManager.h"
#include "Resources.h"
#include "Logger.h"
#include <cmath>

DroughtEvent::DroughtEvent()
	:RandomEvent(30, "Drought destroys food crops!!!!", "Drought") {

}

void DroughtEvent::execute(City& city, ResourceManager& resourceManager) {
	const double foodLossRatio = 0.5;
	

	std::cout << "Random Event: " << getName() << " --->" << getDescription() << std::endl;

	if (resourceManager.getResourceAmount(ResourceType::FOOD) < 50) {
		int foodLoss = resourceManager.getResourceAmount(ResourceType::FOOD);
		resourceManager.consumeResource(ResourceType::FOOD, foodLoss);
		logMessage("[RANDOMEVENT] Drought destroyed " + std::to_string(foodLoss) + " FOOD.");
	}
	else
	{
		int foodLoss = std::round(resourceManager.getResourceAmount(ResourceType::FOOD) * foodLossRatio);
		resourceManager.consumeResource(ResourceType::FOOD, foodLoss);
		logMessage("[RANDOMEVENT] Drought destroyed " + std::to_string(foodLoss) + " FOOD.");

	}

};