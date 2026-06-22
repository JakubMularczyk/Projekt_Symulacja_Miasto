#include "PopulationManager.h"
#include "Citizen.h"
#include "ResourceManager.h"
#include "Farmer.h"
#include "Merchant.h"
#include "Stonecutter.h"
#include "Woodcutter.h"
#include <utility>
#include <iostream>
#include <cstdlib>     

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
            
            std::unique_ptr<Citizen> newCitizen = nullptr;
            std::string citizenType = "";

            int randomChoice = std::rand() % 5;

            switch (randomChoice) {
                case 0:
                    newCitizen = std::make_unique<Farmer>(40, &resourceManager, 10, 2);
                    citizenType = "Farmer";
                    break;
                case 1:
                    newCitizen = std::make_unique<Guard>(45, &resourceManager, 12, 4);
                    citizenType = "Guard";
                    break;
                case 2:
                    newCitizen = std::make_unique<Merchant>(42, &resourceManager, 8, 3);
                    citizenType = "Merchant";
                    break;
                case 3:
                    newCitizen = std::make_unique<Stonecutter>(38, &resourceManager, 15, 1);
                    citizenType = "Stonecutter";
                    break;
                case 4:
                    newCitizen = std::make_unique<Woodcutter>(35, &resourceManager, 11, 2);
                    citizenType = "Woodcutter";
                    break;
                default:
                    newCitizen = std::make_unique<Farmer>(40, &resourceManager, 10, 2);
                    citizenType = "Farmer";
                    break;
            }

            if (newCitizen) {
                addCitizen(std::move(newCitizen));
                std::cout << ">>> MIGRATION: Due to prosperity, a new citizen (" << citizenType << ") has joined the city! <<<" << std::endl;
            }
        }
    }
}
