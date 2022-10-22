#include "Snake.h"
#include "raylib.h"

Snake::Snake()
{
	m_coordX = 0;
	m_coordY = 0;
	m_snakeSize = 32;
	m_bodyCount = 0;

	m_timerStart = GetTime();
	m_timerLife = 0.5f;

	//No Movement before Start
	m_direction = Direction::Default;
}

Snake::Snake(int x, int y, int size, float speed)
{
	m_coordX = x;
	m_coordY = y;
	m_snakeSize = size;
	m_bodyCount = 0;

	m_timerStart = GetTime();
	m_timerLife = (1/ speed);

	//No Movement before Start
	m_direction = Direction::Default;
}

Snake::~Snake()
{
}

void Snake::Update()
{
	int screenHeight = GetScreenHeight() - 16;
	int screenWidth = GetScreenWidth() - 16;

	switch (m_direction)
	{
	case Direction::Default:
		if (IsKeyDown(KEY_UP))
		{
			m_direction = Direction::UP;
		}
		else if (IsKeyDown(KEY_DOWN))
		{
			m_direction = Direction::DOWN;
		}
		else if (IsKeyDown(KEY_LEFT))
		{
			m_direction = Direction::LEFT;
		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			m_direction = Direction::RIGHT;
		}
		break;
	case Direction::UP:
		if (PixelDelay())
		{
			m_coordY -= m_snakeSize;
			m_timerStart = GetTime();
		}
		if (IsKeyDown(KEY_LEFT))
		{
			m_direction = Direction::LEFT;
		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			m_direction = Direction::RIGHT;
		}
		break;
	case Direction::DOWN:
		if (PixelDelay())
		{
			m_coordY += m_snakeSize;
			m_timerStart = GetTime();
		}
		if (IsKeyDown(KEY_LEFT))
		{
			m_direction = Direction::LEFT;
		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			m_direction = Direction::RIGHT;
		}
		break;
	case Direction::LEFT:
		if (PixelDelay())
		{
			m_coordX -= m_snakeSize;
			m_timerStart = GetTime();
		}
		if (IsKeyDown(KEY_UP))
		{
			m_direction = Direction::UP;
		}
		else if (IsKeyDown(KEY_DOWN))
		{
			m_direction = Direction::DOWN;
		}
		break;
	case Direction::RIGHT:
		if (PixelDelay())
		{
			m_coordX += m_snakeSize;
			m_timerStart = GetTime();
		}
		if (IsKeyDown(KEY_UP))
		{
			m_direction = Direction::UP;
		}
		else if (IsKeyDown(KEY_DOWN))
		{
			m_direction = Direction::DOWN;
		}
		break;
	}




	//if (IsKeyDown(KEY_UP))
	//{
	//	m_coordY -= m_speedY;
	//}
	//else if (IsKeyDown(KEY_DOWN))
	//{
	//	m_coordY += m_speedY;
	//}
	//else if (IsKeyDown(KEY_LEFT))
	//{
	//	m_coordX -= m_speedX;
	//}
	//else if (IsKeyDown(KEY_RIGHT))
	//{
	//	m_coordX += m_speedX;
	//}
}

void Snake::Draw()
{
	DrawRectangle(m_coordX, m_coordY, m_snakeSize, m_snakeSize, WHITE);
}

int Snake::GetX() const
{
	return 0;
}

void Snake::SetX(int x)
{
}

int Snake::GetSpeed() const
{
	return 0;
}

void Snake::SetSpeed(int x)
{
}

int Snake::GetWidth() const
{
	return 0;
}

bool Snake::PixelDelay()
{
	if (GetTime() - m_timerStart >= m_timerLife)
	{
		return true;
	}
	else if (GetTime() - m_timerStart < m_timerLife)
	{
		return false;
	}
}
