#include "Game.h"
#include "GameScreen.h"
#include <time.h>
#include <iostream>

Game::Game() 
{
	glLineWidth(1);
	srand((unsigned int)time(0));
	m_snake = new Snake();
	m_food = new BasicElement({5, 5}, { 0.0, 0.5, 0.0 });
	Speed = 5;
	m_bool_increase = false;
	m_direction = { 1, 0 };
}

Game::~Game() 
{
	delete m_snake;
	delete m_food;
}

void Game::Update() 
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*++SpeedCount;
	if (SpeedCount == Speed) {
		m_snake->Movem_snake(&m_direction);
		m_snake->Drawm_snake();
	}*/
	if (EatFood(&m_snake->GetHeadCoord(), &m_food->m_elem_coord)) {
		m_bool_increase = true;
		m_snake->IncreaseSnake();
		if (m_snake->GetSnakeSize() == 400) 
		{
			std::cout << "You win!" << std::endl;
			system("pause");
			exit(0);
		}
		m_food->m_elem_coord = GenerateFood();
	}
	if (m_snake->Intersect(m_snake->head()->m_elem_coord, 1)) {
		m_snake->Reset();
		m_direction = { 1, 0 };
	}
	if (m_food) m_food->DrawElem();
	m_snake->DrawSnake(&m_bool_increase);
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
		if (m_direction.X == 1) return;
		else m_direction = { -1, 0 };
		m_snake->MoveSnake(&m_direction);
	}
	else if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		if (m_direction.X == -1) return;
		else m_direction = { 1, 0 };
		m_snake->MoveSnake(&m_direction);
	}
	else if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		if (m_direction.Y == -1) return;
		else m_direction = { 0, 1 };
		m_snake->MoveSnake(&m_direction);
	}
	else if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
		if (m_direction.Y == 1) return;
		else m_direction = { 0, -1 };
		m_snake->MoveSnake(&m_direction);
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
	} while (m_snake->Intersect(food));
	return food;
}
