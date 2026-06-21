#include <gtest/gtest.h>
#include "City.h"
#include "ResourceManager.h"

TEST(CityTest, PoczatkoweBezpieczenstwo) {
    City city;
    EXPECT_EQ(city.getSafety(), 40);
}

TEST(CityTest, ZmianaBezpieczenstwaWGore) {
    City city;
    city.changeSafety(20);
    EXPECT_EQ(city.getSafety(), 60);
}

TEST(CityTest, ZmianaBezpieczenstwaWDol) {
    City city;
    city.changeSafety(-20);
    EXPECT_EQ(city.getSafety(), 20);
}

TEST(CityTest, BezpieczenstwoNieSpadaPonizejZero) {
    City city;
    city.changeSafety(-100);
    EXPECT_EQ(city.getSafety(), 0);
}

TEST(CityTest, BezpieczenstwoNiePrzekracza100) {
    City city;
    city.changeSafety(200);
    EXPECT_EQ(city.getSafety(), 100);
}

TEST(CityTest, BrakZasobyNieKonczaGryOdRazu) {
    City city;
    ResourceManager rm;
    city.updateTurnsToCollapse(rm);
    EXPECT_FALSE(city.checkCollapseConditions());
}

TEST(CityTest, TrzyTuryBezJedzeniaKonczyGre) {
    City city;
    ResourceManager rm;
    city.updateTurnsToCollapse(rm);
    city.updateTurnsToCollapse(rm);
    city.updateTurnsToCollapse(rm);
    EXPECT_TRUE(city.checkCollapseConditions());
}

TEST(CityTest, TrzyTuryBezZlotaKonczyGre) {
    City city;
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 100);
    city.updateTurnsToCollapse(rm);
    city.updateTurnsToCollapse(rm);
    city.updateTurnsToCollapse(rm);
    EXPECT_TRUE(city.checkCollapseConditions());
}

TEST(CityTest, TrzyTuryBezBezpieczenstwaKonczyGre) {
    City city;
    ResourceManager rm;
    rm.addResource(ResourceType::FOOD, 100);
    rm.addResource(ResourceType::GOLD, 100);
    city.changeSafety(-40);
    city.updateTurnsToCollapse(rm);
    city.updateTurnsToCollapse(rm);
    city.updateTurnsToCollapse(rm);
    EXPECT_TRUE(city.checkCollapseConditions());
}

TEST(CityTest, OdzyskanieJedzeniaResetujeLicznikUpadku) {
    City city;
    ResourceManager rm;
    city.updateTurnsToCollapse(rm);
    city.updateTurnsToCollapse(rm);
    rm.addResource(ResourceType::FOOD, 100);
    rm.addResource(ResourceType::GOLD, 100);
    city.updateTurnsToCollapse(rm);
    EXPECT_FALSE(city.checkCollapseConditions());
}
