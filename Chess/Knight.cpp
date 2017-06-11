#include "Knight.h"

Knight::Knight()
{

}
Knight::Knight(int x, int y, Image image, int type, bool color) : Figure(x, y, image, type, color)
{

}
void Knight::OnPosition(int x, int y, Shader ourShader)
{

	this->image.PrintImage(x, y,ourShader);
}
Position& Knight::GetPosition()
{
	return this->position;
}
void Knight::Delete()
{
	image.DeleteImage();
}
Coordinate& Knight::GetCoordinate()
{
	return this->coordinate;
}
Coordinate& Knight::GetLastCoordinate()
{
	return this->lastCoordinate;
}
void Knight::Move()
{

	
}
bool Knight::GetColor()
{
	return this->color;
}
int Knight::GetType()
{
	return this->type;
}
