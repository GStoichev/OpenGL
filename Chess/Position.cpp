#include "Position.h"

Position::Position()
{
	this->x = -1.0f;
	this->y = -1.0f;
}
Position::Position(GLfloat x, GLfloat y)
{
	this->x = x;
	this->y = y;
}
GLfloat Position::GetX()
{
	return this->x;
}
GLfloat Position::GetY()
{
	return this->y;
}
void Position::SetX(GLfloat x)
{
	this->x = x;
}
void Position::SetY(GLfloat y)
{
	this->y = y;
}
Position Position::CoordinateToPosition(int x, int y)
{
	Position currentPosition;
	Position defaultPosition(0.12f, 0.24f);
	currentPosition.SetX(defaultPosition.GetX()*x);
	currentPosition.SetY(defaultPosition.GetY()*y);
	return currentPosition;

}