#pragma once
#include "RandomEvent.h"
class FireEvent : public RandomEvent {
public:
	FireEvent();

	void execute(City& city) override;

};