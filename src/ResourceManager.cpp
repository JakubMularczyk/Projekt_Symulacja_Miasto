#include "ResourceManager.h"

ResourceManager::ResourceManager() {
    resources[ResourceType::FOOD] = 0;
    resources[ResourceType::GOLD] = 0;
    resources[ResourceType::WOOD] = 0;
    resources[ResourceType::STONE] = 0;
}

void ResourceManager::addResource(ResourceType type, int amount) {
    if (amount > 0) {
        resources[type] += amount;
    }
}

bool ResourceManager::consumeResource(ResourceType type, int amount) {
    if (amount > 0 && resources[type] >= amount) {
        resources[type] -= amount;
        return true;
    }
    return false;
}

int ResourceManager::getResourceAmount(ResourceType type) const {
    return resources.at(type);
}