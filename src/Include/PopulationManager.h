#pragma once
#include <vector>
#include <memory>
class Citizen;
class ResourceManager;
class PopulationManager {
private:
	std::vector<std::unique_ptr<Citizen>> population;

public:
	void addCitizen(std::unique_ptr<Citizen> citizen);
	void executeCitizenActions();
	int getPopulation() const;
	//void displayCitizens();
};