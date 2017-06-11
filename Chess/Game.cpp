#include "Game.h"

void Game::InitzializeBoard()
{

	this->chessBoard.Create();
}
bool Game::FigureAt(Coordinate coordinate)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->arr[i]->GetCoordinate().x == coordinate.x &&  this->arr[i]->GetCoordinate().y == coordinate.y)
		{
			return true;
		}
	}
	return false;
}
bool Game::FigureAt(Coordinate coordinate, bool color)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->arr[i]->GetCoordinate().x == coordinate.x &&  this->arr[i]->GetCoordinate().y == coordinate.y && color == this->arr[i]->GetColor() )
		{
			return true;
		}
	}
	return false;
}
bool Game::FigureAt(int x, int y,int figure)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (i == figure)
		{
			continue;
		}
		if (this->arr[i]->GetCoordinate().x == x && this->arr[i]->GetCoordinate().y == y)
		{
			return true;
		}
		
	}
	return false;
}
bool Game::FigureAt(int x, int y, int figure, bool color)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (i == figure)
		{
			continue;
		}
		if ( this->arr[i]->GetColor() == color && this->arr[i]->GetCoordinate().x == x && this->arr[i]->GetCoordinate().y == y)
		{
			return true;
		}

	}
	return false;
}
int Game::FigureAt(int x, int y, bool color)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->arr[i]->GetColor() == color && this->arr[i]->GetCoordinate().x == x && this->arr[i]->GetCoordinate().y == y)
		{
			return i;
		}
	}
	
}
int Game::GetFigureAt(int x, int y, int figure)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (figure == i)
		{
			continue;
		}
		if (this->arr[i]->GetCoordinate().x == x && this->arr[i]->GetCoordinate().y == y)
		{
			return i;
		}
	}
}
void Game::InitzializeFugures()
{

}
int Game::GetLength()
{
	return this->size;
}

Figure** Game::GetArr()
{
	return this->arr;
}
Board Game::GetChessBoard()
{
	return this->chessBoard;
}


Game::Game()
{
	this->player = true;
	this->size = 0;
	this->capacity = 4;
	this->arr = new Figure*[this->capacity];
	for (size_t i = 0; i < this->capacity; i++)
	{
		this->arr[i] = NULL;
	}
	this->countTimesOfNotMovedOrCapturePawn = 0;
	this->GAMEOVER = 0;
}
int Game::IsGameOver()
{
	return this->GAMEOVER;
}
Game::~Game()
{
	delete[] arr;
}
void Game::ReSize()
{
	this->capacity *= 2;
	Figure** temp = new Figure*[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = temp;

}
void Game::AddFigure(Figure& figure)
{
	if (this->size == this->capacity)
	{
		this->ReSize();
	}
	this->arr[size++] = &figure;
}
void Game::DeleteBoard()
{
	this->chessBoard.Delete();
}
void Game::DeleteFigures()
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i]->Delete();
	}
}
bool Game::GetPlayer()
{
	return this->player;
}
int Game::GetKing(bool color)
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->arr[i]->GetColor() == color && this->arr[i]->GetType() == 6)
		{
			return i;
		}
	}
}
int Game::Attacker(int figure)
{
	//int figure = -1;

	//check what is figure from right 
	for (size_t i = this->arr[figure]->GetCoordinate().x + 1; i < 8; i++)
	{
		if (this->FigureAt(i, this->arr[figure]->GetCoordinate().y, figure))
		{
			int fig = this->GetFigureAt(i, this->arr[figure]->GetCoordinate().y, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return fig;
			}
			break;
		}
	}
	//check what is figure from left
	for (int i = this->arr[figure]->GetCoordinate().x - 1; i >= 0; i--)
	{
		if (this->FigureAt(i, this->arr[figure]->GetCoordinate().y, figure))
		{
			int fig = this->GetFigureAt(i, this->arr[figure]->GetCoordinate().y, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return fig;
			}
			break;
		}
	}
	//check what is figure from top 
	for (size_t i = this->arr[figure]->GetCoordinate().y + 1; i < 8; i++)
	{
		if (this->FigureAt(this->arr[figure]->GetCoordinate().x, i, figure))
		{
			int fig = this->GetFigureAt(this->arr[figure]->GetCoordinate().x, i, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return fig;
			}
			break;
		}
	}
	//check what is figure from bottom 
	for (int i = this->arr[figure]->GetCoordinate().y - 1; i >= 0; i--)
	{
		if (this->FigureAt(this->arr[figure]->GetCoordinate().x, i, figure))
		{
			int fig = this->GetFigureAt(this->arr[figure]->GetCoordinate().x, i, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return fig;
			}
			break;
		}
	}
	//Check for figure from right-top
	for (size_t i = this->arr[figure]->GetCoordinate().x + 1, j = this->arr[figure]->GetCoordinate().y + 1; i < 8 && j < 8; i++, j++)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == true && i == this->arr[figure]->GetCoordinate().x + 1 && j == this->arr[figure]->GetCoordinate().y + 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return fig;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return fig;
				}
			}

			break;
		}
	}
	//Check for figure from left-top
	for (int i = this->arr[figure]->GetCoordinate().x - 1, j = this->arr[figure]->GetCoordinate().y + 1; i >= 0 && j < 8; i--, j++)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == true && i == this->arr[figure]->GetCoordinate().x - 1 && j == this->arr[figure]->GetCoordinate().y + 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return fig;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return fig;
				}
			}
			break;
		}
	}
	//Check for figure from left-bottom
	for (int i = this->arr[figure]->GetCoordinate().x - 1, j = this->arr[figure]->GetCoordinate().y - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == false && i == this->arr[figure]->GetCoordinate().x - 1 && j == this->arr[figure]->GetCoordinate().y - 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return fig;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return fig;
				}
			}

			break;
		}
	}
	//Check for figure from right-bottom
	for (int i = this->arr[figure]->GetCoordinate().x + 1, j = this->arr[figure]->GetCoordinate().y - 1; i < 8 && j >= 0; i++, j--)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == false && i == this->arr[figure]->GetCoordinate().x + 1 && j == this->arr[figure]->GetCoordinate().y - 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return fig;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return fig;
				}
			}

			break;
		}
	}
	//Check for knight
	int currentX = this->arr[figure]->GetCoordinate().x;
	int currentY = this->arr[figure]->GetCoordinate().y;
	if (FigureAt(currentX + 1, currentY + 2, figure))
	{
		int fig = this->GetFigureAt(currentX + 1, currentY + 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return fig;
		}
	}
	if (FigureAt(currentX + 2, currentY + 1, figure))
	{
		int fig = this->GetFigureAt(currentX + 2, currentY + 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return fig;
		}
	}
	if (FigureAt(currentX - 1, currentY + 2, figure))
	{
		int fig = this->GetFigureAt(currentX - 1, currentY + 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return fig;
		}
	}
	if (FigureAt(currentX + 1, currentY - 2, figure))
	{
		int fig = this->GetFigureAt(currentX + 1, currentY - 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return fig;
		}
	}
	if (FigureAt(currentX - 2, currentY + 1, figure))
	{
		int fig = this->GetFigureAt(currentX - 2, currentY + 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return fig;
		}
	}
	if (FigureAt(currentX + 2, currentY - 1, figure))
	{
		int fig = this->GetFigureAt(currentX + 2, currentY - 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return fig;
		}
	}
	if (FigureAt(currentX - 2, currentY - 1, figure))
	{
		int fig = this->GetFigureAt(currentX - 2, currentY - 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return fig;
		}
	}
	if (FigureAt(currentX - 1, currentY - 2, figure))
	{
		int fig = this->GetFigureAt(currentX - 1, currentY - 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return fig;
		}
	}
	return -1;
}
bool Game::CanFigureMoveTo(int x, int y, int figure)
{
	bool check = false;


	//check what is figure from right 
	for (size_t i = this->arr[figure]->GetCoordinate().x + 1; i < 8; i++)
	{
		if (this->FigureAt(i, this->arr[figure]->GetCoordinate().y, figure))
		{
			int fig = this->GetFigureAt(i, this->arr[figure]->GetCoordinate().y, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}
	//check what is figure from left
	for (int i = this->arr[figure]->GetCoordinate().x - 1; i >= 0; i--)
	{
		if (this->FigureAt(i, this->arr[figure]->GetCoordinate().y, figure))
		{
			int fig = this->GetFigureAt(i, this->arr[figure]->GetCoordinate().y, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}
	//check what is figure from top 
	int count = 0;
	for (size_t i = this->arr[figure]->GetCoordinate().y + 1; i < 8; i++)
	{
		count++;
		if (this->FigureAt(this->arr[figure]->GetCoordinate().x, i, figure))
		{
			int fig = this->GetFigureAt(this->arr[figure]->GetCoordinate().x, i, figure);
			int type = this->arr[fig]->GetType();
			bool pawnBlock = (((type == 1) && (count == 1)) || ((this->arr[fig]->GetCoordinate().y == 1) && count == 2));
			if (this->arr[fig]->GetColor() && (this->arr[fig]->GetCoordinate().y > this->arr[figure]->GetCoordinate().y))
			{
				pawnBlock = false;
			}
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (pawnBlock || type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}

	//check what is figure from bottom 
	count = 0;
	for (int i = this->arr[figure]->GetCoordinate().y - 1; i >= 0; i--)
	{
		count++;
		if (this->FigureAt(this->arr[figure]->GetCoordinate().x, i, figure))
		{
			int fig = this->GetFigureAt(this->arr[figure]->GetCoordinate().x, i, figure);
			int type = this->arr[fig]->GetType();
			bool pawnBlock = (( (type == 1) && (count == 1) ) || ((this->arr[fig]->GetCoordinate().y == 1) && count == 2));
			if (!(this->arr[fig]->GetColor()) && (this->arr[fig]->GetCoordinate().y < this->arr[figure]->GetCoordinate().y))
			{
				pawnBlock = false;
			}
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && ( pawnBlock || type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}
	//Check for figure from right-top
	for (size_t i = this->arr[figure]->GetCoordinate().x + 1, j = this->arr[figure]->GetCoordinate().y + 1; i < 8 && j < 8; i++, j++)
	{
		if (this->FigureAt(i, j, figure))
		{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			

			break;
		}
	}
	//Check for figure from left-top
	for (int i = this->arr[figure]->GetCoordinate().x - 1, j = this->arr[figure]->GetCoordinate().y + 1; i >= 0 && j < 8; i--, j++)
	{
		if (this->FigureAt(i, j, figure))
		{
			
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			
			break;
		}
	}
	//Check for figure from left-bottom
	for (int i = this->arr[figure]->GetCoordinate().x - 1, j = this->arr[figure]->GetCoordinate().y - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (this->FigureAt(i, j, figure))
		{
			
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			

			break;
		}
	}
	//Check for figure from right-bottom
	for (int i = this->arr[figure]->GetCoordinate().x + 1, j = this->arr[figure]->GetCoordinate().y - 1; i < 8 && j >= 0; i++, j--)
	{
		if (this->FigureAt(i, j, figure))
		{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			

			break;
		}
	}
	//Check for knight
	int currentX = this->arr[figure]->GetCoordinate().x;
	int currentY = this->arr[figure]->GetCoordinate().y;
	if (FigureAt(currentX + 1, currentY + 2, figure))
	{
		int fig = this->GetFigureAt(currentX + 1, currentY + 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX + 2, currentY + 1, figure))
	{
		int fig = this->GetFigureAt(currentX + 2, currentY + 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 1, currentY + 2, figure))
	{
		int fig = this->GetFigureAt(currentX - 1, currentY + 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX + 1, currentY - 2, figure))
	{
		int fig = this->GetFigureAt(currentX + 1, currentY - 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 2, currentY + 1, figure))
	{
		int fig = this->GetFigureAt(currentX - 2, currentY + 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX + 2, currentY - 1, figure))
	{
		int fig = this->GetFigureAt(currentX + 2, currentY - 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 2, currentY - 1, figure))
	{
		int fig = this->GetFigureAt(currentX - 2, currentY - 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 1, currentY - 2, figure))
	{
		int fig = this->GetFigureAt(currentX - 1, currentY - 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	return check;
}
bool Game::isMate(bool color)
{
	bool mate = false;
	int king = this->GetKing(color);
//	bool check = this->checkForCheck(king);
	if (this->checkForCheck(king))
	{
		
		bool check = false;
		bool freeTile = false;
		int currentX = this->arr[king]->GetCoordinate().x;
		int currentY = this->arr[king]->GetCoordinate().y;
		int previuseX = currentX;
		int previuseY = currentY;
		//can king move
		for (int i = currentX - 1; i <= currentX+1; i++)
		{
			for (int j = currentY - 1; j <= currentY+1; j++)
			{
				if (i < 0 || j < 0 || i > 7 || j > 7)
				{
					continue;
				}
				if (FigureAt(i,j,king,color))
				{
					continue;
				}
				if (FigureAt(i,j,king,!(color)))
				{
					this->arr[king]->GetCoordinate().x = i;
					this->arr[king]->GetCoordinate().y = j;
					if (checkForCheck(king))
					{
						this->arr[king]->GetCoordinate().x = previuseX;
						this->arr[king]->GetCoordinate().y = previuseY;
						continue;
					}
					this->arr[king]->GetCoordinate().x = previuseX;
					this->arr[king]->GetCoordinate().y = previuseY;
				}
				this->arr[king]->GetCoordinate().x = i;
				this->arr[king]->GetCoordinate().y = j;
				if (checkForCheck(king))
				{
					this->arr[king]->GetCoordinate().x = previuseX;
					this->arr[king]->GetCoordinate().y = previuseY;
					continue;
				}
				this->arr[king]->GetCoordinate().x = previuseX;
				this->arr[king]->GetCoordinate().y = previuseY;
				return false;
			}
		}
		this->arr[king]->GetCoordinate().x = previuseX;
		this->arr[king]->GetCoordinate().y = previuseY;
		//if king dont have place for moving
		int fig = this->Attacker(king);
		//second phase
		
		if (checkForCheckForMate(fig))
		{
			return false;
		}
		
		//third phase
		if (this->arr[fig]->GetType() == 2 || this->arr[fig]->GetType() == 5)
		{
			int otherKing = this->GetKing(!(this->arr[king]->GetColor()));
			int otherKingPrevX = this->arr[otherKing]->GetCoordinate().x;
			int otherKingPrevY = this->arr[otherKing]->GetCoordinate().y;
			//right
			if (this->arr[fig]->GetCoordinate().x > this->arr[king]->GetCoordinate().x)
			{
				for (size_t i = this->arr[king]->GetCoordinate().x + 1; i < this->arr[fig]->GetCoordinate().x; i++)
				{
					this->arr[otherKing]->GetCoordinate().x = i;
					this->arr[otherKing]->GetCoordinate().y = this->arr[king]->GetCoordinate().y;
					if (CanFigureMoveTo(i, this->arr[otherKing]->GetCoordinate().y, otherKing))
					{
						this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
						this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
						return false;
					}
					this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
					this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
				}
			}
			//top
			else if (this->arr[fig]->GetCoordinate().y > this->arr[king]->GetCoordinate().y)
			{
				for (size_t i = this->arr[king]->GetCoordinate().y + 1; i < this->arr[fig]->GetCoordinate().y; i++)
				{
					this->arr[otherKing]->GetCoordinate().y = i;
					if (CanFigureMoveTo(this->arr[otherKing]->GetCoordinate().x, i, otherKing))
					{
						this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
						return false;
					}
					this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
				}
			}
			//left
			else if (this->arr[fig]->GetCoordinate().x < this->arr[king]->GetCoordinate().x)
			{
				for (size_t i = this->arr[king]->GetCoordinate().y - 1; i < this->arr[fig]->GetCoordinate().y; i--)
				{
					this->arr[otherKing]->GetCoordinate().x = i;
					if (CanFigureMoveTo(this->arr[otherKing]->GetCoordinate().x, i, otherKing))
					{
						this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
						return false;
					}
					this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
				}
			}
			//bot
			else if (this->arr[fig]->GetCoordinate().y < this->arr[king]->GetCoordinate().y)
			{
				for (size_t i = this->arr[king]->GetCoordinate().y - 1; i < this->arr[fig]->GetCoordinate().y; i--)
				{
					this->arr[otherKing]->GetCoordinate().y = i;
					if (CanFigureMoveTo(this->arr[otherKing]->GetCoordinate().x, i, otherKing))
					{
						this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
						return false;
					}
					this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
				}
			}
			
			//checking all coordinates from king to attacker
			
			
		}
		else if(this->arr[fig]->GetType() == 3 || this->arr[fig]->GetType() == 5)
		{
			int otherKing = this->GetKing(!(this->arr[king]->GetColor()));
			int otherKingPrevX = this->arr[otherKing]->GetCoordinate().x;
			int otherKingPrevY = this->arr[otherKing]->GetCoordinate().y;
			//top - right
			if ((this->arr[fig]->GetCoordinate().x > this->arr[king]->GetCoordinate().x) && (this->arr[fig]->GetCoordinate().y > this->arr[king]->GetCoordinate().y))
			{
				for (size_t i = this->arr[king]->GetCoordinate().x + 1, j = this->arr[king]->GetCoordinate().y + 1; i < this->arr[fig]->GetCoordinate().x; i++, j++)
				{
					this->arr[otherKing]->GetCoordinate().x = i;
					this->arr[otherKing]->GetCoordinate().y = j;
					if (CanFigureMoveTo(this->arr[otherKing]->GetCoordinate().x, this->arr[otherKing]->GetCoordinate().y, otherKing))
					{
						this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
						this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
						return false;
					}
					this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
					this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
				}
			}
			//top left
			else if((this->arr[fig]->GetCoordinate().x < this->arr[king]->GetCoordinate().x) && (this->arr[fig]->GetCoordinate().y > this->arr[king]->GetCoordinate().y))
			{
				for (size_t i = this->arr[king]->GetCoordinate().x - 1, j = this->arr[king]->GetCoordinate().y + 1; i > this->arr[fig]->GetCoordinate().x; i--, j++)
				{
					this->arr[otherKing]->GetCoordinate().x = i;
					this->arr[otherKing]->GetCoordinate().y = j;
					if (CanFigureMoveTo(this->arr[otherKing]->GetCoordinate().x, this->arr[otherKing]->GetCoordinate().y, otherKing))
					{
						this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
						this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
						return false;
					}
					this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
					this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
				}
			}
			else if ((this->arr[fig]->GetCoordinate().x < this->arr[king]->GetCoordinate().x) && (this->arr[fig]->GetCoordinate().y < this->arr[king]->GetCoordinate().y))
			{
				for (size_t i = this->arr[king]->GetCoordinate().x - 1, j = this->arr[king]->GetCoordinate().y - 1; i > this->arr[fig]->GetCoordinate().x; i--, j--)
				{
					this->arr[otherKing]->GetCoordinate().x = i;
					this->arr[otherKing]->GetCoordinate().y = j;
					if (CanFigureMoveTo(this->arr[otherKing]->GetCoordinate().x, this->arr[otherKing]->GetCoordinate().y, otherKing))
					{
						this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
						this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
						return false;
					}
					this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
					this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
				}
			}
			else if ((this->arr[fig]->GetCoordinate().x > this->arr[king]->GetCoordinate().x) && (this->arr[fig]->GetCoordinate().y < this->arr[king]->GetCoordinate().y))
			{
				for (size_t i = this->arr[king]->GetCoordinate().x + 1, j = this->arr[king]->GetCoordinate().y - 1; i < this->arr[fig]->GetCoordinate().x; i++, j--)
				{
					this->arr[otherKing]->GetCoordinate().x = i;
					this->arr[otherKing]->GetCoordinate().y = j;
					if (CanFigureMoveTo(this->arr[otherKing]->GetCoordinate().x, this->arr[otherKing]->GetCoordinate().y, otherKing))
					{
						this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
						this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
						return false;
					}
					this->arr[otherKing]->GetCoordinate().x = otherKingPrevX;
					this->arr[otherKing]->GetCoordinate().y = otherKingPrevY;
				}
			}
			
		}
		mate = true;

	}
	return mate;
}
bool Game::checkForCheck(int figure)
{
	bool check = false;

	//check for other king
	int otherKing = this->GetKing(!(this->arr[figure]->GetColor()));
	if (std::abs(this->arr[figure]->GetCoordinate().x - this->arr[otherKing]->GetCoordinate().x) <= 1 && std::abs(this->arr[figure]->GetCoordinate().y - this->arr[otherKing]->GetCoordinate().y) <= 1)
	{
		return true;
	}
	//check what is figure from right 
	for (size_t i = this->arr[figure]->GetCoordinate().x + 1 ; i < 8; i++)
	{
		if (this->FigureAt(i,this->arr[figure]->GetCoordinate().y,figure))
		{
			int fig = this->GetFigureAt(i, this->arr[figure]->GetCoordinate().y, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5) )
			{
				return true;
			}
			break;
		}
	}
	//check what is figure from left
	for (int i = this->arr[figure]->GetCoordinate().x - 1; i >= 0; i--)
	{
		if (this->FigureAt(i, this->arr[figure]->GetCoordinate().y, figure))
		{
			int fig = this->GetFigureAt(i, this->arr[figure]->GetCoordinate().y, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}
	//check what is figure from top 
	for (size_t i = this->arr[figure]->GetCoordinate().y + 1; i < 8; i++)
	{
		if (this->FigureAt(this->arr[figure]->GetCoordinate().x, i, figure))
		{
			int fig = this->GetFigureAt(this->arr[figure]->GetCoordinate().x, i, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}
	//check what is figure from bottom 
	for (int i = this->arr[figure]->GetCoordinate().y - 1; i >= 0; i--)
	{
		if (this->FigureAt(this->arr[figure]->GetCoordinate().x, i, figure))
		{
			int fig = this->GetFigureAt(this->arr[figure]->GetCoordinate().x, i, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}
	//Check for figure from right-top
	for (size_t i = this->arr[figure]->GetCoordinate().x + 1 , j = this->arr[figure]->GetCoordinate().y + 1; i < 8 && j < 8 ; i++, j++)
	{
		if (this->FigureAt(i, j, figure))
		{ 
			if (this->arr[figure]->GetColor() == true && i == this->arr[figure]->GetCoordinate().x + 1 &&  j == this->arr[figure]->GetCoordinate().y + 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 ||  type == 4 || type == 5))
				{
					return true;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			}
			
			break;
		}
	}
	//Check for figure from left-top
	for (int i = this->arr[figure]->GetCoordinate().x - 1, j = this->arr[figure]->GetCoordinate().y + 1; i >= 0 && j < 8; i--, j++)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == true && i == this->arr[figure]->GetCoordinate().x - 1 && j == this->arr[figure]->GetCoordinate().y + 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return true;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			}
			break;
		}
	}
	//Check for figure from left-bottom
	for (int i = this->arr[figure]->GetCoordinate().x - 1, j = this->arr[figure]->GetCoordinate().y - 1; i >= 0 && j >=  0; i--, j--)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == false && i == this->arr[figure]->GetCoordinate().x - 1 && j == this->arr[figure]->GetCoordinate().y - 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return true;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			}
			
			break;
		}
	}
	//Check for figure from right-bottom
	for (int i = this->arr[figure]->GetCoordinate().x + 1, j = this->arr[figure]->GetCoordinate().y - 1; i < 8 && j >= 0; i++, j--)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == false && i == this->arr[figure]->GetCoordinate().x + 1 && j == this->arr[figure]->GetCoordinate().y - 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return true;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			}
			
			break;
		}
	}
	//Check for knight
	int currentX = this->arr[figure]->GetCoordinate().x;
	int currentY = this->arr[figure]->GetCoordinate().y;
	if (FigureAt(currentX + 1, currentY + 2, figure))
	{
		int fig = this->GetFigureAt(currentX + 1, currentY + 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX + 2, currentY + 1, figure))
	{
		int fig = this->GetFigureAt(currentX + 2, currentY + 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 1, currentY + 2, figure))
	{
		int fig = this->GetFigureAt(currentX - 1, currentY + 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX + 1, currentY - 2, figure))
	{
		int fig = this->GetFigureAt(currentX + 1, currentY - 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 2, currentY + 1, figure))
	{
		int fig = this->GetFigureAt(currentX - 2, currentY + 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX + 2, currentY - 1, figure))
	{
		int fig = this->GetFigureAt(currentX + 2, currentY - 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 2, currentY - 1, figure))
	{
		int fig = this->GetFigureAt(currentX - 2, currentY - 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 1, currentY - 2, figure))
	{
		int fig = this->GetFigureAt(currentX - 1, currentY - 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	return check;
}
bool Game::checkForCheckForMate(int figure)
{
	bool check = false;

	//check for other king

	//check what is figure from right 
	for (size_t i = this->arr[figure]->GetCoordinate().x + 1; i < 8; i++)
	{
		if (this->FigureAt(i, this->arr[figure]->GetCoordinate().y, figure))
		{
			int fig = this->GetFigureAt(i, this->arr[figure]->GetCoordinate().y, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}
	//check what is figure from left
	for (int i = this->arr[figure]->GetCoordinate().x - 1; i >= 0; i--)
	{
		if (this->FigureAt(i, this->arr[figure]->GetCoordinate().y, figure))
		{
			int fig = this->GetFigureAt(i, this->arr[figure]->GetCoordinate().y, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}
	//check what is figure from top 
	for (size_t i = this->arr[figure]->GetCoordinate().y + 1; i < 8; i++)
	{
		if (this->FigureAt(this->arr[figure]->GetCoordinate().x, i, figure))
		{
			int fig = this->GetFigureAt(this->arr[figure]->GetCoordinate().x, i, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}
	//check what is figure from bottom 
	for (int i = this->arr[figure]->GetCoordinate().y - 1; i >= 0; i--)
	{
		if (this->FigureAt(this->arr[figure]->GetCoordinate().x, i, figure))
		{
			int fig = this->GetFigureAt(this->arr[figure]->GetCoordinate().x, i, figure);
			int type = this->arr[fig]->GetType();
			if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 2 || type == 5))
			{
				return true;
			}
			break;
		}
	}
	//Check for figure from right-top
	for (size_t i = this->arr[figure]->GetCoordinate().x + 1, j = this->arr[figure]->GetCoordinate().y + 1; i < 8 && j < 8; i++, j++)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == true && i == this->arr[figure]->GetCoordinate().x + 1 && j == this->arr[figure]->GetCoordinate().y + 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return true;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			}

			break;
		}
	}
	//Check for figure from left-top
	for (int i = this->arr[figure]->GetCoordinate().x - 1, j = this->arr[figure]->GetCoordinate().y + 1; i >= 0 && j < 8; i--, j++)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == true && i == this->arr[figure]->GetCoordinate().x - 1 && j == this->arr[figure]->GetCoordinate().y + 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return true;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			}
			break;
		}
	}
	//Check for figure from left-bottom
	for (int i = this->arr[figure]->GetCoordinate().x - 1, j = this->arr[figure]->GetCoordinate().y - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == false && i == this->arr[figure]->GetCoordinate().x - 1 && j == this->arr[figure]->GetCoordinate().y - 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return true;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			}

			break;
		}
	}
	//Check for figure from right-bottom
	for (int i = this->arr[figure]->GetCoordinate().x + 1, j = this->arr[figure]->GetCoordinate().y - 1; i < 8 && j >= 0; i++, j--)
	{
		if (this->FigureAt(i, j, figure))
		{
			if (this->arr[figure]->GetColor() == false && i == this->arr[figure]->GetCoordinate().x + 1 && j == this->arr[figure]->GetCoordinate().y - 1)
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 1 || type == 4 || type == 5))
				{
					return true;
				}
			}
			else
			{
				int fig = this->GetFigureAt(i, j, figure);
				int type = this->arr[fig]->GetType();
				if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 4 || type == 5))
				{
					return true;
				}
			}

			break;
		}
	}
	//Check for knight
	int currentX = this->arr[figure]->GetCoordinate().x;
	int currentY = this->arr[figure]->GetCoordinate().y;
	if (FigureAt(currentX + 1, currentY + 2, figure))
	{
		int fig = this->GetFigureAt(currentX + 1, currentY + 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX + 2, currentY + 1, figure))
	{
		int fig = this->GetFigureAt(currentX + 2, currentY + 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 1, currentY + 2, figure))
	{
		int fig = this->GetFigureAt(currentX - 1, currentY + 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX + 1, currentY - 2, figure))
	{
		int fig = this->GetFigureAt(currentX + 1, currentY - 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 2, currentY + 1, figure))
	{
		int fig = this->GetFigureAt(currentX - 2, currentY + 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX + 2, currentY - 1, figure))
	{
		int fig = this->GetFigureAt(currentX + 2, currentY - 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 2, currentY - 1, figure))
	{
		int fig = this->GetFigureAt(currentX - 2, currentY - 1, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	if (FigureAt(currentX - 1, currentY - 2, figure))
	{
		int fig = this->GetFigureAt(currentX - 1, currentY - 2, figure);
		int type = this->arr[fig]->GetType();
		if ((this->arr[fig]->GetColor() != this->arr[figure]->GetColor()) && (type == 3))
		{
			return true;
		}
	}
	return check;
}
void Game::RemoveFigure(int position)
{
	this->countTimesOfNotMovedOrCapturePawn = -1;
	Figure** temp = new Figure*[this->capacity];
	for (size_t i = 0, j = 0; i < this->size;j++,i++)
	{
		if (i == position)
		{
			--j;
			continue;
		}
		temp[j] = this->arr[i];
	}
	this->size--;
	delete[] this->arr;
	this->arr = temp;
}
bool Game::MoveFigure(int figure)
{
	bool mate;
	bool move = false;
	int type = this->arr[figure]->GetType();
	int currentX = this->arr[figure]->GetCoordinate().x;
	int currentY = this->arr[figure]->GetCoordinate().y;
	int previousX = this->arr[figure]->GetLastCoordinate().x;
	int previousY = this->arr[figure]->GetLastCoordinate().y;
	bool firstMove = false;
	if (currentX == previousX && currentY == previousY)
	{
		return false;
	}
	switch (type)
	{
		//Pawn
	case 1:
		//White
		if (this->arr[figure]->GetColor() == 1)
		{
			if (!this->player)
			{
				move = false;
			}
			else
			{
				//first time move
				if (previousY == 1 && (currentY - previousY > 0)
					&& (currentY - previousY <= 2)
					&& (currentX - previousX == 0))
				{
					firstMove = true;
					move = true;
					int count = currentY - previousY;
					int tempY = currentY;
					while (count-- > 0)
					{

						if (this->FigureAt(currentX, tempY--, figure))
						{
							move = false;
						}

					}
				}
				//other time moves
				if (currentY - previousY == 1)
				{
					if (currentX - previousX == 0)
					{

						move = true;
						if (this->FigureAt(currentX, currentY, figure))
						{
							move = false;
						}
					}
					else if ((std::abs(currentX - previousX) == 1))
					{
						if (this->FigureAt(this->arr[figure]->GetCoordinate(), 0))
						{
							move = true;
							this->RemoveFigure(this->FigureAt(currentX, currentY, false));
						}
						else if (((this->en_passanRule.y == this->arr[figure]->GetCoordinate().y) && (this->en_passanRule.x == this->arr[figure]->GetCoordinate().x)))
						{
							move = true;
							this->RemoveFigure(this->FigureAt(currentX, currentY - 1, false));
						}
					}
					
				}
				if (this->checkForCheck(this->GetKing((this->arr[figure]->GetColor()))))
				{
					move = false;
				}
				if (firstMove && move)
				{
					//en passan rule
						this->en_passanRule.x = currentX;
						this->en_passanRule.y = currentY - 1;
				}
				else if (move)
				{
					//en passan rule
						this->en_passanRule.x = - 1;
						this->en_passanRule.y = - 1;
					
				}
			}
			if (!move)
			{
				this->arr[figure]->GetCoordinate() = this->arr[figure]->GetLastCoordinate();
			}
			else
			{
				this->countTimesOfNotMovedOrCapturePawn = 0;
				//Swap players turn
				this->player = !(this->player);
				//Promoting
				if (currentY == 7)
				{
					//this->promote = true;
					char promoteTo;
					do
					{
						std::cout << "Promote pawn to : K for Knight, Q for Queen, R for Rook and B for Bishop! : ";
						std::cin >> promoteTo;
					} while (promoteTo != 'K' && promoteTo != 'Q' && promoteTo != 'B' && promoteTo != 'R');
					Image whiteProm;
					
						if (promoteTo=='Q')
						{
							whiteProm.CreateImage("Images/White_Queen.png");
							Queen* q = new Queen(currentX, currentY, whiteProm, 5, 1);
							//delete this->arr[figure];
							this->arr[figure] = q;
						}
						else if(promoteTo == 'R')
						{
							whiteProm.CreateImage("Images/White_Rook.png");
							Rook* r = new Rook(currentX, currentY, whiteProm, 2, 1);
							//delete this->arr[figure];
							this->arr[figure] = r;
						}
						else if (promoteTo == 'K')
						{
							whiteProm.CreateImage("Images/White_Knight.png");
							Knight* k = new Knight(currentX, currentY, whiteProm, 3, 1);
							//delete this->arr[figure];
							this->arr[figure] = k;
						}
						else if (promoteTo == 'B')
						{
							whiteProm.CreateImage("Images/White_Bishop.png");
							Bishop* b = new Bishop(currentX, currentY, whiteProm, 4, 1);
							//delete this->arr[figure];
							this->arr[figure] = b;
						}
						
					
					
						//promote
				}
			}
			return move;
		}
		//Black
		else
		{
			if (this->player)
			{
				move = false;
			}
			else
			{
				//first time move
				if (previousY == 6 && (previousY - currentY > 0)
					&& (previousY - currentY <= 2)
					&& (previousX - currentX == 0))
				{
					firstMove = true;
					move = true;
					int count = previousY - currentY;
					int tempY = this->arr[figure]->GetCoordinate().y;
					while (count-- > 0)
					{

						if (this->FigureAt(currentX, tempY++, figure))
						{
							move = false;
						}

					}
				}
				//other time moves
				if (previousY - currentY == 1)
				{
					if (previousX - currentX == 0)
					{

						move = true;
						if (this->FigureAt(currentX, currentY, figure))
						{
							move = false;
						}
					}
					else if (std::abs(currentX - previousX) == 1)
					{
						if (this->FigureAt(this->arr[figure]->GetCoordinate(), 1))
						{
							move = true;
							this->RemoveFigure(this->FigureAt(currentX, currentY, true));
						}
						else if (((this->en_passanRule.y == this->arr[figure]->GetCoordinate().y) && (this->en_passanRule.x == this->arr[figure]->GetCoordinate().x)))
						{
							move = true;
							this->RemoveFigure(this->FigureAt(currentX, currentY + 1, true));
						}
					}
					

				}
				if (this->checkForCheck(this->GetKing((this->arr[figure]->GetColor()))))
				{
					move = false;
				}
				if (firstMove && move)
				{
					//en passan rule
						this->en_passanRule.x = currentX;
						this->en_passanRule.y = currentY + 1;
				}
				else if (move)
				{
					//en passan rule
						this->en_passanRule.x = -1;
						this->en_passanRule.y = -1;
					
				}
			}
			if (!move)
			{
				this->arr[figure]->GetCoordinate() = this->arr[figure]->GetLastCoordinate();
			}
			else
			{
				this->countTimesOfNotMovedOrCapturePawn = 0;
				this->player = !(this->player);
				//Promoting
				if (currentY == 0)
				{
				char promoteTo;
					do
					{
						std::cout << "Promote pawn to : K for Knight, Q for Queen, R for Rook and B for Bishop! : ";
						std::cin >> promoteTo;
					} while (promoteTo != 'K' && promoteTo != 'Q' && promoteTo != 'B' && promoteTo != 'R');
					Image blackProm;

					if (promoteTo == 'Q')
					{
						blackProm.CreateImage("Images/Black_Queen.png");
						Queen* q = new Queen(currentX, currentY, blackProm, 5, 0);
						//delete this->arr[figure];
						this->arr[figure] = q;
					}
					else if (promoteTo == 'R')
					{
						blackProm.CreateImage("Images/Black_Rook.png");
						Rook* r = new Rook(currentX, currentY, blackProm, 2, 0);
						//delete this->arr[figure];
						this->arr[figure] = r;
					}
					else if (promoteTo == 'K')
					{
						blackProm.CreateImage("Images/Black_Knight.png");
						Knight* k = new Knight(currentX, currentY, blackProm, 3, 0);
						//delete this->arr[figure];
						this->arr[figure] = k;
					}
					else if (promoteTo == 'B')
					{
						blackProm.CreateImage("Images/Black_Bishop.png");
						Bishop* b = new Bishop(currentX, currentY, blackProm, 4, 0);
						//delete this->arr[figure];
						this->arr[figure] = b;
					}

				}
			}
			return move;
		}


		break;
		//Rook
	case 2:
		if (this->player != this->arr[figure]->GetColor())
		{
			move = false;
		}
		else
		{
			if (currentY == previousY)
			{

				int countX = std::abs(previousX - currentX);
				move = true;
				int tempX = currentX;
				if (currentX > previousX)
				{
					tempX--;
					while (countX--)
					{
						if (FigureAt(tempX--, currentY, figure))
						{
							move = false;
						}
					}

				}
				else
				{

					tempX++;
					while (countX--)
					{
						if (FigureAt(tempX++, currentY, figure))
						{
							move = false;
						}
					}
				}



			}
			else if (currentX == previousX)
			{

				int countY = std::abs(previousY - currentY);
				move = true;
				int tempY = currentY;
				if (currentY > previousY)
				{
					while (countY--)
					{
						tempY--;
						if (FigureAt(currentX, tempY, figure))
						{
							move = false;
						}
					}

				}
				else
				{
					while (countY--)
					{
						tempY++;
						if (FigureAt(currentX, tempY, figure))
						{
							move = false;
						}
					}
				}
			}
			if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
			{
				
				this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
				figure--;
			}
			else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
			{
				move = false;
			}
		}
		if (!move)
		{
			this->arr[figure]->GetCoordinate() = this->arr[figure]->GetLastCoordinate();
		}
		else
		{
			this->en_passanRule.x = -1;
			this->en_passanRule.y = -1;
			this->countTimesOfNotMovedOrCapturePawn++;
			if (!(this->arr[figure]->GetMoved()))
			{
				this->arr[figure]->SetMoved(true);
			}
			this->player = !(this->player);
			if (this->countTimesOfNotMovedOrCapturePawn == 50)
			{
				this->GAMEOVER = 1;
			}
		}
		return move;
		break;
	case 3:
		if (this->player != this->arr[figure]->GetColor())
		{
			move = false;
		}
		else
		{
			if ((currentX == (previousX + 2) && currentY == (previousY + 1)) || (currentX == (previousX + 2) && currentY == (previousY - 1))
				|| (currentX == (previousX - 2) && currentY == (previousY + 1)) || (currentX == (previousX - 2) && currentY == (previousY - 1))
				|| (currentX == (previousX + 1) && currentY == (previousY + 2)) || (currentX == (previousX + 1) && currentY == (previousY - 2))
				|| (currentX == (previousX - 1) && currentY == (previousY + 2)) || (currentX == (previousX - 1) && currentY == (previousY - 2)))
			{
				move = true;
				if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
				{
					this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
				}
				else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
				{
					move = false;
				}
			}
			if (this->checkForCheck(this->GetKing((this->arr[figure]->GetColor()))))
			{
				move = false;
			}
		}
		if (!move)
		{
			this->arr[figure]->GetCoordinate() = this->arr[figure]->GetLastCoordinate();
		}
		else
		{
			this->en_passanRule.x = -1;
			this->en_passanRule.y = -1;
			this->countTimesOfNotMovedOrCapturePawn++;
			this->player = !(this->player);
			if (this->countTimesOfNotMovedOrCapturePawn == 50)
			{
				this->GAMEOVER = 1;
			}
		
		}
		return move;
		break;
	case 4:
		if (this->player != this->arr[figure]->GetColor())
		{
			move = false;
		}
		else
		{
			if (std::abs(currentX - previousX) == std::abs(currentY - previousY))
			{
				move = true;
				if (currentX>previousX && currentY>previousY)
				{
					int tempX = currentX;
					int tempY = currentY;
					while (tempX-- != previousX && tempY-- != previousY)
					{
						if (this->FigureAt(tempX, tempY, figure))
						{
							move = false;
							break;
						}

					}
					if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
					{
						this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
					}
					else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
					{
						move = false;
					}
				}
				else if (currentX>previousX && currentY<previousY)
				{
					int tempX = currentX;
					int tempY = currentY;
					while (tempX-- != previousX && tempY++ != previousY)
					{
						if (this->FigureAt(tempX, tempY, figure))
						{
							move = false;
							break;
						}

					}
					if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
					{
						this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
					}
					else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
					{
						move = false;
					}
				}
				else if (currentX<previousX && currentY>previousY)
				{
					int tempX = currentX;
					int tempY = currentY;
					while (tempX++ != previousX && tempY-- != previousY)
					{
						if (this->FigureAt(tempX, tempY, figure))
						{
							move = false;
							break;
						}

					}
					if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
					{
						this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
					}
					else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
					{
						move = false;
					}
				}
				else if (currentX<previousX && currentY<previousY)
				{
					int tempX = currentX;
					int tempY = currentY;
					while (tempX++ != previousX && tempY++ != previousY)
					{
						if (this->FigureAt(tempX, tempY, figure))
						{
							move = false;
							break;
						}

					}
					if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
					{
						this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
					}
					else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
					{
						move = false;
					}
				}
			}
			if (this->checkForCheck(this->GetKing((this->arr[figure]->GetColor()))))
			{
				move = false;
			}

		}
		if (!move)
		{
			this->arr[figure]->GetCoordinate() = this->arr[figure]->GetLastCoordinate();
		}
		else
		{
			this->en_passanRule.x = -1;
			this->en_passanRule.y = -1;
			this->countTimesOfNotMovedOrCapturePawn++;
			this->player = !(this->player);
			if (this->countTimesOfNotMovedOrCapturePawn == 50)
			{
				this->GAMEOVER = 1;
			}
		}
		return move;
		break;
	case 5:
		if (this->player != this->arr[figure]->GetColor())
		{
			move = false;
		}
		else
		{
			if (std::abs(currentX - previousX) == std::abs(currentY - previousY))
			{
				move = true;
				if (currentX>previousX && currentY>previousY)
				{
					int tempX = currentX;
					int tempY = currentY;
					while (tempX-- != previousX && tempY-- != previousY)
					{
						if (this->FigureAt(tempX, tempY, figure))
						{
							move = false;
							break;
						}

					}
					if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
					{
						this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
					}
					else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
					{
						move = false;
					}
				}
				else if (currentX>previousX && currentY<previousY)
				{
					int tempX = currentX;
					int tempY = currentY;
					while (tempX-- != previousX && tempY++ != previousY)
					{
						if (this->FigureAt(tempX, tempY, figure))
						{
							move = false;
							break;
						}

					}
					if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
					{
						this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
					}
					else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
					{
						move = false;
					}
				}
				else if (currentX<previousX && currentY>previousY)
				{
					int tempX = currentX;
					int tempY = currentY;
					while (tempX++ != previousX && tempY-- != previousY)
					{
						if (this->FigureAt(tempX, tempY, figure))
						{
							move = false;
							break;
						}

					}
					if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
					{
						this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
					}
					else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
					{
						move = false;
					}
				}
				else if (currentX<previousX && currentY<previousY)
				{
					int tempX = currentX;
					int tempY = currentY;
					while (tempX++ != previousX && tempY++ != previousY)
					{
						if (this->FigureAt(tempX, tempY, figure))
						{
							move = false;
							break;
						}

					}
				}
			}
			else if (currentX == previousX)
			{
				int countY = std::abs(previousY - currentY);
				move = true;
				int tempY = currentY;
				if (currentY > previousY)
				{
					while (countY--)
					{
						tempY--;
						if (FigureAt(currentX, tempY, figure))
						{
							move = false;
						}
					}

				}
				else
				{
					while (countY--)
					{
						tempY++;
						if (FigureAt(currentX, tempY, figure))
						{
							move = false;
						}
					}
				}
			}
			else if (currentY == previousY)
			{
				int countX = std::abs(previousX - currentX);
				move = true;
				int tempX = currentX;
				if (currentX > previousX)
				{
					tempX--;
					while (countX--)
					{
						if (FigureAt(tempX--, currentY, figure))
						{
							move = false;
						}
					}

				}
				else
				{

					tempX++;
					while (countX--)
					{
						if (FigureAt(tempX++, currentY, figure))
						{
							move = false;
						}
					}
				}

			}
			if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
			{
				this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
			}
			else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
			{
				move = false;
			}
			if (this->checkForCheck(this->GetKing((this->arr[figure]->GetColor()))))
			{
				move = false;
			}
		}
		if (!move)
		{
			this->arr[figure]->GetCoordinate() = this->arr[figure]->GetLastCoordinate();
		}
		else
		{
			this->en_passanRule.x = -1;
			this->en_passanRule.y = -1;
			this->countTimesOfNotMovedOrCapturePawn++;
			this->player = !(this->player);
			if (this->countTimesOfNotMovedOrCapturePawn == 50)
			{
				this->GAMEOVER = 1;
			}
		}
		return move;
		break;
		case 6 :
			if (this->player != this->arr[figure]->GetColor())
			{
				move = false;
			}
			else
			{
				if (checkForCheck(figure))
				{
					move = false;
				}
				else
				{
					if (std::abs(currentX - previousX) <= 1 && std::abs(currentY - previousY) <= 1)
					{
						move = true;
						if (move && FigureAt(this->arr[figure]->GetCoordinate(), !(this->arr[figure]->GetColor())))
						{
							this->RemoveFigure(this->FigureAt(currentX, currentY, !(this->arr[figure]->GetColor())));
						}
						else if (FigureAt(this->arr[figure]->GetCoordinate().x, this->arr[figure]->GetCoordinate().y, figure, (this->arr[figure]->GetColor())))
						{
							move = false;
						}
					}
					//castling
					else if(!(this->arr[figure]->GetMoved()))
					{
						bool color = this->arr[figure]->GetColor();
						//White
						if (color)
						{
							//Long castle
							if (currentX == 2 && currentY == previousY && !(this->arr[FigureAt(0,0,true)]->GetMoved()))
							{
								move = true;
								for (size_t i = 0; i < 3; i++)
								{
									bool fig = FigureAt(i+1, 0,figure);
									if (fig)
									{
										move = false;
										break;
									}
								}
								for (size_t i = 0; i < 3; i++)
								{
									this->arr[figure]->GetCoordinate().x = i + 2;
									if (this->checkForCheck(figure))
									{
										move = false;
										break;
									}
								}
								this->arr[figure]->GetCoordinate().x = currentX;
								this->arr[figure]->GetCoordinate().y = currentY;
									
								
								
								if (move)
									{
									int rook = FigureAt(0, 0, true);
									Coordinate co;
									co.x = 3;
									co.y = 0;
									this->arr[rook]->GetCoordinate() = co;

									}
							}							
							//short castle
							else if (currentX == 6 && currentY == previousY && !(this->arr[FigureAt(7, 0, true)]->GetMoved()))
							{
								move = true;
								for (size_t i = 5; i < 7; i++)
								{
									bool fig = FigureAt(i , 0, figure);
									if (fig)
									{
										move = false;
										break;
									}
								}
								for (size_t i = 4; i < 7; i++)
								{
									this->arr[figure]->GetCoordinate().x = i;
									if (this->checkForCheck(figure))
									{
										move = false;
										break;
									}
								}
								this->arr[figure]->GetCoordinate().x = currentX;
								this->arr[figure]->GetCoordinate().y = currentY;



								if (move)
								{
									int rook = FigureAt(7, 0, true);
									Coordinate co;
									co.x = 5;
									co.y = 0;
									this->arr[rook]->GetCoordinate() = co;

								}

							}
							
						}
						//Black
						else
						{
							//Long castle
							if (currentX == 2 && currentY == previousY && !(this->arr[FigureAt(0, 7, false)]->GetMoved()))
							{
								move = true;
								for (size_t i = 0; i < 3; i++)
								{
									bool fig = FigureAt(i + 1, 7, figure);
									if (fig)
									{
										move = false;
										break;
									}
								}
								for (size_t i = 0; i < 3; i++)
								{
									this->arr[figure]->GetCoordinate().x = i + 2;
									if (this->checkForCheck(figure))
									{
										move = false;
										break;
									}
								}
								this->arr[figure]->GetCoordinate().x = currentX;
								this->arr[figure]->GetCoordinate().y = currentY;
								if (move)
								{
									int rook = FigureAt(0, 7, false);
									Coordinate co;
									co.x = 3;
									co.y = 7;
									this->arr[rook]->GetCoordinate() = co;

								}
							}
							//short castle
							else if (currentX == 6 && currentY == previousY && !(this->arr[FigureAt(7, 7, false)]->GetMoved()))
							{
								move = true;
								for (size_t i = 5; i < 7; i++)
								{
									bool fig = FigureAt(i, 7, figure);
									if (fig)
									{
										move = false;
										break;
									}
								}
								for (size_t i = 4; i < 7; i++)
								{
									this->arr[figure]->GetCoordinate().x = i;
									if (this->checkForCheck(figure))
									{
										move = false;
										break;
									}
								}
								this->arr[figure]->GetCoordinate().x = currentX;
								this->arr[figure]->GetCoordinate().y = currentY;



								if (move)
								{
									int rook = FigureAt(7, 7, false);
									Coordinate co;
									co.x = 5;
									co.y = 7;
									this->arr[rook]->GetCoordinate() = co;

								}

							}
						}
					}

				}
			}
			if (!move)
			{
				this->arr[figure]->GetCoordinate() = this->arr[figure]->GetLastCoordinate();
			}
			else
			{
				this->en_passanRule.x = -1;
				this->en_passanRule.y = -1;
				this->countTimesOfNotMovedOrCapturePawn++;
				if (!(this->arr[figure]->GetMoved()))
				{
					this->arr[figure]->SetMoved(true);
				}
				this->player = !(this->player);
				if (this->countTimesOfNotMovedOrCapturePawn == 50)
				{
					this->GAMEOVER = 1;
				}
			}
			return move;
		break;
	}
	
		//white
	
	
}