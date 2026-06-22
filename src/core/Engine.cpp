#include "Engine.h"
#include <iostream>
#include "PopulationFactory.h"
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include "Logger.h"
#include "PopulationManager.h"
#include "BuildingFactory.h"
#define CONSUMPTION_FOOD 25
#define CONSUMPTION_GOLD 18

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
   /* if (!loadConfig("config.txt")) {
        resourceManager.addResource(ResourceType::FOOD, 1500);
        resourceManager.addResource(ResourceType::GOLD, 1200);
        resourceManager.addResource(ResourceType::WOOD, 1000);
        resourceManager.addResource(ResourceType::STONE, 500);
    }*/
resourceManager.addResource(ResourceType::FOOD, 1500);
resourceManager.addResource(ResourceType::GOLD, 1200);
resourceManager.addResource(ResourceType::WOOD, 1000);
resourceManager.addResource(ResourceType::STONE, 500);

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
    static bool isFirstTime = true;

    if (isFirstTime) {
        std::cout << "\n==============================================================\n";
        std::cout << "                   CITY SIMULATOR ENGINE                      \n";
        std::cout << "==============================================================\n";
        std::cout << " Welcome! As the unseen manager of a growing settlement,      \n";
        std::cout << " your goal is to gather resources, expand infrastructure,     \n";
        std::cout << " manage citizens, and survive unexpected random events.       \n";
        std::cout << "==============================================================\n";
        std::cout << "[0] Show logs | [1] Start simulation | [2] Exit simulation\n";
        std::cout << "[3] Fast-forward X turns\nChoice: ";
    } else {
        std::cout << "\n[0] Show logs | [1] Next turn | [2] End simulation\n";
        std::cout << "[3] Fast-forward X turns\nChoice: ";
    }

    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Please enter a valid number!" << std::endl;
        return;
    }

    if (choice == 0) {
        std::ifstream logFile("simulation_logs.txt");
        if (logFile.is_open()) {
            std::cout << "\n--- CURRENT SIMULATION LOGS ---\n";
            std::string line;
            while (std::getline(logFile, line)) {
                std::cout << line << "\n";
            }
            std::cout << "-------------------------------\n";
            logFile.close();
        } else {
            std::cout << "\n[INFO] Logs are currently empty or file cannot be opened.\n";
        }
    }
    else if (choice == 1) {
        if (isFirstTime) {
            std::cout << "\n>>> Preparing the city... Simulation started! <<<\n";
            isFirstTime = false;
        }
        executeTurn(); 
    }
    else if (choice == 2) {
        isSimulationRunning = false;
        if (isFirstTime) {
            std::cout << "Simulation exited before starting." << std::endl;
        } else {
            std::cout << "Simulation ended by user." << std::endl;
        }
    }
    else if (choice == 3) {
        int turnsToSkip;
        std::cout << "\nEnter how many turns to simulate automatically: ";
        
        if (!(std::cin >> turnsToSkip) || turnsToSkip <= 0) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "[ERROR] Invalid input! Please enter a positive number.\n";
        } else {
            if (isFirstTime) {
                std::cout << "\n>>> Preparing the city... Simulation started! <<<\n";
                isFirstTime = false;
            }
            
            std::cout << "\n>>> Fast-forwarding " << turnsToSkip << " turns... <<<\n";
            
            for (int i = 0; i < turnsToSkip; ++i) {
                if (!isSimulationRunning) break; 
                
                bool isSilent = (i < turnsToSkip - 1); 
                executeTurn(isSilent);
            }
        }
    }
    else {
        std::cout << "Invalid choice! Please select 0, 1, 2, or 3." << std::endl;
    }
}


void Engine::executeTurn(bool silent) {
    currentTurn++;
    
    if (!silent) {
        std::cout << "\n--- START OF TURN " << currentTurn << " ---" << std::endl;
    }

    logMessage("\n--- START OF TURN " + std::to_string(currentTurn) + " ---");

    city.getPopulationManager().executeCitizenActions();
    city.getBuildingManager().operateAll();
    city.getPopulationManager().updateAllHappiness(resourceManager, city.getSafety());
    city.getPopulationManager().handleMigration(currentTurn, resourceManager, city);
    city.getBuildingManager().handleExpansion(currentTurn, resourceManager, city);
    resourceManager.consumeResource(ResourceType::FOOD, CONSUMPTION_FOOD);
    resourceManager.consumeResource(ResourceType::GOLD, CONSUMPTION_GOLD);

    if (currentTurn > 5) {
        randomEventManager.executeRandomEvent(city, resourceManager);
    }

    logMessage(" [GLOBAL] The city centrally consumed: " + std::to_string(CONSUMPTION_FOOD) + " FOOD, " + std::to_string(CONSUMPTION_GOLD) + " GOLD.");

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

    if (!silent) {
        displayReport();
    }

    logMessage(" [RESOURCES STATUS] FOOD: " + std::to_string(resourceManager.getResourceAmount(ResourceType::FOOD))
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
