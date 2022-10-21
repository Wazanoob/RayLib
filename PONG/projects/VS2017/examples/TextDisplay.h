#pragma once
#include "raylib.h"
#include <string>

using std::string;

class TextDisplay
{
public:
	TextDisplay() = delete;
	TextDisplay(int x, int y, string text, int fontSize, Color color);
	~TextDisplay();

	void Draw();

	void SetText(string text);

private:
	int m_coordX;
	int m_coordY;
	string m_text;
	int m_fontSize;
	Color m_color;
};

