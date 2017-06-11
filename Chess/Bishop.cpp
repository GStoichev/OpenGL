#include "Bishop.h"

Bishop::Bishop() : Figure()
{

}
Bishop::Bishop(int x, int y, Image image, int type, bool color) : Figure(x, y, image, type, color)
{

}
void Bishop::OnPosition(int x, int y, Shader ourShader) 
{
	
	/*this->coordinate.x = x;
	this->coordinate.y = y;*/
	this->image.PrintImage(x, y,ourShader);
	//std::cout << this->GetCoordinate().x << " : " <<this->GetCoordinate().y << std::endl;

}
Position& Bishop::GetPosition()
{
	return this->position;
}
void Bishop::OnPosition(GLfloat x, GLfloat y, Shader ourShader)
{
	this->image.PrintImage(x, y, ourShader);
}
void Bishop::OnPosition(Position position, Shader ourShader)
{
	this->image.PrintImage(position);
}

void Bishop::Delete()
{
	image.DeleteImage();
}
Coordinate& Bishop::GetCoordinate()
{
	return this->coordinate;
}
Coordinate& Bishop::GetLastCoordinate()
{
	return this->lastCoordinate;
}
void Bishop::Move()
{

}
bool Bishop::GetColor()
{
	return this->color;
}
int Bishop::GetType()
{
	return this->type;
}