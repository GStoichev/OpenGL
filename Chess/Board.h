#pragma once
#include "Dependencies\glew\glew.h"
#include "Dependencies\glfw\glfw3.h"
#include "Position.h"
#include "Image.h"


class Board
{
private:
	const GLfloat DISTANCE_SQUARE_H = 0.24f;
	const GLfloat DISTANCE_SQUARE_W = 0.12f;
	Image blackSquare;
	Image whiteSquare;
public:
	void Create();
	void Print(Shader ourShader);
	void Delete();
};