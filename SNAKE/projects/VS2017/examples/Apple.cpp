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

void Apple::Update()
{
}

void Apple::Draw()
{
	DrawRectangle(m_coordX, m_coordY, m_appleSize, m_appleSize, WHITE);
}

int Apple::GetX() const
{
	return m_coordX;
}

void Apple::SetX(int x)
{
	m_coordX = x;
}

int Apple::GetWidth() const
{
	return m_appleSize;
}
