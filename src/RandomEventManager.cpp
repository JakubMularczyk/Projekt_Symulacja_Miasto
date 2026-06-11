#include "RandomEventManager.h"
#include "City.h"
#include "ResourceManager.h"
#include "FireEvent.h"
#include "DroughtEvent.h"
#include <random>
#include <iostream>
#include <utility>
RandomEventManager::RandomEventManager() {
    addEvent(std::make_unique<FireEvent>());
    addEvent(std::make_unique<DroughtEvent>());
}
void RandomEventManager::addEvent(std::unique_ptr<RandomEvent> event) {
    events.push_back(std::move(event));
}

void RandomEventManager::executeAllEvents(City& city, ResourceManager& resourceManager) {
    for (auto& event : events) {
        event->execute(city, resourceManager);
    }
}