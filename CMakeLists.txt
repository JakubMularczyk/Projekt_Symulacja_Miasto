cmake_minimum_required(VERSION 3.12)
project(SymulacjaMiasto CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SymulacjaMiasto
    src/main.cpp
    src/Farm.cpp
    src/Barracks.cpp
    src/Market.cpp
    src/BuildingManager.cpp
    src/BuildingFactory.cpp
    "src/Include/BuildingManager.h"
    "src/Include/BuildingFactory.h"
    "src/Include/Farm.h"
    "src/Include/Barracks.h"
    "src/Include/Market.h"
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
    src/Marketplace.cpp
    "src/Include/Marketplace.h" "src/Include/PopulationManager.h" "src/PopulationManager.cpp" "src/Include/PopulationFactory.h" "src/PopulationFactory.cpp" "src/Include/NoEvent.h" "src/NoEvent.cpp" "src/Include/PlagueEvent.h" "src/PlagueEvent.cpp" "src/Include/RiotsEvent.h" "src/RiotsEvent.cpp")

target_include_directories(SymulacjaMiasto PRIVATE src/Include)
