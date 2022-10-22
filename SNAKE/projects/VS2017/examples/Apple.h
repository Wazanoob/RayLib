#pragma once
class Apple
{
public:
	Apple();
	Apple(int x, int y, int size);
	~Apple();

	void Update();
	void Draw();

	int GetX() const;
	void SetX(int x);

	int GetWidth() const;

private:
	int m_coordX;
	int m_coordY;
	int m_appleSize;
};

