#include "Engine.h"
#include <iostream>
#include "Include/PopulationFactory.h"
#include <memory>
#include <fstream>
#include <sstream>
#include "Logger.h" 
#include "Include/PopulationManager.h"
#include "Include/BuildingFactory.h"
#define CONSUMPTION_FOOD 10
#define CONSUMPTION_GOLD 5

std::string Engine::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

bool Engine::loadConfig(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Warning: Could not open " << filePath << ". Loading default setup." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        std::stringstream ss(line);
        std::string key;
        std::string valueStr;

        if (std::getline(ss, key, '=') && std::getline(ss, valueStr)) {
            key = trim(key);
            valueStr = trim(valueStr);

            try {
                int value = std::stoi(valueStr);

                if (key == "FOOD") {
                    resourceManager.addResource(ResourceType::FOOD, value);
                }
                else if (key == "GOLD") {
                    resourceManager.addResource(ResourceType::GOLD, value);
                }
                else if (key == "WOOD") {
                    resourceManager.addResource(ResourceType::WOOD, value);
                }
                else if (key == "STONE") {
                    resourceManager.addResource(ResourceType::STONE, value);
                }
                else if (key == "SAFETY") {
                    int currentSafety = city.getSafety();
                    city.changeSafety(value - currentSafety);
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Error parsing value for key: " << key << std::endl;
            }
        }
    }
    file.close();
    return true;
}

Engine::Engine() : currentTurn(0), isSimulationRunning(false) {
    if (!loadConfig("config.txt")) {
        resourceManager.addResource(ResourceType::FOOD, 60);
        resourceManager.addResource(ResourceType::GOLD, 30);
        resourceManager.addResource(ResourceType::WOOD, 100);
        resourceManager.addResource(ResourceType::STONE, 50);
    }

    PopulationFactory populaationFactory;
    populaationFactory.createStartingPopulation(city, resourceManager);

    BuildingFactory buildingFactory;
    buildingFactory.createStartingBuildings(city.getBuildingManager(), city, resourceManager);
}

void Engine::run() {
    clearLogFile();
    isSimulationRunning = true;
    std::cout << "--- WELCOME TO THE MEDIEVAL CITY SIMULATION ---" << std::endl;

    while (isSimulationRunning) {
        showMenu();
    }
}

void Engine::showMenu() {
    std::cout << "\n[1] Next turn | [2] End simulation\nChoice: ";
    int choice;

    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Please enter a number!" << std::endl;
        return;
    }

    if (choice == 1) {
        executeTurn();
    }
    else if (choice == 2) {
        isSimulationRunning = false;
        std::cout << "Simulation ended by user." << std::endl;
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
    }
}

void Engine::executeTurn() {
    currentTurn++;
    std::cout << "\n--- START OF TURN " << currentTurn << " ---" << std::endl;

    logMessage("\n--- START OF TURN " + std::to_string(currentTurn) + " ---");

    city.getPopulationManager().executeCitizenActions();
    city.getBuildingManager().operateAll();
    city.getPopulationManager().updateAllHappiness(resourceManager, city.getSafety());

    resourceManager.consumeResource(ResourceType::FOOD, CONSUMPTION_FOOD);
    resourceManager.consumeResource(ResourceType::GOLD, CONSUMPTION_GOLD);

    if (currentTurn > 5) {
        randomEventManager.executeRandomEvent(city, resourceManager);
    }

    logMessage(" [GLOBAL] Miasto skonsumowalo centralnie: " + std::to_string(CONSUMPTION_FOOD) + " FOOD, " + std::to_string(CONSUMPTION_GOLD) + " GOLD.");

    city.updateTurnsToCollapse(resourceManager);

    if (city.checkCollapseConditions()) {
        displayReport();

        logMessage("=========================================");
        logMessage("             THE CITY COLLAPSED!         ");
        logMessage("=========================================");
        logMessage("Turns survived: " + std::to_string(currentTurn));

        std::cout << "\n=========================================" << std::endl;
        std::cout << "             THE CITY COLLAPSED!         " << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "Turns survived: " << currentTurn << std::endl;

        isSimulationRunning = false;
        return;
    }

    displayReport();

    logMessage(" [STAN MAGAZYNU] FOOD: " + std::to_string(resourceManager.getResourceAmount(ResourceType::FOOD))
        + " | GOLD: " + std::to_string(resourceManager.getResourceAmount(ResourceType::GOLD))
        + " | WOOD: " + std::to_string(resourceManager.getResourceAmount(ResourceType::WOOD))
        + " | STONE: " + std::to_string(resourceManager.getResourceAmount(ResourceType::STONE))
        + " | SAFETY: " + std::to_string(city.getSafety()));
}

void Engine::displayReport() const {
    std::cout << "=========================================" << std::endl;
    std::cout << " REPORT FROM TURN: " << currentTurn << std::endl;
    std::cout << " FOOD: " << resourceManager.getResourceAmount(ResourceType::FOOD)
        << " | GOLD: " << resourceManager.getResourceAmount(ResourceType::GOLD)
        << " | WOOD: " << resourceManager.getResourceAmount(ResourceType::WOOD)
        << " | STONE: " << resourceManager.getResourceAmount(ResourceType::STONE) << std::endl;
    std::cout << " SAFETY: " << city.getSafety() << std::endl;
    std::cout << " AVG HAPPINESS: " << city.getPopulationManager().getAverageHappiness() << std::endl;
    std::cout << " POPULATION: " << city.getPopulationManager().getPopulation() << std::endl;
    std::cout << "=========================================" << std::endl;
}