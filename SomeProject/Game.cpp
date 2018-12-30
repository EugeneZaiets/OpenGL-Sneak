#include "Game.h"
#include "GameScreen.h"
#include <time.h>
#include <iostream>

Game::Game()
{
	glLineWidth(1);
	srand((unsigned int)time(0));
	this->m_snake = new Snake();
	this->m_food = new BasicElement({5, 5}, { 0.0, 0.9, 0.0 });
	m_direction = { 1, 0 };
	SpeedCount = 0;
	Speed = 40;
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
	
	if (EatFood(&m_snake->GetHeadCoord(), &m_food->m_elem_coord)) {
		m_snake->IncreaseSnake(m_snake->m_tail_previous_coord);
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
		m_food->m_elem_coord = GenerateFood();
		m_direction = { 1, 0 };
	}
	
	++SpeedCount;
	if (SpeedCount == Speed) {
		SpeedCount = 0;
		m_snake->MoveSnake(&m_direction);
		Sleep(5);
	}

	m_food->DrawElem();
	m_snake->DrawSnake();
	DrawNet();
}

void Game::Keyboard(
	int key,
	int scancode,
	int action,
	int mods)
{
	if (key == GLFW_KEY_ESCAPE && (action == GLFW_PRESS  /*|| action == GLFW_REPEAT*/)) {
		glfwTerminate();
		system("pause");
		exit(0);
	}
	else if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS /*|| action == GLFW_REPEAT*/)) {
		if (m_direction.X == 1) return;
		else m_direction = { -1, 0 };
		m_snake->MoveSnake(&m_direction);
		Sleep(20);
	}
	else if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS  /*|| action == GLFW_REPEAT*/)) {
		if (m_direction.X == -1) return;
		else m_direction = { 1, 0 };
		m_snake->MoveSnake(&m_direction);
		Sleep(20);
	}
	else if (key == GLFW_KEY_UP && (action == GLFW_PRESS /*|| action == GLFW_REPEAT*/)) {
		if (m_direction.Y == -1) return;
		else m_direction = { 0, 1 };
		m_snake->MoveSnake(&m_direction);
		Sleep(20);
	}
	else if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS /*|| action == GLFW_REPEAT*/)) {
		if (m_direction.Y == 1) return;
		else m_direction = { 0, -1 };
		m_snake->MoveSnake(&m_direction);
		Sleep(20);
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
