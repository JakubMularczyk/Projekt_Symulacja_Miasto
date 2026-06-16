#include "BuildingManager.h"
#include "Farm.h" // Wymagane, aby móc stworzyć nową Farmę co 10 tur
#include <utility>
#include <iostream>

void BuildingManager::addBuilding(std::unique_ptr<Building> building) {
    buildings.push_back(std::move(building));
}

void BuildingManager::operateAll() {
    for (auto& building : buildings) {
        building->operate();
    }
}

void BuildingManager::handleExpansion(int currentTurn, ResourceManager& resourceManager) {
    if (currentTurn > 0 && currentTurn % 10 == 0) {
        // 1. Tworzymy instancję nowej farmy
        auto newFarm = std::make_unique<Farm>(&resourceManager, 15);

        if (newFarm->build(&resourceManager)) {
            
            addBuilding(std::move(newFarm));
            
            std::cout << ">>> AUTOMATYCZNA ROZBUDOWA: Tura " << currentTurn 
                      << ". Pomyslnie zainwestowano surowce i wzniesiono nowa Farme! <<<" << std::endl;
        } 
        else {
            std::cout << ">>> AUTOMATYCZNA ROZBUDOWA: Anulowano w turze " << currentTurn 
                      << " z powodu braku surowcow w magazynie. <<<" << std::endl;
        }
    }
}
