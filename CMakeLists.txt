cmake_minimum_required(VERSION 3.12)
project(SymulacjaMiasto CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SymulacjaMiasto
    src/main.cpp
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
 "src/Include/PopulationManager.h" "src/PopulationManager.cpp" "src/Include/PopulationFactory.h" "src/PopulationFactory.cpp" "src/Include/NoEvent.h" "src/NoEvent.cpp")

target_include_directories(SymulacjaMiasto PRIVATE src/Include)