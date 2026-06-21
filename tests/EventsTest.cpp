#include <gtest/gtest.h>
#include "FireEvent.h"
#include "DroughtEvent.h"
#include "PlagueEvent.h"
#include "BanditAttackEvent.h"
#include "RiotsEvent.h"
#include "City.h"
#include "ResourceManager.h"

TEST(FireEventTest, ObnizaDrewnoIBezpieczenstwo) {
    City city;
    ResourceManager rm;
    rm.addResource(ResourceType::WOOD, 100);
    int drewnoPrzed = rm.getResourceAmount(ResourceType::WOOD);
    int bezpieczenstwoPrzed = city.getSafety();

    FireEvent event;
    event.execute(city, rm);

    EXPECT_LT(rm.getResourceAmount(ResourceType::WOOD), drewnoPrzed);
    EXPECT_LT(city.getSafety(), bezpieczenstwoPrzed);
}

TEST(FireEventTest, MaloDrewnaZabieraWszystko) {
    City city;
    ResourceManager rm;
    rm.addResource(ResourceType::WOOD, 20);

    FireEvent event;
    event.execute(city, rm);

    EXPECT_EQ(rm.getResourceAmount(ResourceType::WOOD), 0);
}

TEST(DroughtEventTest, ObnizaJedzenie) {
    City city;
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 100);
    int jedzeniePrzed = rm.getResourceAmount(ResourceType::FOOD);

    DroughtEvent event;
    event.execute(city, rm);

    EXPECT_LT(rm.getResourceAmount(ResourceType::FOOD), jedzeniePrzed);
}

TEST(DroughtEventTest, MaloJedzeniaZabieraWszystko) {
    City city;
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 20);

    DroughtEvent event;
    event.execute(city, rm);

    EXPECT_EQ(rm.getResourceAmount(ResourceType::FOOD), 0);
}

TEST(PlagueEventTest, ObnizaBezpieczenstwoIJedzenie) {
    City city;
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 100);
    int jedzeniePrzed = rm.getResourceAmount(ResourceType::FOOD);
    int bezpieczenstwoPrzed = city.getSafety();

    PlagueEvent event;
    event.execute(city, rm);

    EXPECT_LT(rm.getResourceAmount(ResourceType::FOOD), jedzeniePrzed);
    EXPECT_LT(city.getSafety(), bezpieczenstwoPrzed);
}

TEST(BanditAttackEventTest, ObnizaZlotoIBezpieczenstwo) {
    City city;
    ResourceManager rm;
    rm.addResource(ResourceType::GOLD, 20);
    int zlotoPrzed = rm.getResourceAmount(ResourceType::GOLD);
    int bezpieczenstwoPrzed = city.getSafety();

    BanditAttackEvent event;
    event.execute(city, rm);

    EXPECT_LT(rm.getResourceAmount(ResourceType::GOLD), zlotoPrzed);
    EXPECT_LT(city.getSafety(), bezpieczenstwoPrzed);
}

TEST(RiotsEventTest, ObnizaZlotoIBezpieczenstwo) {
    City city;
    ResourceManager rm;
    rm.addResource(ResourceType::GOLD, 20);
    int zlotoPrzed = rm.getResourceAmount(ResourceType::GOLD);
    int bezpieczenstwoPrzed = city.getSafety();

    RiotsEvent event;
    event.execute(city, rm);

    EXPECT_LT(rm.getResourceAmount(ResourceType::GOLD), zlotoPrzed);
    EXPECT_LT(city.getSafety(), bezpieczenstwoPrzed);
}

TEST(RiotsEventTest, DuzoZlotaObnizaProporconalnie) {
    City city;
    ResourceManager rm;
    rm.addResource(ResourceType::GOLD, 200);

    RiotsEvent event;
    event.execute(city, rm);

    EXPECT_GT(rm.getResourceAmount(ResourceType::GOLD), 0);
    EXPECT_LT(rm.getResourceAmount(ResourceType::GOLD), 200);
}
