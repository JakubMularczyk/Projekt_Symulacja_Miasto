#pragma once
#include <vector>
#include <memory>
#include "RandomEvent.h"
class City;
class ResourceManager;
class RandomEventManager {
private:
	std::vector<std::unique_ptr<RandomEvent>> events;

public:
	RandomEventManager();
	void addEvent(std::unique_ptr<RandomEvent> event);
	void executeAllEvents(City& city, ResourceManager& resourceManager);
};