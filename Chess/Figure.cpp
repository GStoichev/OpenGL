#include "Figure.h"

Figure::Figure()
{
	this->coordinate.x = 0;
	this->coordinate.y = 0;
	this->BLStartinPostion = Position(-9.5f, -9.5f);
	this->TRStartingPosition = Position(-8.3f, -8.3f);
	this->type = 0;
	this->color = 0;
	this->moved = false;
}
Figure::Figure(int x, int y, Image image, int type, bool color)
{
	this->position = this->position.CoordinateToPosition(x, y);
	this->coordinate.x = x;
	this->coordinate.y = y;
	this->BLStartinPostion = Position(-9.5f, -9.5f);
	this->TRStartingPosition = Position(-8.3f, -8.3f);
	this->color = color;
	this->image = image;
	this->type = type;
	this->moved = false;
}
bool Figure::GetMoved()
{
	return this->moved;
}
void Figure::SetMoved(bool moved)
{
	this->moved = moved;
}
void Figure::OnPosition(int x, int y, Shader ourShader)
{
	this->image.PrintImage(x, y, ourShader);
}
int Figure::GetType()
{
	return this->type;
}

//bool Figure::GetColor()
//{
//	return this->color;
//}


