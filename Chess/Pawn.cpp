#include "Pawn.h"

Pawn::Pawn()
{

}
Pawn::Pawn(int x, int y, Image image, int type, bool color): Figure(x, y, image,type,color)
{

}
void Pawn::OnPosition(int x,int y,Shader ourShader)
{
	this->image.PrintImage(x, y,ourShader);
}
Position& Pawn::GetPosition()
{
	return this->position;
}
void Pawn::Delete()
{
	image.DeleteImage();
}
Coordinate& Pawn::GetCoordinate()
{
	return this->coordinate;
}
Image Pawn::GetImage()
{
	return this->image;
}
Coordinate& Pawn::GetLastCoordinate()
{
	return this->lastCoordinate;
}
void Pawn::Move()
{
	
}
int Pawn::GetType()
{
	return this->type;
}
bool Pawn::GetColor()
{
	return this->color;
}