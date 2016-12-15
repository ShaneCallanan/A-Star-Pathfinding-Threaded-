#pragma once

#include "BasicTypes.h"

struct GameSettings1
{
	const int fps = 0;
	const Size2D mapSize = Size2D(30, 30);
	const Rect npcZoneAsPercentage = Rect(0.57f, 0.11f, 0.38f, 0.5f);
	const int numNPCs = 5;
	const Rect playerZoneAsPercentage = Rect(0.075f, 0.32, 0.314f, 0.33f);
	const Size2D windowSize = Size2D(600, 600);
	const int numWalls = 3;
	const int numWallsTouchingBorder = 1;
	const float wallWidth = 1 / 30.0f;
	const float wallHeight = 0.8f;
	const int numWaypoints = 2;
};

struct GameSettings2
{
	const int fps = 0;
	const Size2D mapSize = Size2D(100, 100);
	const Rect npcZoneAsPercentage = Rect(0.57f, 0.11f, 0.38f, 0.5f);
	const int numNPCs = 50;
	const Rect playerZoneAsPercentage = Rect(0.075f, 0.32, 0.314f, 0.33f);
	const Size2D windowSize = Size2D(2000, 2000);
	const int numWalls = 6;
	const int numWallsTouchingBorder = 2;
	const float wallWidth = 1 / 60.0f;
	const float wallHeight = 0.8f;
	const int numWaypoints = 5;
};

struct GameSettings3
{
	const int fps = 0;
	const Size2D mapSize = Size2D(1000, 1000);
	const Rect npcZoneAsPercentage = Rect(0.57f, 0.11f, 0.38f, 0.5f);
	const int numNPCs = 500;
	const Rect playerZoneAsPercentage = Rect(0.075f, 0.32, 0.314f, 0.33f);
	const Size2D windowSize = Size2D(2000, 2000);
	const int numWalls = 18;
	const int numWallsTouchingBorder = 4;
	const float wallWidth = 1 / 100.0f;
	const float wallHeight = 0.8f;
	const int numWaypoints = 20;
};