#include <gtest/gtest.h>
#include "ResourceManager.h"

TEST(ResourceManagerTest, PoczatkoweZasobyRowneZero) {
    ResourceManager rm;
    EXPECT_EQ(rm.getResourceAmount(ResourceType::FOOD), 0);
    EXPECT_EQ(rm.getResourceAmount(ResourceType::GOLD), 0);
    EXPECT_EQ(rm.getResourceAmount(ResourceType::WOOD), 0);
    EXPECT_EQ(rm.getResourceAmount(ResourceType::STONE), 0);
}

TEST(ResourceManagerTest, DodawanieZasobow) {
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 50);
    EXPECT_EQ(rm.getResourceAmount(ResourceType::FOOD), 50);
}

TEST(ResourceManagerTest, DodawanieUjemnejIlosciNieZmieniaZasobow) {
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, -10);
    EXPECT_EQ(rm.getResourceAmount(ResourceType::FOOD), 0);
}

TEST(ResourceManagerTest, ZuzywanieZasobowPowodzenie) {
    ResourceManager rm;
    rm.addResource(ResourceType::GOLD, 100);
    bool wynik = rm.consumeResource(ResourceType::GOLD, 40);
    EXPECT_TRUE(wynik);
    EXPECT_EQ(rm.getResourceAmount(ResourceType::GOLD), 60);
}

TEST(ResourceManagerTest, ZuzywanieZasobowBrakSrodkow) {
    ResourceManager rm;
    rm.addResource(ResourceType::WOOD, 10);
    bool wynik = rm.consumeResource(ResourceType::WOOD, 20);
    EXPECT_FALSE(wynik);
    EXPECT_EQ(rm.getResourceAmount(ResourceType::WOOD), 10);
}

TEST(ResourceManagerTest, ZuzywanieDokladnejIlosci) {
    ResourceManager rm;
    rm.addResource(ResourceType::STONE, 30);
    bool wynik = rm.consumeResource(ResourceType::STONE, 30);
    EXPECT_TRUE(wynik);
    EXPECT_EQ(rm.getResourceAmount(ResourceType::STONE), 0);
}

TEST(ResourceManagerTest, ZuzywanieZeroNieZmieniaZasobow) {
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 50);
    bool wynik = rm.consumeResource(ResourceType::FOOD, 0);
    EXPECT_FALSE(wynik);
    EXPECT_EQ(rm.getResourceAmount(ResourceType::FOOD), 50);
}
