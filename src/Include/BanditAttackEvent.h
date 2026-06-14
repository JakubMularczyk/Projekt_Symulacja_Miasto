#pragma once
#include "RandomEvent.h"
class BanditAttackEvent : public RandomEvent {
public:
	BanditAttackEvent();

	void execute(City& city, ResourceManager& resourceManager) override;

};