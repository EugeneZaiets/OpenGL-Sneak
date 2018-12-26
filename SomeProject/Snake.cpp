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
	m_tail_previous_coord = body[0]->m_elem_coord;

	for (int i = 1; i < body.size(); i++)
	{
		body[i - 1]->m_elem_coord = body[i]->m_elem_coord;
	}

	head()->MoveElem(direction);

	if (head()->m_elem_coord.X < -10) {
		head()->m_elem_coord.X = 9;
	}
	else if (head()->m_elem_coord.X >= 10) {
		head()->m_elem_coord.X = -10;
	}
	else if (head()->m_elem_coord.Y < -10) {
		head()->m_elem_coord.Y = 9;
	}
	else if (head()->m_elem_coord.Y >= 10) {
		head()->m_elem_coord.Y = -10;
	}
}

void Snake::Reset()
{
	if (this->body.size() > 0) {
		for (auto it = body.begin(); it != body.end(); it++)
		{
			delete (*it);
		}
	}
	body.clear();
	for (short i = 0; i < 4; i++)
	{
		body.insert(body.begin(), new BasicElement({ i * -1, 0 }));
	}
}

void Snake::DrawSnake()
{
	for (auto element : body) element->DrawElem();
}

BasicElement* Snake::head()
{
	return body[body.size() - 1];
}

COORD Snake::GetHeadCoord()
{
	COORD head_coord = 
	{ head()->m_elem_coord.X,
	  head()->m_elem_coord.Y };
	return head_coord;
}

COORD Snake::GetTailCoord()
{
	COORD tail_coord =
	{ body[0]->m_elem_coord.X,
		body[0]->m_elem_coord.Y };
	return tail_coord;
}

int Snake::GetSnakeSize()
{
	return body.size();
}

void Snake::IncreaseSnake(COORD coord) {
	body.insert(body.begin(), new BasicElement(coord));
}

bool Snake::Intersect(COORD coord, int offset) {
	for (int i = 0; i < body.size() - offset; i++)
	{
		if ((body[i]->m_elem_coord.X == coord.X) && (body[i]->m_elem_coord.Y == coord.Y)) return true;
	}
	return false;
}
