#include "NoEvent.h"
#include <iostream>
#include "Logger.h"

NoEvent::NoEvent()
	:RandomEvent(30, "The city is looking good", "nothig :)") {

}

void NoEvent::execute(City& city, ResourceManager& resourceManager) {

	std::cout << "Random Event: " << getName() << " --->" << getDescription() << std::endl;
	logMessage("[RANDOMEVENT] nothing happened");

};