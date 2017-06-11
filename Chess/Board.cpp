#include "Board.h"

void Board::Create()
{
	//loading images of squares for the board
	
	blackSquare.CreateImage("Images/Black_Square.png");
	
	whiteSquare.CreateImage("Images/White_Square.png");
	//Creating board
	


}
void Board::Print(Shader ourShader)
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				blackSquare.PrintImage(i*DISTANCE_SQUARE_W, j*DISTANCE_SQUARE_H,ourShader);
			}
			else
			{
				whiteSquare.PrintImage(i*DISTANCE_SQUARE_W, j*DISTANCE_SQUARE_H,ourShader);
			}
		}
	}
}
void Board::Delete()
{
	blackSquare.DeleteImage();
	whiteSquare.DeleteImage();
}


