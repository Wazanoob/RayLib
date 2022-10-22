#pragma once
#include "Collisions.h"

enum class  Direction {
	RIGHT,
	DOWN,
	LEFT,
	UP,

	Default = 50
};

class Snake
{
public:
	Snake();
	Snake(int x, int y, int size, float speed);
	~Snake();

	RectangleI GetRect();

	void Update();
	void Draw();

	int GetX() const;
	int GetY() const;
	void Restart();

	void AddBody();
	void SetSpeed(float x);

	int GetWidth() const;

private:
	int m_coordX;
	int m_coordY;
	int m_snakeSize;
	int m_bodyCount;
	float m_speed;

	float m_timerStart;
	float m_timerLife;
	Direction m_direction;
	Direction m_nextDirection;
	Vector2 m_lastPos;

	bool PixelDelay();
};

