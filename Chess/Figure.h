#pragma once
#include "Dependencies\glew\glew.h"
#include "Position.h"
#include "String.h"
#include "Image.h"
#include "Coordinate.h"
#include "HelpMatrix.h"

class Figure
{
protected:
	Coordinate lastCoordinate;
	Position position;
	Coordinate coordinate;
	Position BLStartinPostion;
	Position TRStartingPosition;
	Image image;
	int type;
	bool color;
	bool moved;
	//void copyFunc(const Figure& figure);
public:
	
	Figure();
	Figure(int x,int y,Image image, int type, bool color);
	bool GetMoved();
	void SetMoved(bool moved);
	//Figure(Position position, Image image, String name, bool color);
	virtual Coordinate& GetCoordinate() = 0;
	virtual Coordinate& GetLastCoordinate() = 0;
	virtual int GetType() = 0;
	virtual void Move() = 0;
	virtual bool GetColor() = 0;
	virtual void Delete() = 0;
	void OnPosition(int x, int y, Shader ourShader);
	void OnPosition(GLfloat x, GLfloat y, Shader ourShader);
	virtual Position& GetPosition() = 0;


};