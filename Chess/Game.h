#pragma once
#include "Board.h"
#include "Image.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "String.h"
class Game
{
private:
	int capacity;
	int size;
	void ReSize();
	Figure** arr;
	Board chessBoard;
	bool checkForCheck(int figure);
	// 1 for white 0 for black
	bool player;
	int countTimesOfNotMovedOrCapturePawn;
	int GAMEOVER;
	Coordinate en_passanRule;
	int Attacker(int figure);
	bool CanFigureMoveTo(int x, int y, int figure);
	bool checkForCheckForMate(int figure);
public:
	//bool promote;
	int IsGameOver();
	Figure** GetArr();
	void AddFigure(Figure& figure);
	Game();
	~Game();
	bool isMate(bool color);
	int FigureAt(int x, int y, bool color);
	void RemoveFigure(int position);
	int GetKing(bool color);
	int GetFigureAt(int x, int y, int figure);
	bool GetPlayer();
	bool FigureAt(int x, int y, int figure, bool color);
	bool FigureAt(int x, int y,int figure);
	bool FigureAt(Coordinate coordinate);
	bool FigureAt(Coordinate coordinate, bool color);
	Board GetChessBoard();
	bool MoveFigure(int figure);
	int GetLength();
	void InitzializeBoard();
	void InitzializeFugures();
	void DeleteBoard();
	void DeleteFigures();

};