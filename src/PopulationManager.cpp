#include "PopulationManager.h"
#include "Citizen.h"
#include "ResourceManager.h"
#include "Farmer.h" 
#include <utility>
#include <iostream> 

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

int PopulationManager::getAverageHappiness() const {
    if (population.empty()) return 0;
    int sum = 0;
    for (const auto& citizen : population) {
        sum += citizen->getHappiness();
    }
    return sum / population.size();
}

int PopulationManager::getPopulation() const {
    return population.size();
}

void PopulationManager::handleMigration(int currentTurn, ResourceManager& resourceManager) {
    if (currentTurn > 0 && currentTurn % 5 == 0) {
        int currentPopulation = getPopulation();
        
        if (currentPopulation == 0) return; 

        // czy starczy jedzenia
        int foodPerCitizen = resourceManager.getResourceAmount(ResourceType::FOOD) / currentPopulation;

        if (foodPerCitizen >= 5) {
            // nowy obywatel
            addCitizen(std::make_unique<Farmer>(40, 30, 100, &resourceManager, 10, 2));
            std::cout << ">>> MIGRACJA: Ze wzgledu na dobrobyt, nowy mieszkaniec (Farmer) dolaczyl do miasta! <<<" << std::endl;
        }
    }
}
}
