#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Dependencies\glew\glew.h"

class Shader
{

public:
	GLuint Program;
	Shader();
	~Shader();
	// Constructor generates the shader on the fly
	Shader(const GLchar *vertexPath, const GLchar *fragmentPath);
		// Uses the current shader
	void Use();
};

#endif