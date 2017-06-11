#pragma once



#include "Shader.h"
#include "Dependencies\SOIL2\SOIL2.h"
#include "Dependencies\glfw\glfw3.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"
#include "Position.h"
#include "String.h"
class Image
{
private:

	//	Shader ourShader;
	Position BLStartingPosition;
	Position TRStartingPosition;
	int width;
	int height;
	GLuint VBO;
	GLuint VAO;
	GLuint EBO;
	GLuint texture;
	const char* path;

public:
	Image();
	void CreateImage(const char* path, GLfloat BLx, GLfloat BLy, GLfloat TRx, GLfloat TRy);
	void CreateImage(const char* path);
	void PrintImage(int x, int y,Shader ourShader);
	void PrintImage(GLfloat x, GLfloat y,Shader ourShader);
	void PrintImage(Position position);
	void DeleteImage();
	const char* GetPath();


};
