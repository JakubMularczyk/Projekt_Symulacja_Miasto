#include "RandomEventManager.h"
#include "City.h"
#include "ResourceManager.h"

//events:
#include "FireEvent.h"
#include "DroughtEvent.h"
#include "BanditAttackEvent.h"
#include "Include/NoEvent.h"
#include "PlagueEvent.h"
#include "RiotsEvent.h"

#include <random>
#include <iostream>
#include <utility>


RandomEventManager::RandomEventManager(unsigned int seed):rng_engine(seed) {
    addEvent(std::make_unique<FireEvent>());
    addEvent(std::make_unique<DroughtEvent>());
    addEvent(std::make_unique<BanditAttackEvent>());
    addEvent(std::make_unique<NoEvent>());
    addEvent(std::make_unique<NoEvent>());
    addEvent(std::make_unique<NoEvent>());
    addEvent(std::make_unique<NoEvent>());
    addEvent(std::make_unique<PlagueEvent>());
    addEvent(std::make_unique<RiotsEvent>());
  
}
void RandomEventManager::addEvent(std::unique_ptr<RandomEvent> event) {
    events.push_back(std::move(event));
}

void RandomEventManager::executeAllEvents(City& city, ResourceManager& resourceManager) {
    for (auto& event : events) {
        event->execute(city, resourceManager);
    }
}
void RandomEventManager::executeRandomEvent(City& city, ResourceManager& resourceManager) {
    std::uniform_int_distribution<size_t> dist(0, events.size() - 1);
    size_t randomIndex = dist(rng_engine);
    events[randomIndex]->execute(city, resourceManager);

}