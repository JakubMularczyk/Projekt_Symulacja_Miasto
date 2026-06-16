#pragma once
#include "RandomEvent.h"
class PlagueEvent : public RandomEvent {
public:
	PlagueEvent();

	void execute(City& city, ResourceManager& resourceManager) override;

};