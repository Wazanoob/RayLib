#pragma once
#include "raylib.h"

struct RectangleI
{
	int x;
	int y;
	int width;
	int height;
};

class Collisions
{
public:
	static bool AABBCollision(const RectangleI& rectA, const RectangleI& rectB)
	{
		int xMinA = rectA.x;
		int xMaxA = rectA.x + rectA.width;
		int yMinA = rectA.y;
		int yMaxA = rectA.y + rectA.height;
		int xMinB = rectB.x;
		int xMaxB = rectB.x + rectB.width;
		int yMinB = rectB.y;
		int yMaxB = rectB.y + rectB.height;

		return !(xMinA > xMaxB
			|| xMaxA < xMinB
			|| yMinA > yMaxB
			|| yMaxA < yMinB);
	}
};

