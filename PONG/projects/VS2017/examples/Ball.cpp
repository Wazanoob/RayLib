#include "Ball.h"
#include  "raylib.h"

Ball::Ball()
{
	m_coordX = 0;
	m_coordY = 0;
	m_ballSize = 32;

	m_speedX = 5;
	m_speedY = 5;
}

Ball::Ball(int x, int y, int size, int speed)
{
	m_coordX = x;
	m_coordY = y;
	m_ballSize = size;

	m_speedX = speed;
	m_speedY = speed;
}

Ball::~Ball()
{
}

RectangleI Ball::GetRect()
{
	return RectangleI{ m_coordX, m_coordY, m_ballSize, m_ballSize };
}

int Ball::GetX() const
{
	return m_coordX;
}

void Ball::SetX(int x)
{
	m_coordX = x;
}

int Ball::GetWidth() const
{
	return m_ballSize;
}

void Ball::HorizontalBounce(int newX)
{
	m_speedX = -m_speedX;
	m_coordX = newX;
}

void Ball::VerticalBounce(int newY)
{
	m_speedY = -m_speedY;
	m_coordY = newY;
}

void Ball::Update()
{
	m_coordX += m_speedX;
	m_coordY += m_speedY;

	int screenWidth = GetScreenWidth();
	int screenHeight = GetScreenHeight();

	//if (m_coordX < 0)
	//{
	//	HorizontalBounce(0);
	//}
	if (m_coordX > screenWidth - m_ballSize)
	{
		HorizontalBounce(screenWidth - m_ballSize);
	}	
	if (m_coordY < 0)
	{
		VerticalBounce(0);
	}
	if (m_coordY > screenHeight - m_ballSize)
	{
		VerticalBounce(screenHeight - m_ballSize);
	}
}

void Ball::Draw()
{
	DrawRectangle(m_coordX, m_coordY, m_ballSize, m_ballSize, WHITE);
}
