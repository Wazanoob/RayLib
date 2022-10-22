#pragma once

enum Direction {
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
	Snake(int x, int y, int size, int speed);
	~Snake();

	void Update();
	void Draw();

	int GetX() const;
	void SetX(int x);
	int GetSpeed() const;
	void SetSpeed(int x);

	int GetWidth() const;

private:
	int m_coordX;
	int m_coordY;
	int m_snakeSize;
	int m_bodyCount;
	float m_speedX;
	float m_speedY;
	Direction m_direction;
};

