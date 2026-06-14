#include "PopulationManager.h"
#include "Citizen.h"
#include "ResourceManager.h"
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

void PopulationManager::updateAllHappiness(const ResourceManager& resourceManager, int safety) {
    int count = population.size();
    if (count == 0) return;

    int foodPerCitizen = resourceManager.getResourceAmount(ResourceType::FOOD) / count;
    int goldPerCitizen = resourceManager.getResourceAmount(ResourceType::GOLD) / count;

    for (auto& citizen : population) {
        citizen->updateHappiness(foodPerCitizen, goldPerCitizen, safety);
    }
}

int PopulationManager::getPopulation() const {
    return population.size();
}

int PopulationManager::getAverageHappiness() const {
    if (population.empty()) return 0;
    int sum = 0;
    for (const auto& citizen : population) {
        sum += citizen->getHappiness();
    }
    return sum / population.size();
}