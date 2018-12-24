#include "Game.h"
#include "GameScreen.h"
#include <time.h>

Game::Game() 
{
	glLineWidth(1);
	srand((unsigned int)time(0));
	snake = new Snake();
	food = new BasicElement({5, 5}, { 0.0, 0.5, 0.0 });
	Speed = 5;
	direction = { 1, 0 };
}

Game::~Game() 
{
	delete snake;
	delete food;
}

void Game::Update() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	/*++SpeedCount;
	if (SpeedCount == Speed) {
		snake->MoveSnake(&direction);
		snake->DrawSnake();
	}*/
	if (EatFood(&snake->GetHeadCoord(), &food->m_elem_coord)) {
		snake->IncreaseSnake(food);
		food->m_elem_coord = GenerateFood();
	}
	if (food) food->DrawElem();
	snake->DrawSnake();
	DrawNet();
}

void Game::Keyboard(
	int key,
	int scancode,
	int action,
	int mods)
{
	if (key == GLFW_KEY_ESCAPE && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		glfwTerminate();
		system("pause");
		exit(0);
	}
	else if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		if (direction.X == 1) return;
		else direction = { -1, 0 };
		snake->MoveSnake(&direction);
	}
	else if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		if (direction.X == -1) return;
		else direction = { 1, 0 };
		snake->MoveSnake(&direction);
	}
	else if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		if (direction.Y == -1) return;
		else direction = { 0, 1 };
		snake->MoveSnake(&direction);
	}
	else if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		if (direction.Y == 1) return;
		else direction = { 0, -1 };
		snake->MoveSnake(&direction);
	}
}
bool Game::EatFood(COORD* cr1, COORD* cr2) 
{
	return ((cr1->X == cr2->X) && (cr1->Y == cr2->Y)) ? 1 : 0;
}
COORD Game::GenerateFood()
{
	COORD food;
	do{
		food.X = rand() % 20 - 10;
		food.Y = rand() % 20 - 10;
	} while (snake->Intersect(food));
	return food;
}

