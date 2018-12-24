#pragma once
#include "GameScreen.h"
#include "BasicElement.h"
#include "Snake.h"
class Game : public GameScreen {
	COORD m_direction;
	Snake* m_snake;
	BasicElement* m_food;
	int SpeedCount, Speed;
	bool m_bool_increase;
public:
	Game();
	virtual ~Game();
	virtual void Update();
	virtual void Keyboard(
		int key,
		int scancode,
		int action,
		int mods);
	bool EatFood(COORD* cr1, COORD* cr2);
	COORD GenerateFood();
};