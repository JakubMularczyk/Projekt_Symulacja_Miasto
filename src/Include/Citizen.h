#pragma once

class Citizen {
protected:
    int happinessLevel;
    int age;
    int healthLevel;

public:
    Citizen(int happinessLevel = 0, int age = 0, int healthLevel = 0);

    virtual ~Citizen() = default;

    virtual void work() = 0;
    virtual void consume() = 0;
};