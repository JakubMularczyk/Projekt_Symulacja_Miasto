#include "ResourceManager.h"
#include "Resources.h"
#include "Logger.h"
#include "City.h"
#include "PlagueEvent.h"
#include <cmath>
#include <iostream>

PlagueEvent::PlagueEvent()
	:RandomEvent(30, "Plague infects the city!!!!", "Plague") {

}

void PlagueEvent::execute(City& city, ResourceManager& resourceManager) {



	std::cout << "Random Event: " << getName() << " --->" << getDescription() << std::endl;
	const int safetyLoss = 20;
	const double foodLossRatio = 0.3;

	if (city.getSafety() < safetyLoss) {
		city.changeSafety(-city.getSafety());
	} else {
		city.changeSafety(-safetyLoss);
	}
	logMessage("[RANDOMEVENT] Plague decreased safety by " + std::to_string(safetyLoss) + ".");

	int foodLoss = std::round(resourceManager.getResourceAmount(ResourceType::FOOD) * foodLossRatio);
	resourceManager.consumeResource(ResourceType::FOOD, foodLoss);
	logMessage("[RANDOMEVENT] Plague destroyed " + std::to_string(foodLoss) + " FOOD.");


};