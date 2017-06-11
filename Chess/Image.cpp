#include "Image.h"


Image::Image()
{

	this->BLStartingPosition = Position(-0.95f, -0.95f);
	this->TRStartingPosition = Position(-0.83f, -0.71f);
	this->width = 0;
	this->height = 0;
	this->EBO = 0;
	this->path = NULL;
	this->texture = 0;
	this->VAO = 0;
	this->VBO = 0;
	
	//Shader ourShader;
}
void Image::CreateImage(const char* path, GLfloat BLx, GLfloat BLy, GLfloat TRx, GLfloat TRy)
{
	this->path = path;

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] =
	{        //position		     //texture
		TRx, TRy, 0.0f,        1.0f,1.0f, //Top Rigth
		TRx, BLy, 0.0f,   	 1.0f,0.0f, //Bottom Rigth
		BLx,BLy,0.0f,    	 0.0f,0.0f, //Bottom Left
		BLx,TRy,0.0f,		 	 0.0f,1.0f  //Top Left

	};

	GLuint indices[] =
	{
		0,1,3, //First Triangle
		1,2,3 // Second Triangle
	};

	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	//texture coordinate attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);



	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	
	
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

}
void Image::CreateImage(const char* path)
{

	this->path = path;

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] =
	{							//position														//texture
		this->TRStartingPosition.GetX(), this->TRStartingPosition.GetY(), 0.0f,			 1.0f, 1.0f, //Top Rigth
		this->TRStartingPosition.GetX(), this->BLStartingPosition.GetY(), 0.0f,   		 1.0f, 0.0f, //Bottom Rigth
		this->BLStartingPosition.GetX(), this->BLStartingPosition.GetY(), 0.0f,		   	 0.0f, 0.0f, //Bottom Left
		this->BLStartingPosition.GetX(), this->TRStartingPosition.GetY(), 0.0f,		 	 0.0f, 1.0f  //Top Left

	};

	GLuint indices[] =
	{
		0,1,3, //First Triangle
		1,2,3 // Second Triangle
	};


	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	//texture coordinate attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);



	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)



	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}
void Image::PrintImage(GLfloat x, GLfloat y,Shader ourShader)
{

		ourShader.Use();

		glm::mat4 transform;

		transform = glm::translate(transform, glm::vec3(x, y, 0.0f));
		GLint transformLocation = glGetUniformLocation(ourShader.Program, "transform");

		glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(transform));



		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture"), 0);

		// Draw our first triangle
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);


//		glm::mat4 transform;


}
void Image::PrintImage(Position position)
{
	Shader ourShader("core.vs", "core.frag");
	//ourShader.func("core.vs", "core.frag");
	ourShader.Use();

	glm::mat4 transform;

	transform = glm::translate(transform, glm::vec3(position.GetX(), position.GetY(), 0.0f));
	GLint transformLocation = glGetUniformLocation(ourShader.Program, "transform");

	glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(transform));


	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture"), 0);

	// Draw our first triangle
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
void Image::PrintImage(int x, int y,Shader ourShader)
{

	Position defautPosition(0.12f, 0.24f);

	ourShader.Use();

	glm::mat4 transform;

	transform = glm::translate(transform, glm::vec3(defautPosition.GetX() * x, defautPosition.GetY() * y, 0.0f));

	GLint transformLocation = glGetUniformLocation(ourShader.Program, "transform");

	glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(transform));

	    
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture"), 0);

	// Draw our first triangle
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}
void Image::DeleteImage()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
const char* Image::GetPath()
{
	return this->path;
}

