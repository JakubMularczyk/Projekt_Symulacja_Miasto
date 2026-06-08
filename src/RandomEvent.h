#pragma once
#include <string>
#include <ResourceManager.h>

class City;
class RandomEvent {
protected:
	int  chance;// 0-100%
	std::string description;
	std::string name;

public:
	RandomEvent(int chance = 0, const std::string description = " ", const std::string name = "");
	std::string getDescription() {
		return description;
	}
	virtual ~RandomEvent() = default;
	std::string getDescription() const;
	int getChance() const;
	std::string getName() const;
		
	virtual void execute(City& city) = 0;
};