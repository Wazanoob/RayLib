#pragma once
#include "Collisions.h"

class Ball
{
public:
	Ball();
	Ball(int x, int y, int size, int speed);
	~Ball();

	RectangleI GetRect();

	int GetX() const;
	void SetX(int x);
	
	int GetWidth() const;

	void HorizontalBounce(int newX);
	void VerticalBounce(int newY);
	void Update();
	void Draw();

private:
	int m_coordX;
	int m_coordY;
	int m_ballSize;
	int m_speedX;
	int m_speedY;
};

