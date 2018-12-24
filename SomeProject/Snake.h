#pragma once
#include <vector>
#include "BasicElement.h"
typedef std::vector<BasicElement*> SnakeBody;
class Snake
{
	SnakeBody body;
public:
	Snake();
	~Snake();
	void MoveSnake(COORD* direction);
	void Reset();
	void DrawSnake();
	int Head();
	COORD GetHeadCoord();
	COORD GetTailCoord();
	bool Intersect(COORD coord);
	void IncreaseSnake(BasicElement* elem);
};