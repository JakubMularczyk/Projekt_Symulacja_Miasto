cmake_minimum_required(VERSION 3.12)
project(SymulacjaMiasto CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SymulacjaMiasto
    src/main.cpp
    src/Farm.cpp
    src/Barracks.cpp
    src/BuildingManager.cpp
    src/BuildingFactory.cpp
    "src/Include/BuildingManager.h"
    "src/Include/BuildingFactory.h"
    "src/Include/Farm.h"
    "src/Include/Barracks.h"
    src/Building.cpp
    src/Citizen.cpp
    src/City.cpp
    src/Engine.cpp
    src/Farmer.cpp
    src/Merchant.cpp
    src/Guard.cpp
    src/ResourceManager.cpp
    src/Woodcutter.cpp
    src/Stonecutter.cpp
    src/RandomEvent.cpp
    src/FireEvent.cpp
    src/DroughtEvent.cpp
    src/BanditAttackEvent.cpp
    src/RandomEventManager.cpp
    src/PopulationManager.cpp
    src/PopulationFactory.cpp
    src/NoEvent.cpp
    src/PlagueEvent.cpp
    src/RiotsEvent.cpp
    src/Farm.cpp
    src/Sawmill.cpp
    src/Quarry.cpp
    src/Barracks.cpp
    src/Marketplace.cpp
    src/BuildingFactory.cpp
    src/BuildingManager.cpp
    "src/Include/BuildingManager.h"
    "src/Include/BuildingFactory.h"
    "src/Include/PopulationManager.h"
    "src/Include/PopulationFactory.h"
    "src/Include/NoEvent.h"
    "src/Include/PlagueEvent.h"
    "src/Include/RiotsEvent.h"
    "src/Include/Farm.h"
    "src/Include/Sawmill.h"
    "src/Include/Quarry.h"
    "src/Include/Barracks.h"
    "src/Include/Marketplace.h"
    "src/Include/BuildingFactory.h")

target_include_directories(SymulacjaMiasto PRIVATE src/Include)
