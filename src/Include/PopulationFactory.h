#pragma once

class City;
class ResourceManager;

class PopulationFactory {
public:
	static void  createStartingPopulation(City& city, ResourceManager& resourceManager);
};