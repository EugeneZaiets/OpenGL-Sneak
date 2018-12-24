#include "BasicElement.h"

BasicElement::BasicElement(COORD coord, RGB init_color)
{
	m_elem_coord.X = coord.X;
	m_elem_coord.Y = coord.Y;
	m_init_color = init_color;
}
BasicElement::~BasicElement()
{
}
void BasicElement::DrawElem() {
	/*glBegin(GL_TRIANGLES);
	glColor3d(0.7, 0.0, 0.0);
	glVertex2d(0.0 + m_elem_coord.X * m_scale, 0.0 + m_elem_coord.Y * m_scale);
	glVertex2d(0.1 + m_elem_coord.X * m_scale, 0.1 + m_elem_coord.Y * m_scale);
	glVertex2d(0.0 + m_elem_coord.X * m_scale, 0.1 + m_elem_coord.Y * m_scale);
	glEnd();
	*/
	/*glBegin(GL_QUADS);
	glColor3d(0.5, 0.0, 0.0);
	glVertex2d(0.02 + m_elem_coord.X * m_scale, 0.02 + m_elem_coord.Y * m_scale);
	glVertex2d(0.08 + m_elem_coord.X * m_scale, 0.02 + m_elem_coord.Y * m_scale);
	glVertex2d(0.08 + m_elem_coord.X * m_scale, 0.08 + m_elem_coord.Y * m_scale);
	glVertex2d(0.02 + m_elem_coord.X * m_scale, 0.08 + m_elem_coord.Y * m_scale);
	glEnd();
	*/
	glBegin(GL_QUADS);
	glColor3d(m_init_color.Red, m_init_color.Green, m_init_color.Blue);
	glVertex2d(m_elem_coord.X * m_scale, m_elem_coord.Y * m_scale);
	glVertex2d(1 * m_scale + m_elem_coord.X * m_scale, m_elem_coord.Y * m_scale);
	glVertex2d(1 * m_scale + m_elem_coord.X * m_scale, 1 * m_scale + m_elem_coord.Y * m_scale);
	glVertex2d(m_elem_coord.X * m_scale, 1 * m_scale + m_elem_coord.Y * m_scale);
	glEnd();
}
void BasicElement::ClearElem() 
{
	glBegin(GL_QUADS);
	glColor3d(0,0,0);
	glVertex2d(m_elem_coord.X * m_scale, m_elem_coord.Y * m_scale);
	glVertex2d(1 * m_scale + m_elem_coord.X * m_scale, m_elem_coord.Y * m_scale);
	glVertex2d(1 * m_scale + m_elem_coord.X * m_scale, 1 * m_scale + m_elem_coord.Y * m_scale);
	glVertex2d(m_elem_coord.X * m_scale, 1 * m_scale + m_elem_coord.Y * m_scale);
	glEnd();
}

void BasicElement::MoveElem(COORD* direction)
{
	m_elem_coord.X += direction->X;
	m_elem_coord.Y += direction->Y;
}

void BasicElement::SetCoord(int x, int y) {
	m_elem_coord.X = x;
	m_elem_coord.Y = y;
}