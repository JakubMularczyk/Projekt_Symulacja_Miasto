#pragma once

#include "City.h"
#include "ResourceManager.h" 
#include <string>

class Engine {
private:
    City city;
    ResourceManager resourceManager; 
    int currentTurn;
    bool isSimulationRunning;

    void executeTurn();
    void displayReport() const;
    void showMenu();

    std::string trim(const std::string& str);
    bool loadConfig(const std::string& filePath);

public:
    Engine();
    void run();
};
