
#include <iostream>
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\freeglut\glut.h"
#include "Dependencies\glfw\glfw3.h"
#include <cmath>
#include <stdio.h>
#include "Game.h"
#include "HelpMatrix.h"

//GLFWwindow *promote;
double wseconds = 0.0;
double bseconds = 0.0;
double wtime = 1800;
double btime = 1800;




GLfloat mouse_X, mouse_Y;
Shader ourShader;
static void cursorPositionCallBack(GLFWwindow *window, double xPos, double yPos);
bool move = false;
int moveFigure = -1;
Coordinate mouseCoord;
int rememberPos_X = 0;
int rememberPos_Y = 0;
HelpMatrix help;
Position CoordinateToPosition(int x, int y)
{
	Position currentPosition;
	Position defaultPosition(0.12f, 0.24f);
	currentPosition.SetX(defaultPosition.GetX()*x);
	currentPosition.SetY(defaultPosition.GetY()*y);
	return currentPosition;
		
}


void mouseButtonCallback(GLFWwindow *window, int but, int action, int mods);
// Window dimensions
const GLuint WIDTH = 1300, HEIGHT = 650;

Game game;
Image wpawn;
Image bpawn;
Image wrook;
Image brook;
Image wknight;
Image bknight;
Image wbishop;
Image bbishop;
Image wqueen;
Image bqueen;
Image wking;
Image bking;

Image test;
void InitzializingBoard()
{
	
	game.InitzializeBoard();
	test.CreateImage("Images/White_pawn.png",0.0f,0.0f,1.0f,1.0f);

	wpawn.CreateImage("Images/White_Pawn.png");
	bpawn.CreateImage("Images/Black_Pawn.png");
	wrook.CreateImage("Images/White_Rook.png");
	brook.CreateImage("Images/Black_Rook.png");
	wknight.CreateImage("Images/White_Knight.png");
	bknight.CreateImage("Images/Black_Knight.png");
	wbishop.CreateImage("Images/White_Bishop.png");
	bbishop.CreateImage("Images/Black_Bishop.png");
	wqueen.CreateImage("Images/White_Queen.png");
	bqueen.CreateImage("Images/Black_Queen.png");
	wking.CreateImage("Images/White_King.png");
	bking.CreateImage("Images/Black_King.png");

	//this->WAPawn = Pawn(0, 1, wpawn, "Pawn", 1);
	
	//game.InitzializeFugures();
}

void LoadStartGamePosition()
{
	
	for (size_t i = 0; i < game.GetLength(); i++)
	{
		game.GetArr()[i]->OnPosition(game.GetArr()[i]->GetCoordinate().x, game.GetArr()[i]->GetCoordinate().y, ourShader);
	}
	//GLfloat xValue = CoordinateToPosition(game.GetBKBishop().GetCoordinate().x, game.GetBKBishop().GetCoordinate().y).GetX();
	//GLfloat yValue = CoordinateToPosition(game.GetBKBishop().GetCoordinate().x, game.GetBKBishop().GetCoordinate().y).GetY();
	////White
	//game.GetWAPawn().OnPosition(game.GetWAPawn().GetCoordinate().x, game.GetWAPawn().GetCoordinate().y,ourShader);
	//game.GetWBPawn().OnPosition(game.GetWBPawn().GetCoordinate().x, game.GetWBPawn().GetCoordinate().y, ourShader);
	//game.GetWCPawn().OnPosition(game.GetWCPawn().GetCoordinate().x, game.GetWCPawn().GetCoordinate().y, ourShader);
	//game.GetWDPawn().OnPosition(game.GetWDPawn().GetCoordinate().x, game.GetWDPawn().GetCoordinate().y, ourShader);
	//game.GetWEPawn().OnPosition(game.GetWEPawn().GetCoordinate().x, game.GetWEPawn().GetCoordinate().y, ourShader);
	//game.GetWFPawn().OnPosition(game.GetWFPawn().GetCoordinate().x, game.GetWFPawn().GetCoordinate().y, ourShader);
	//game.GetWGPawn().OnPosition(game.GetWGPawn().GetCoordinate().x, game.GetWGPawn().GetCoordinate().y, ourShader);
	//game.GetWHPawn().OnPosition(game.GetWHPawn().GetCoordinate().x, game.GetWHPawn().GetCoordinate().y, ourShader);
	//game.GetWQRook().OnPosition(game.GetWQRook().GetCoordinate().x, game.GetWQRook().GetCoordinate().y, ourShader);
	//game.GetWQKnight().OnPosition(game.GetWQKnight().GetCoordinate().x, game.GetWQKnight().GetCoordinate().y, ourShader);
	//game.GetWQBishop().OnPosition(game.GetWQBishop().GetCoordinate().x, game.GetWQBishop().GetCoordinate().y, ourShader);
	//game.GetWQueen().OnPosition(game.GetWQueen().GetCoordinate().x, game.GetWQueen().GetCoordinate().y, ourShader);
	//game.GetWKing().OnPosition(game.GetWKing().GetCoordinate().x, game.GetWKing().GetCoordinate().y, ourShader);
	//game.GetWKBishop().OnPosition(game.GetWKBishop().GetCoordinate().x, game.GetWKBishop().GetCoordinate().y, ourShader);
	//game.GetWKKnight().OnPosition(game.GetWKKnight().GetCoordinate().x, game.GetWKKnight().GetCoordinate().y, ourShader);
	//game.GetWKRook().OnPosition(game.GetWKRook().GetCoordinate().x, game.GetWKRook().GetCoordinate().y, ourShader);
	////Black
	//game.GetBAPawn().OnPosition(game.GetBAPawn().GetCoordinate().x, game.GetBAPawn().GetCoordinate().y, ourShader);
	//game.GetBBPawn().OnPosition(game.GetBBPawn().GetCoordinate().x, game.GetBBPawn().GetCoordinate().y, ourShader);
	//game.GetBCPawn().OnPosition(game.GetBCPawn().GetCoordinate().x, game.GetBCPawn().GetCoordinate().y, ourShader);
	//game.GetBDPawn().OnPosition(game.GetBDPawn().GetCoordinate().x, game.GetBDPawn().GetCoordinate().y, ourShader);
	//game.GetBEPawn().OnPosition(game.GetBEPawn().GetCoordinate().x, game.GetBEPawn().GetCoordinate().y, ourShader);
	//game.GetBFPawn().OnPosition(game.GetBFPawn().GetCoordinate().x, game.GetBFPawn().GetCoordinate().y, ourShader);
	//game.GetBGPawn().OnPosition(game.GetBGPawn().GetCoordinate().x, game.GetBGPawn().GetCoordinate().y, ourShader);
	//game.GetBHPawn().OnPosition(game.GetBHPawn().GetCoordinate().x, game.GetBHPawn().GetCoordinate().y, ourShader);
	//game.GetBQRook().OnPosition(game.GetBQRook().GetCoordinate().x, game.GetBQRook().GetCoordinate().y, ourShader);
	//game.GetBQKnight().OnPosition(game.GetBQKnight().GetCoordinate().x, game.GetBQKnight().GetCoordinate().y, ourShader);
	//game.GetBQBishop().OnPosition(game.GetBQBishop().GetCoordinate().x, game.GetBQBishop().GetCoordinate().y, ourShader);
	//game.GetBQueen().OnPosition(game.GetBQueen().GetCoordinate().x, game.GetBQueen().GetCoordinate().y, ourShader);
	//game.GetBKing().OnPosition(game.GetBKing().GetCoordinate().x, game.GetBKing().GetCoordinate().y, ourShader);
	//game.GetBKBishop().OnPosition(game.GetBKBishop().GetCoordinate().x, game.GetBKBishop().GetCoordinate().y, ourShader);
	//game.GetBKKnight().OnPosition(game.GetBKKnight().GetCoordinate().x, game.GetBKKnight().GetCoordinate().y, ourShader);
	//game.GetBKRook().OnPosition(game.GetBKRook().GetCoordinate().x, game.GetBKRook().GetCoordinate().y, ourShader);


}
void DeleteInitzializedItems()
{
	game.DeleteBoard();
	game.DeleteFigures();
}

// The MAIN function, from here we start the application and run the game loop
int main()
{
	
	//int times = 0;
	// Init GLFW
	glfwInit();

	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Chess", nullptr, nullptr);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetCursorPosCallback(window, cursorPositionCallBack);
	
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
	
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	//glfwMakeContextCurrent(promote);
	//glfwMakeContextCurrent(win);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Define the viewport dimensions
	glViewport(0, 0, screenWidth, screenHeight);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	ourShader = Shader("core.vs", "core.frag");


	InitzializingBoard();
	//White


	game.AddFigure(Pawn(0, 1, wpawn, 1, 1));
	game.AddFigure(Pawn(1, 1, wpawn, 1, 1));
	game.AddFigure(Pawn(2, 1, wpawn, 1, 1));
	game.AddFigure(Pawn(3, 1, wpawn, 1, 1));
	game.AddFigure(Pawn(4, 1, wpawn, 1, 1));
	game.AddFigure(Pawn(5, 1, wpawn, 1, 1));
	game.AddFigure(Pawn(6, 1, wpawn, 1, 1));
	game.AddFigure(Pawn(7, 1, wpawn, 1, 1));
	game.AddFigure(Rook(0, 0, wrook, 2, 1));
	game.AddFigure(Knight(1, 0, wknight, 3, 1));
	game.AddFigure(Bishop(2, 0, wbishop, 4, 1));
	game.AddFigure(Queen(3, 0, wqueen, 5, 1));
	game.AddFigure(King(4, 0, wking, 6, 1));
	game.AddFigure(Bishop(5, 0, wbishop, 4, 1));
	game.AddFigure(Knight(6, 0, wknight, 3, 1));
	game.AddFigure(Rook(7, 0, wrook, 2, 1));
	//Black
	game.AddFigure(Pawn(0, 6, bpawn, 1, 0));
	game.AddFigure(Pawn(1, 6, bpawn, 1, 0));
	game.AddFigure(Pawn(2, 6, bpawn, 1, 0));
	game.AddFigure(Pawn(3, 6, bpawn, 1, 0));
	game.AddFigure(Pawn(4, 6, bpawn, 1, 0));
	game.AddFigure(Pawn(5, 6, bpawn, 1, 0));
	game.AddFigure(Pawn(6, 6, bpawn, 1, 0));
	game.AddFigure(Pawn(7, 6, bpawn, 1, 0));
	game.AddFigure(Rook(0, 7, brook, 2, 0));
	game.AddFigure(Knight(1, 7, bknight, 3, 0));
	game.AddFigure(Bishop(2, 7, bbishop, 4, 0));
	game.AddFigure(Queen(3, 7, bqueen, 5, 0));
	game.AddFigure(King(4, 7, bking, 6, 0));
	game.AddFigure(Bishop(5, 7, bbishop, 4, 0));
	game.AddFigure(Knight(6, 7, bknight, 3, 0));
	game.AddFigure(Rook(7, 7, brook, 2, 0));
	glfwSetTime(0);
	int lastWSec = 0;
	int lastBSec = 0;
//						  // Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
	//	std::cout << times++ << std::endl;
		//if (game.promote)
		//{
		//	while (!glfwWindowShouldClose(promote))
		//	{
		//		glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
		//		glClear(GL_COLOR_BUFFER_BIT);
		//		test.PrintImage(0.0f, 0.0f, ourShader);
		//		glfwSwapBuffers(promote);
		//		glfwWaitEvents();
		//		//glfwPollEvents();
		//	}
		//	glfwDestroyWindow(promote);
		//	game.promote = false;
		//}
	
		
		// Clear the colorbuffer
		
		glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		//test.PrintImage(0.0f, 0.0f, ourShader);
	//		game.GetChessBoard().Create();
		game.GetChessBoard().Print(ourShader);
		LoadStartGamePosition();
	//	std::cout << game.GetBKBishop().GetCoordinate().x << " : " << game.GetBKBishop().GetCoordinate().y << std::endl;
		
		if (game.GetPlayer())
		{
			wseconds = glfwGetTime();
		}
		else
		{
			bseconds = glfwGetTime();
			
		}
		if (wtime-wseconds <= 0)
		{
			glfwDestroyWindow(window);
			std::cout << "Black won!" << std::endl;
			char end;
			std::cin >> end;
		}
		if (btime - bseconds <= 0)
		{
			glfwDestroyWindow(window);
			std::cout << "White won!" << std::endl;
			char end;
			std::cin >> end;
		}
		if (int(wtime - wseconds) != lastWSec || int(btime - bseconds) != lastBSec)
		{
			system("cls");
			std::cout << "White : " << int(wtime - wseconds);
			std::cout << "  |  Black : " << int(btime - bseconds) << std::endl;
			lastBSec = int(btime - bseconds);
			lastWSec = int(wtime - wseconds);
			
		}

	//	std::cout <<"White : " <<wtime << std::endl;
	//	std::cout << "Black : " << btime << std::endl;
//		std::cout << game.GetArr()[10]->GetCoordinate().x << " : " << game.GetArr()[10]->GetCoordinate().y <<std::endl;
	
		
		
		// Swap the screen buffers
		glfwSwapBuffers(window);
		//glfwWaitEvents();
		glfwPollEvents();
	
	}

	// Properly de-allocate all resources once they've outlived their purpose

	//game.GetWAPawn().Delete();
	DeleteInitzializedItems();
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	char s;
	std::cin >> s;
	return EXIT_SUCCESS;
}

static void cursorPositionCallBack(GLFWwindow *window, double xPos, double yPos)
{
	GLfloat  ox= xPos;
	GLfloat oy = yPos;
	mouse_X = ((ox / (WIDTH / 2)) - (1.0f));
	mouse_Y = -((oy / (HEIGHT / 2)) - (1.0f));
	int X_Coordinate = 0, Y_Coordinate = 0;
	if ( xPos<32 || xPos >655)
	{
		X_Coordinate = -1;
	}
	else
	{

		X_Coordinate = std::floor((xPos-32)/78);
	}
	if ( yPos < 10 || yPos > 634)
	{
		Y_Coordinate = -1;
	}
	else
	{
		Y_Coordinate = std::floor((yPos-11)/78);
		Y_Coordinate -= 7;
		Y_Coordinate %= 8;
		Y_Coordinate *= -1;
	}
	mouseCoord.x = X_Coordinate;
	mouseCoord.y = Y_Coordinate;
	if (move)
	{
		game.GetArr()[moveFigure]->GetCoordinate() = mouseCoord;
	}
	//std::cout << mouse_X << " : " << mouse_Y << std::endl;
}
void mouseButtonCallback(GLFWwindow *window, int but, int action, int mods)
{
	if (but == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		for (size_t i = 0; i < game.GetLength(); i++)
		{
			if (mouseCoord.x == game.GetArr()[i]->GetCoordinate().x &&  mouseCoord.y == game.GetArr()[i]->GetCoordinate().y)
			{
				game.GetArr()[i]->GetLastCoordinate() = game.GetArr()[i]->GetCoordinate();
				moveFigure = i;
				move = true;
				break;
			}
		}
		//std::string s = "print me";
		//std::cout << game.GetArr()[moveFigure]->GetType() << std::endl;
	//	std::cout << "Left button | ";
	//	std::cout << mouseCoord.x << " : " << mouseCoord.y << std::endl;
		
	}
	if (but == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		if (moveFigure == -1)
		{

		}
		else
		{
			if (game.GetArr()[moveFigure]->GetCoordinate().x == -1 || game.GetArr()[moveFigure]->GetCoordinate().y == -1)
			{
				game.GetArr()[moveFigure]->GetCoordinate() = game.GetArr()[moveFigure]->GetLastCoordinate();
			}
			else
			{
				bool swap = game.MoveFigure(moveFigure);
				//if (game.promote)
				//{
				//	promote = glfwCreateWindow(300, 100, "Promote", nullptr, nullptr);
				//	glfwMakeContextCurrent(promote);
				//	int screenWidth2, screenHeight2;
				//	glfwGetFramebufferSize(promote, &screenWidth2, &screenHeight2);
				//	glViewport(0, 0, screenWidth2, screenHeight2);
				//
				//	//fill window with figures make events for chosing right figure and swap pawn with chosen figure
				//}

				//std::cout << swap << std::endl;
				if (swap)
				{
					
					if (game.IsGameOver() == 1)
					{
						std::cout << "-------DRAW------" << std::endl;
						glfwDestroyWindow(window);
					}
					bool player = !(game.GetPlayer());
					if (player)
					{
						wtime -= wseconds;
					}
					else
					{
						btime -= bseconds;
					}
					bool s = game.isMate(game.GetPlayer());
					if (s)
					{
						std::cout << !(game.GetPlayer()) << " WIN !!!!" << std::endl;
						glfwDestroyWindow(window);
					}
					glfwSetTime(0);
				}
			}


			move = false;
		}
		moveFigure = -1;
	//	std::cout << "RELEASED | ";
	//	std::cout << mouseCoord.x << " : " << mouseCoord.y << std::endl;
	}

}
