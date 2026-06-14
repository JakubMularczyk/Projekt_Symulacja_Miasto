#pragma once

class PopulationManager;
class City;
class ResourceManager;

class PopulationFactory {
public:
	static void  createStartingPopulation(PopulationManager& populationManager, City& city, ResourceManager& resourceManager);
};