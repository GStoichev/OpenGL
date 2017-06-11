#pragma once
#include "Figure.h"
class Rook : public Figure
{
private:
public:
	Rook();
	Rook(int x, int y, Image image, int type, bool color);
	Coordinate& GetCoordinate();
	Coordinate& GetLastCoordinate();
	Position& GetPosition();
	int GetType();
	void Move();
	bool GetColor();
	void OnPosition(int x, int y, Shader ourShader);
	void Delete();
};