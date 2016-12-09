#pragma once

#include "BasicTypes.h"


struct GameSettings1
{
	const int fps = 0;
	const Size2D mapSize = Size2D(30, 30);
	const Rect npcZoneAsPercentage = Rect(0.57f, 0.11f, 0.38f, 0.5f);
	const int numNPCs = 5;
	const Rect playerZoneAsPercentage = Rect(0.075f, 0.32, 0.314f, 0.33f);
	const Size2D windowSize = Size2D(2000, 2000);

	const Rect wallsAsPercentage[3] = { Rect(0.235f, 0, 0.02f, 0.83f),
		Rect(0.46f, 0.11f, 0.02f, 0.775f),
		Rect(0.66f, 0.044f, 0.02f, 0.82f) };
};

struct GameSettings2
{
	const int fps = 0;
	const Size2D mapSize = Size2D(100, 100);
	const Rect npcZoneAsPercentage = Rect(0.57f, 0.11f, 0.38f, 0.5f);
	const int numNPCs = 50;
	const Rect playerZoneAsPercentage = Rect(0.075f, 0.32, 0.314f, 0.33f);
	const Size2D windowSize = Size2D(2000, 2000);
	
	const Rect wallsAsPercentage[3] = { Rect(0.235f, 0, 0.02f, 0.83f),
		Rect(0.46f, 0.11f, 0.02f, 0.775f),
		Rect(0.66f, 0.044f, 0.02f, 0.82f) };
};

struct GameSettings3
{
	const int fps = 0;
	const Size2D mapSize = Size2D(1000, 1000);
	const Rect npcZoneAsPercentage = Rect(0.57f, 0.11f, 0.38f, 0.5f);
	const int numNPCs = 500;
	const Rect playerZoneAsPercentage = Rect(0.075f, 0.32, 0.314f, 0.33f);
	const Size2D windowSize = Size2D(2000, 2000);

	const Rect wallsAsPercentage[18] = { Rect(0.05f, 0, 0.01f, 0.8f),
										Rect(0.1f, 0.2f, 0.01f, 0.8f),
										Rect(0.15f, 0, 0.01f, 0.8f),
										Rect(0.2f, 0.2f, 0.01f, 0.8f),
										Rect(0.25f, 0, 0.01f, 0.8f),
										Rect(0.3f, 0.2f, 0.01f, 0.8f),
										Rect(0.35f, 0, 0.01f, 0.8f),
										Rect(0.4f, 0.2f, 0.01f, 0.8f),
										Rect(0.45f, 0, 0.01f, 0.8f),
										Rect(0.5f, 0.2f, 0.01f, 0.8f),
										Rect(0.55f, 0, 0.01f, 0.8f),
										Rect(0.6f, 0.2f, 0.01f, 0.8f),
										Rect(0.65f, 0, 0.01f, 0.8f),
										Rect(0.7f, 0.2f, 0.01f, 0.8f),
										Rect(0.75f, 0, 0.01f, 0.8f),
										Rect(0.8f, 0.2f, 0.01f, 0.8f),
										Rect(0.85f, 0, 0.01f, 0.8f),
										Rect(0.9f, 0.2f, 0.01f, 0.8f) };
};