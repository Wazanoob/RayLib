#pragma once
#include "Collisions.h"

class Apple
{
public:
	Apple();
	Apple(int x, int y, int size);
	~Apple();

	RectangleI GetRect();

	void Update();
	void Draw();

	int GetX() const;
	int GetY() const;
	void NextPos(Vector2 newPos);

	int GetWidth() const;

private:
	int m_coordX;
	int m_coordY;
	int m_appleSize;
};

