#include "Queen.h"

Queen::Queen()
{

}
Queen::Queen(int x, int y, Image image, int type, bool color) : Figure(x, y, image, type, color)
{

}

void Queen::OnPosition(int x, int y, Shader ourShader)
{
	this->image.PrintImage(x, y,ourShader);
}
Position& Queen::GetPosition()
{
	return this->position;
}
void Queen::Delete()
{
	image.DeleteImage();
}
Coordinate& Queen::GetCoordinate()
{
	return this->coordinate;
}
Coordinate& Queen::GetLastCoordinate()
{
	return this->lastCoordinate;
}
void Queen::Move()
{

	
}
bool Queen::GetColor()
{
	return this->color;
}
int Queen::GetType()
{
	return this->type;
}