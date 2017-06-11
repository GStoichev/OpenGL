#pragma once
#include "Figure.h"
class Bishop : public Figure
{
private:

public:
	Bishop();
	Bishop(int x, int y, Image image, int type, bool color);
	Coordinate& GetCoordinate();
	Coordinate& GetLastCoordinate();
	Position& GetPosition();
	int GetType();
	void Move();
	bool GetColor();
	void OnPosition(int x, int y, Shader ourShader);
	void OnPosition(GLfloat x, GLfloat y, Shader ourShader);
	void OnPosition(Position position, Shader ourShader);
	void Delete();
};
