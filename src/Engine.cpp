#include "Engine.h"
#include <iostream>
#include "City.h"
#include "Farmer.h"
#include "Merchant.h"
#include "Guard.h"
#include "Woodcutter.h"
#include "Stonecutter.h"
#include <memory>
#include <fstream>  
#include <sstream>  

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
                    city.getResourceManager().addResource(ResourceType::FOOD, value);
                } else if (key == "GOLD") {
                    city.getResourceManager().addResource(ResourceType::GOLD, value);
                } else if (key == "WOOD") {
                    city.getResourceManager().addResource(ResourceType::WOOD, value);
                } else if (key == "STONE") {
                    city.getResourceManager().addResource(ResourceType::STONE, value);
                } else if (key == "SAFETY") {
                    int currentSafety = city.getSafety();
                    city.changeSafety(value - currentSafety); 
                }
            } catch (const std::exception& e) {
                std::cerr << "Error parsing value for key: " << key << " (" << valueStr << ")" << std::endl;
            }
        }
    }
    file.close();
    return true;
}

Engine::Engine() : currentTurn(0), isSimulationRunning(false) {
    if (!loadConfig("config.txt")) {
        city.getResourceManager().addResource(ResourceType::FOOD, 60);
        city.getResourceManager().addResource(ResourceType::GOLD, 10);
        city.getResourceManager().addResource(ResourceType::WOOD, 100);
        city.getResourceManager().addResource(ResourceType::STONE, 50);
    }

    city.addCitizen(std::make_unique<Farmer>(40, 30, 100, &city.getResourceManager(), 10, 2));
    city.addCitizen(std::make_unique<Farmer>(40, 30, 100, &city.getResourceManager(), 10));
    city.addCitizen(std::make_unique<Farmer>(40, 30, 100, &city.getResourceManager(), 10));
    city.addCitizen(std::make_unique<Merchant>(40, 30, 100, &city.getResourceManager(), 2));
    city.addCitizen(std::make_unique<Merchant>(40, 30, 100, &city.getResourceManager(), 6));
    city.addCitizen(std::make_unique<Guard>(40, 30, 100, &city, &city.getResourceManager(), 10, 1));
    city.addCitizen(std::make_unique<Woodcutter>(40, 30, 100, &city.getResourceManager(), 10));
    city.addCitizen(std::make_unique<Stonecutter>(40, 30, 100, &city.getResourceManager(), 10));

}

void Engine::run() {
    isSimulationRunning = true;
    std::cout << "--- WELCOME TO THE MEDIEVAL CITY SIMULATION ---" << std::endl;
    //loadConfig;
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
    city.executeCitizenActions();
    city.getResourceManager().consumeResource(ResourceType::FOOD, 10);
    city.getResourceManager().consumeResource(ResourceType::GOLD, 5);
    city.updateTurnsToCollapse();

    if (city.checkCollapseConditions()) {
        displayReport();
        std::cout << "\n=========================================" << std::endl;
        std::cout << "             THE CITY COLLAPSED!         " << std::endl;
        std::cout << "=========================================" << std::endl;
        std::cout << "Turns survived: " << currentTurn << std::endl;

        isSimulationRunning = false;
        return;
    }

    displayReport();
}

void Engine::displayReport() const {
    const ResourceManager& rm = city.getResourceManager();

    std::cout << "=========================================" << std::endl;
    std::cout << " REPORT FROM TURN: " << currentTurn << std::endl;
    std::cout << " FOOD: " << rm.getResourceAmount(ResourceType::FOOD)
        << " | GOLD: " << rm.getResourceAmount(ResourceType::GOLD)
        << " | WOOD: " << rm.getResourceAmount(ResourceType::WOOD)
        << " | STONE: " << rm.getResourceAmount(ResourceType::STONE) << std::endl;
    std::cout << " SAFETY: " << city.getSafety() << std::endl;
    std::cout << " Random Event: " << std::endl;
    std::cout << "=========================================" << std::endl;
}
