#include "NoEvent.h"
#include <iostream>
#include "Logger.h"

NoEvent::NoEvent()
	:RandomEvent(30, "The city is looking good", "nothig :)") {

}

void NoEvent::execute(City& city, ResourceManager& resourceManager) {
	logMessage("[RANDOMEVENT] nothing happened");

};
