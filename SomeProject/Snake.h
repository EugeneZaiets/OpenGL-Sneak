#pragma once
#include <vector>
#include "BasicElement.h"
typedef std::vector<BasicElement*> SnakeBody;
class Snake
{
	SnakeBody body;
	bool eaten;
public:
	Snake();
	~Snake();
	void MoveSnake(COORD* direction);
	void Reset();
	void DrawSnake();
	void DrawSnake(bool temp);
	BasicElement* head();
	COORD GetHeadCoord();
	COORD GetTailCoord();
	int GetSnakeSize();
	bool Intersect(COORD coord, int offset = 0);
	void IncreaseSnake();
};