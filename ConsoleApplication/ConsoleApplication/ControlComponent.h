#pragma once

#include <string>
#include "Component.h"

using namespace std;


class ControlComponent : public Component
{
public:
	string input;

	ControlComponent();
	~ControlComponent() override;
};

