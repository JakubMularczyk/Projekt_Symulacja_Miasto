#pragma once
#include "RandomEvent.h"
class NoEvent : public RandomEvent {
public:
	NoEvent();

	void execute(City& city, ResourceManager& resourceManager) override;

};
