#include "Snake.h"
#include <iterator>
Snake::Snake()
{
	this->Reset();
}
Snake::~Snake()
{
	for (int i = 0; i < body.size(); i++)
	{
		delete body[i];
	}
}

void Snake::MoveSnake(COORD* direction)
{

	for (int i = 1; i < body.size(); i++)
	{
		body[i - 1]->m_elem_coord = body[i]->m_elem_coord;
	}
	body[body.size() - 1]->MoveElem(direction);
	if (body[body.size() - 1]->m_elem_coord.X < -10) {
		body[body.size() - 1]->m_elem_coord.X = 9;
	}
	else if (body[body.size() - 1]->m_elem_coord.X >= 10) {
		body[body.size() - 1]->m_elem_coord.X = -10;
	}
	else if (body[body.size() - 1]->m_elem_coord.Y < -10) {
		body[body.size() - 1]->m_elem_coord.Y = 9;
	}
	else if (body[body.size() - 1]->m_elem_coord.Y >= 10) {
		body[body.size() - 1]->m_elem_coord.Y = -10;
	}
}

void Snake::Reset()
{
	for (short i = 0; i < 4; i++)
	{
		body.insert(body.begin(), new BasicElement({ i * -1, 0 }));
	}
}
void Snake::DrawSnake()
{
	for (auto element : body) element->DrawElem();
}

int Snake::Head()
{
	return body.size() - 1;
}

COORD Snake::GetHeadCoord()
{
	COORD head_coord = 
	{ body[body.size() - 1]->m_elem_coord.X, 
	  body[body.size() - 1]->m_elem_coord.Y };
	return head_coord;
}
COORD Snake::GetTailCoord()
{
	COORD tail_coord =
	{ body[0]->m_elem_coord.X,
		body[0]->m_elem_coord.Y };
	return tail_coord;
}
void Snake::IncreaseSnake(BasicElement* elem) {
	body.insert(body.begin(), new BasicElement(elem->m_elem_coord));
	body[0]->m_elem_coord = body[1]->m_elem_coord;
}

bool Snake::Intersect(COORD coord) {
	for (int i = 0; i < body.size(); i++)
	{
		if ((body[i]->m_elem_coord.X == coord.X) && (body[i]->m_elem_coord.Y == coord.Y)) return true;
	}
	return false;
}
