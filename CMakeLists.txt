cmake_minimum_required(VERSION 3.12)
project(SymulacjaMiasto CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJEKT_SOURCES
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

add_executable(SymulacjaMiasto src/main.cpp ${PROJEKT_SOURCES})
target_include_directories(SymulacjaMiasto PRIVATE src/Include)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Testy
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(SymulacjaMiastoTesty
    tests/ResourceManagerTest.cpp
    tests/CitizenTest.cpp
    tests/PopulationManagerTest.cpp
    tests/CityTest.cpp
    tests/EventsTest.cpp
    ${PROJEKT_SOURCES})

target_include_directories(SymulacjaMiastoTesty PRIVATE src/Include)
target_link_libraries(SymulacjaMiastoTesty GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(SymulacjaMiastoTesty)
