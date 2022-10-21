#pragma once
#include "Collisions.h"

class Paddle
{
public:
	Paddle();
	Paddle(int x, int y, int width, int height, int speed);
	~Paddle();

	RectangleI GetRect();
	void Update();
	void Draw();

private:
	int m_coordX;
	int m_coordY;
	int m_width;
	int m_height;
	int m_speedY;
};

