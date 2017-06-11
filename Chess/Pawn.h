#pragma once
#include "Figure.h"
class Pawn : public Figure
{
private:
	bool capture;
public:
	Pawn();
	Pawn(int x, int y, Image image, int type, bool color);
	Coordinate& GetCoordinate();
	Coordinate& GetLastCoordinate();
	Position& GetPosition();
	int GetType();
	Image GetImage();
	bool GetColor();
	void Move();
	void OnPosition(int x, int y,Shader ourShader);
	void Delete();
};