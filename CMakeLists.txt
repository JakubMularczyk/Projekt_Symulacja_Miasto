cmake_minimum_required(VERSION 3.12)
project(SymulacjaMiasto CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SymulacjaMiasto
    src/main.cpp

    src/core/City.cpp
    src/core/Engine.cpp

    src/buildings/Building.cpp
    src/buildings/Farm.cpp
    src/buildings/Sawmill.cpp
    src/buildings/Quarry.cpp
    src/buildings/Barracks.cpp
    src/buildings/Marketplace.cpp

    src/population/Citizen.cpp
    src/population/Farmer.cpp
    src/population/Merchant.cpp
    src/population/Guard.cpp
    src/population/Woodcutter.cpp
    src/population/Stonecutter.cpp

    src/events/RandomEvent.cpp
    src/events/FireEvent.cpp
    src/events/DroughtEvent.cpp
    src/events/BanditAttackEvent.cpp
    src/events/NoEvent.cpp
    src/events/PlagueEvent.cpp
    src/events/RiotsEvent.cpp

    src/managers/BuildingManager.cpp
    src/managers/PopulationManager.cpp
    src/managers/ResourceManager.cpp
    src/managers/RandomEventManager.cpp

    src/factories/BuildingFactory.cpp
    src/factories/PopulationFactory.cpp)

target_include_directories(SymulacjaMiasto PRIVATE src/Include)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
