#include "Engine.h"
#include <iostream>
#include "City.h"
#include "Farmer.h"
#include "Merchant.h"
#include "Guard.h"
#include <memory>

Engine::Engine() : currentTurn(0), isSimulationRunning(false) {
    // Setting up resources
    city.getResourceManager().addResource(ResourceType::FOOD, 6);
    city.getResourceManager().addResource(ResourceType::GOLD, 10);
    city.getResourceManager().addResource(ResourceType::WOOD, 100);
    city.getResourceManager().addResource(ResourceType::STONE, 50);

    // Adding citizens
    city.addCitizen(std::make_unique<Farmer>(40, 30, &city.getResourceManager(), 10, 2));
    city.addCitizen(std::make_unique<Farmer>(40, 30, &city.getResourceManager(), 10, 1));
    city.addCitizen(std::make_unique<Farmer>(40, 30, &city.getResourceManager(), 10, 1));
    city.addCitizen(std::make_unique<Merchant>(40, 30, &city.getResourceManager(), 2));
    city.addCitizen(std::make_unique<Merchant>(40, 30, &city.getResourceManager(), 6));
    city.addCitizen(std::make_unique<Guard>(40, 30, &city.getResourceManager(), 1, 10, &city));
}

void Engine::run() {
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