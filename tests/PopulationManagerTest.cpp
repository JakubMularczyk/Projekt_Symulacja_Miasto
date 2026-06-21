#include <gtest/gtest.h>
#include "PopulationManager.h"
#include "Farmer.h"
#include "ResourceManager.h"
#include <memory>

TEST(PopulationManagerTest, PoczatkowaPopulacjaRownaZero) {
    PopulationManager pm;
    EXPECT_EQ(pm.getPopulation(), 0);
}

TEST(PopulationManagerTest, DodawanieObywatela) {
    PopulationManager pm;
    ResourceManager rm;
    pm.addCitizen(std::make_unique<Farmer>(50, &rm, 10, 1));
    EXPECT_EQ(pm.getPopulation(), 1);
}

TEST(PopulationManagerTest, SrednioSzescieWieleObywateli) {
    PopulationManager pm;
    ResourceManager rm;
    pm.addCitizen(std::make_unique<Farmer>(40, &rm, 10, 1));
    pm.addCitizen(std::make_unique<Farmer>(60, &rm, 10, 1));
    EXPECT_EQ(pm.getAverageHappiness(), 50);
}

TEST(PopulationManagerTest, SrednioSzescieGdyBrakObywateli) {
    PopulationManager pm;
    EXPECT_EQ(pm.getAverageHappiness(), 0);
}

TEST(PopulationManagerTest, UpdateAllHappinessZmieniaObywateli) {
    PopulationManager pm;
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 1000);
    rm.addResource(ResourceType::GOLD, 1000);
    pm.addCitizen(std::make_unique<Farmer>(50, &rm, 10, 1));
    int szczesciePrzed = pm.getAverageHappiness();
    pm.updateAllHappiness(rm, 80);
    EXPECT_NE(pm.getAverageHappiness(), szczesciePrzed);
}

TEST(PopulationManagerTest, MigracjaDodajeObywatelaPoCo5Turach) {
    PopulationManager pm;
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 1000);
    pm.addCitizen(std::make_unique<Farmer>(50, &rm, 10, 1));
    int populacjaPrzed = pm.getPopulation();
    pm.handleMigration(5, rm);
    EXPECT_GT(pm.getPopulation(), populacjaPrzed);
}

TEST(PopulationManagerTest, MigracjaNieDodajeObywatelaBezJedzenia) {
    PopulationManager pm;
    ResourceManager rm;
    pm.addCitizen(std::make_unique<Farmer>(50, &rm, 10, 1));
    int populacjaPrzed = pm.getPopulation();
    pm.handleMigration(5, rm);
    EXPECT_EQ(pm.getPopulation(), populacjaPrzed);
}

TEST(PopulationManagerTest, MigracjaNieDodajeObywatelaPozaTura5) {
    PopulationManager pm;
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 1000);
    pm.addCitizen(std::make_unique<Farmer>(50, &rm, 10, 1));
    int populacjaPrzed = pm.getPopulation();
    pm.handleMigration(3, rm);
    EXPECT_EQ(pm.getPopulation(), populacjaPrzed);
}
