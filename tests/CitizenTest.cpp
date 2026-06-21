#include <gtest/gtest.h>
#include "Farmer.h"
#include "Merchant.h"
#include "Guard.h"
#include "Woodcutter.h"
#include "Stonecutter.h"
#include "ResourceManager.h"
#include "City.h"

TEST(FarmerTest, WorkDodajeJedzenie) {
    ResourceManager rm;
    Farmer farmer(50, &rm, 10, 1);
    farmer.work();
    EXPECT_GT(rm.getResourceAmount(ResourceType::FOOD), 0);
}

TEST(FarmerTest, ConsumePobieraJedzenie) {
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 10);
    Farmer farmer(50, &rm, 10, 1);
    farmer.consume();
    EXPECT_EQ(rm.getResourceAmount(ResourceType::FOOD), 9);
}

TEST(FarmerTest, ProdukcjaSkalowanaPoziomemSzczescia) {
    ResourceManager rm;
    Farmer farmer100(100, &rm, 10, 1);
    farmer100.work();
    int produkcja100 = rm.getResourceAmount(ResourceType::FOOD);

    ResourceManager rm2;
    Farmer farmer50(50, &rm2, 10, 1);
    farmer50.work();
    int produkcja50 = rm2.getResourceAmount(ResourceType::FOOD);

    EXPECT_GT(produkcja100, produkcja50);
}

TEST(MerchantTest, WorkDodajeZlotoGdyDostepneJedzenie) {
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 100);
    Merchant merchant(100, &rm, 1);
    merchant.work();
    EXPECT_GT(rm.getResourceAmount(ResourceType::GOLD), 0);
}

TEST(MerchantTest, WorkNieDodajeZlotoBezJedzenia) {
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 10);
    Merchant merchant(100, &rm, 1);
    merchant.work();
    EXPECT_EQ(rm.getResourceAmount(ResourceType::GOLD), 0);
}

TEST(WoodcutterTest, WorkDodajeDrewno) {
    ResourceManager rm;
    Woodcutter woodcutter(100, &rm, 10, 1);
    woodcutter.work();
    EXPECT_GT(rm.getResourceAmount(ResourceType::WOOD), 0);
}

TEST(WoodcutterTest, ConsumeBrakJedzeniaObniżaSzczescie) {
    ResourceManager rm;
    Woodcutter woodcutter(50, &rm, 10, 1);
    int szczescePrzed = woodcutter.getHappiness();
    woodcutter.consume();
    EXPECT_LT(woodcutter.getHappiness(), szczescePrzed);
}

TEST(StonecutterTest, WorkDodajeKamien) {
    ResourceManager rm;
    Stonecutter stonecutter(100, &rm, 6, 1);
    stonecutter.work();
    EXPECT_GT(rm.getResourceAmount(ResourceType::STONE), 0);
}

TEST(GuardTest, WorkZwiekszaBezpieczenstwo) {
    City city;
    ResourceManager rm;
    int bezpieczenstwoPrzed = city.getSafety();
    Guard guard(100, &city, &rm, 10, 1);
    guard.work();
    EXPECT_GT(city.getSafety(), bezpieczenstwoPrzed);
}

TEST(CitizenTest, UpdateHappinessDuzoJedzenia) {
    ResourceManager rm;
    Farmer farmer(50, &rm, 10, 1);
    int szczescePrzed = farmer.getHappiness();
    farmer.updateHappiness(30, 20, 80);
    EXPECT_GT(farmer.getHappiness(), szczescePrzed);
}

TEST(CitizenTest, UpdateHappinessBrakJedzenia) {
    ResourceManager rm;
    Farmer farmer(50, &rm, 10, 1);
    int szczescePrzed = farmer.getHappiness();
    farmer.updateHappiness(1, 1, 5);
    EXPECT_LT(farmer.getHappiness(), szczescePrzed);
}

TEST(CitizenTest, SzczescieMaksymalnie100) {
    ResourceManager rm;
    Farmer farmer(95, &rm, 10, 1);
    for (int i = 0; i < 20; i++) {
        farmer.updateHappiness(30, 20, 80);
    }
    EXPECT_LE(farmer.getHappiness(), 100);
}

TEST(CitizenTest, SzczescieMinimlanie0) {
    ResourceManager rm;
    Farmer farmer(5, &rm, 10, 1);
    for (int i = 0; i < 20; i++) {
        farmer.updateHappiness(1, 1, 5);
    }
    EXPECT_GE(farmer.getHappiness(), 0);
}
