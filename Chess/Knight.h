#pragma once
#include "Figure.h"
class Knight : public Figure
{
private:

public:
	Knight();
	Knight(int x, int y, Image image, int type, bool color);
	Coordinate& GetCoordinate();
	Coordinate& GetLastCoordinate();
	Position& GetPosition();
	int GetType();
	void Move();
	bool GetColor();
	void OnPosition(int x, int y, Shader ourShader);
	void Delete();
};