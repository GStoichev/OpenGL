#include "Rook.h"

Rook::Rook()
{
}
Rook::Rook(int x, int y, Image image, int type, bool color) : Figure(x, y, image, type, color)
{
}

void Rook::OnPosition(int x, int y, Shader ourShader)
{
	this->image.PrintImage(x, y,ourShader);
}
Position& Rook::GetPosition()
{
	return this->position;
}
void Rook::Delete()
{
	image.DeleteImage();
}
Coordinate& Rook::GetCoordinate()
{
	return this->coordinate;
}
Coordinate& Rook::GetLastCoordinate()
{
	return this->lastCoordinate;
}
void Rook::Move()
{
//	this->coordinate.x = 3;
	
	
}
bool Rook::GetColor()
{
	return this->color;
}
int Rook::GetType()
{
	return this->type;
}