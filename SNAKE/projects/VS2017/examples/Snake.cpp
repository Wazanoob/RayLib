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

RectangleI Snake::GetRect()
{
	return RectangleI{ m_coordX, m_coordY, m_snakeSize, m_snakeSize };
}

void Snake::Update()
{
	int screenHeight = GetScreenHeight() - 16;
	int screenWidth = GetScreenWidth() - 16;

	switch (m_direction)
	{
	//Should add Sprites here :((((
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
}

void Snake::Draw()
{
	DrawRectangle(m_coordX, m_coordY, m_snakeSize, m_snakeSize, WHITE);

	if (m_bodyCount > 0)
	{
		for (size_t i = 0; i < m_bodyCount; i++)
		{
			//WIP
			DrawRectangle(m_lastPos.x, m_lastPos.y, m_snakeSize, m_snakeSize, GREEN);
		}
	}
}

int Snake::GetX() const
{
	return m_coordX;
}

int Snake::GetY() const
{
	return m_coordY;
}

void Snake::Restart()
{
	m_direction = Direction::Default;

	m_timerLife = 0.5f;
	m_bodyCount = 0;
	m_coordX = 384;
	m_coordY = 288;
}

void Snake::AddBody()
{
	++m_bodyCount;
}

void Snake::SetSpeed(float addSpeed)
{
	m_timerLife /= addSpeed;
}

int Snake::GetWidth() const
{
	return 0;
}

bool Snake::PixelDelay()
{
	if (GetTime() - m_timerStart >= m_timerLife)
	{
		m_lastPos.x = m_coordX;
		m_lastPos.y = m_coordY;

		return true;
	}
	else if (GetTime() - m_timerStart < m_timerLife)
	{
		return false;
	}
}
