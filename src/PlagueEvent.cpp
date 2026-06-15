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
	const int safetyLoss = 15;
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