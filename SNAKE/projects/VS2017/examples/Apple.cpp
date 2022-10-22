#include "Apple.h"
#include "raylib.h"

Apple::Apple()
{
	m_coordX = 200;
	m_coordY = 320;
	m_appleSize = 32;
}

Apple::Apple(int x, int y, int size)
{
	m_coordX = x;
	m_coordY = y;
	m_appleSize = size;
}

Apple::~Apple()
{
}

RectangleI Apple::GetRect()
{
	return RectangleI{ m_coordX, m_coordY, m_appleSize, m_appleSize };
}

void Apple::Update()
{
}

void Apple::Draw()
{
	DrawRectangle(m_coordX, m_coordY, m_appleSize, m_appleSize, RED);
}

int Apple::GetX() const
{
	return m_coordX;
}

int Apple::GetY() const
{
	return m_coordY;
}

void Apple::NextPos(Vector2 newPos)
{
	m_coordX = newPos.x;
	m_coordY = newPos.y;
}

int Apple::GetWidth() const
{
	return m_appleSize;
}
