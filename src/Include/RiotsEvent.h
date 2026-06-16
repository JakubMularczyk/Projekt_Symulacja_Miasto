#pragma once
#include "RandomEvent.h"
class RiotsEvent : public RandomEvent {
public:
	RiotsEvent();

	void execute(City& city, ResourceManager& resourceManager) override;

};
