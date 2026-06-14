#include "PopulationManager.h"
#include "Citizen.h"
#include <utility>


void PopulationManager::addCitizen(std::unique_ptr<Citizen> citizen) {
    population.push_back(std::move(citizen));
}
void PopulationManager::executeCitizenActions() {
    for (auto& citizen : population) {
        citizen->work();
        citizen->consume();
    }
}
int PopulationManager::getPopulation() const
{
    return population.size();
}