#pragma once
#include "GameScreen.h"
#include "BasicElement.h"
#include "Snake.h"
class Game : public GameScreen {
	COORD direction;
	Snake* snake;
	BasicElement* food;
	int SpeedCount, Speed;
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