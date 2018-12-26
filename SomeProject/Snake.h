#pragma once
#include <vector>
#include "BasicElement.h"
typedef std::vector<BasicElement*> SnakeBody;
class Snake
{
	SnakeBody body;
public:
	COORD m_tail_previous_coord; /*need to store coord of tail before moving to set coord of new tail when snake increases*/
	Snake();
	~Snake();
	void MoveSnake(COORD* direction);
	void IncreaseSnake(COORD coord);
	void Reset();
	void DrawSnake();
	bool Intersect(COORD coord, int offset = 0);
	BasicElement* head();
	COORD GetHeadCoord();
	COORD GetTailCoord();
	int GetSnakeSize();
};