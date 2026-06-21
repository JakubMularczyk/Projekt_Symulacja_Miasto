#pragma once

#include "City.h"
#include "ResourceManager.h" 
#include "RandomEventManager.h"
#include <string>

class Engine {
private:
    City city;
    ResourceManager resourceManager; 
    RandomEventManager randomEventManager;
    int currentTurn;
    bool isSimulationRunning;

    void executeTurn(bool silent = false);
    
    void displayReport() const;
    void showMenu();

    std::string trim(const std::string& str);
    bool loadConfig(const std::string& filePath);

public:
    Engine();
    void run();
};
