#include "TextDisplay.h"

TextDisplay::TextDisplay(int x, int y, std::string text, int fontSize, Color color)
{
	m_coordX = x;
	m_coordY = y;
	m_text = text;
	m_fontSize = fontSize;
	m_color = color;
}

TextDisplay::~TextDisplay()
{

}

void TextDisplay::Draw()
{
	DrawText(m_text.c_str(), m_coordX, m_coordY, m_fontSize, m_color);
}

void TextDisplay::SetText(std::string text)
{
	m_text = text;
}
