#include "RandomEvent.h"
RandomEvent::RandomEvent(int chance, std::string description, std::string name)
	: chance(chance), description(description), name(name) {
}

std::string RandomEvent::getDescription() const {
	return description;
}
int RandomEvent::getChance() const {
	return chance;
}
std::string RandomEvent::getName() const {
	return name;
}