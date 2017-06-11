#pragma once
#include "Dependencies\glfw\glfw3.h"
class Position
{
private:
	GLfloat x;
	GLfloat y;
public:
	Position();
	Position(GLfloat x, GLfloat y);
	GLfloat GetX();
	GLfloat GetY();
	void SetX(GLfloat x);
	void SetY(GLfloat y);
	Position CoordinateToPosition(int x, int y);
};