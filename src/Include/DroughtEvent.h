#pragma once
#pragma once
#include "RandomEvent.h"
class DroughtEvent : public RandomEvent {
public:
	DroughtEvent();

	void execute(City& city, ResourceManager& resourceManager) override;

};