#include "BanditAttackEvent.h"
#include "City.h"
#include <iostream>
#include "ResourceManager.h"
#include "Resources.h"
#include "Logger.h"
#include <cmath>

BanditAttackEvent::BanditAttackEvent()
	:RandomEvent(30, "Bandits are attacking the city!!!!", "Bandits Attack") {

}

void BanditAttackEvent::execute(City& city, ResourceManager& resourceManager) {
	const double goldLossRatio = 0.5;
	const int safetyLoss = 25;

	std::cout << "Random Event: " << getName() << " --->" << getDescription() << std::endl;

	if (resourceManager.getResourceAmount(ResourceType::GOLD) < 50) {
		int goldLoss = resourceManager.getResourceAmount(ResourceType::GOLD);
		resourceManager.consumeResource(ResourceType::GOLD, goldLoss);
		logMessage("[RANDOMEVENT] Bandits has stolen " + std::to_string(goldLoss) + " gold.");
	}
	else
	{
		int goldLoss = std::round(resourceManager.getResourceAmount(ResourceType::GOLD) * goldLossRatio);
		resourceManager.consumeResource(ResourceType::GOLD, goldLoss);
		logMessage("[RANDOMEVENT] Bandits has stolen " + std::to_string(goldLoss) + " gold.");

	}
	if (city.getSafety() < safetyLoss) {
		int safetyLossLower = city.getSafety();
		city.changeSafety(-safetyLossLower);
		logMessage("[RANDOMEVENT]  Safety decreased by " + std::to_string(safetyLossLower) + ".");

	}
	else
	{
		city.changeSafety(-safetyLoss);
		logMessage("[RANDOMEVENT]  Safety decreased by " + std::to_string(safetyLoss) + ".");
	}


};