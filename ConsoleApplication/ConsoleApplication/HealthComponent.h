#pragma once
#include "Component.h"


class HealthComponent : public Component
{
public:
	int minHealth = 0;
	int currentHealth = 100;

	HealthComponent();
	~HealthComponent() override;
};

