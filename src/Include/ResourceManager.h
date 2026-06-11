#pragma once
#include <map>
#include "Resources.h"

class ResourceManager {
private:
    std::map<ResourceType, int> resources;

public:
    ResourceManager();
    void addResource(ResourceType type, int amount);
    bool consumeResource(ResourceType type, int amount);
    int getResourceAmount(ResourceType type) const;
};