#pragma once
#include <vector>
#include <memory>
#include <random>
#include "RandomEvent.h"

#define SEED 12345
class City;
class ResourceManager;
class RandomEventManager {
private:
	std::vector<std::unique_ptr<RandomEvent>> events;
	std::mt19937 rng_engine;

public:
	RandomEventManager(unsigned int seed = SEED);
	void addEvent(std::unique_ptr<RandomEvent> event);
	void executeAllEvents(City& city, ResourceManager& resourceManager);

	void executeRandomEvent(City& city, ResourceManager& resourceManager);
};