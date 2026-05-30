#pragma once

#include "City.h"

class Engine {
private:
    City city;
    int currentTurn;
    bool isSimulationRunning;

    void executeTurn();
    void displayReport() const;
    void showMenu();

public:
    Engine();
    void run();
};