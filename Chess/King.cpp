#include "King.h"
King::King()
{

}

King::King(int x, int y, Image image, int type, bool color) : Figure(x, y, image, type, color)
{

}
void King::OnPosition(int x, int y, Shader ourShader)
{
	this->image.PrintImage(x, y,ourShader);
}
Position& King::GetPosition()
{
	return this->position;
}
void King::Delete()
{
	image.DeleteImage();
}
Coordinate& King::GetCoordinate()
{
	return this->coordinate;
}
Coordinate& King::GetLastCoordinate()
{
	return this->lastCoordinate;
}
void King::Move()
{
	
}
bool King::GetColor()
{
	return this->color;
}
int King::GetType()
{
	return this->type;
}