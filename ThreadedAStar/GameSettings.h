#pragma once

#include "BasicTypes.h"


struct GameSettings
{
	const int fps = 0;
	const Size2D mapSize = Size2D(100, 100);
	const Rect npcZoneAsPercentage = Rect(0.57f, 0.11f, 0.38f, 0.5f);
	const int numNPCs = 5;
	const Rect playerZoneAsPercentage = Rect(0.075f, 0.32, 0.314f, 0.33f);
	const Size2D windowSize = Size2D(2000, 2000);

	const Rect wallsAsPercentage[3] = { Rect(0.235f, 0, 0.02f, 0.83f), 
										Rect(0.46f, 0.11f, 0.02f, 0.775f), 
										Rect(0.66f, 0.044f, 0.02f, 0.82f) };
};