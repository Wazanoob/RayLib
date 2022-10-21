#include "Paddle.h"
#include  "raylib.h"

Paddle::Paddle()
{
	m_width = 32;
	m_height = 128;
	m_speedY = 4;
}

Paddle::Paddle(int x, int y, int width, int height, int speed)
{
	m_coordX = x;
	m_coordY = y;

	m_width = width;
	m_height = height;
	m_speedY = speed;
}

Paddle::~Paddle()
{
}

RectangleI Paddle::GetRect()
{
	return RectangleI{ m_coordX, m_coordY, m_width, m_height };
}

void Paddle::Update()
{
	int screenHeight = GetScreenHeight();

	if (IsKeyDown(KEY_UP))
	{
		m_coordY -= m_speedY;
		if (m_coordY < 0)
		{
			m_coordY = 0;
		}
	}
	if (IsKeyDown(KEY_DOWN))
	{
		m_coordY += m_speedY;
		if (m_coordY > screenHeight - m_height)
		{
			m_coordY = screenHeight - m_height;
		}
	}
}

void Paddle::Draw()
{
	DrawRectangle(m_coordX, m_coordY, m_width, m_height, WHITE);
}
