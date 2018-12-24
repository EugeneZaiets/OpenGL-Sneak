#pragma once
#include <glew.h>
#include <glfw3.h>
#include <Windows.h>
struct RGB {
	double Red;
	double Green;
	double Blue;
};
class BasicElement
{
	const int m_x_size = 1;//???
	const int m_y_size = 1;
	const double m_scale = 0.1;
	RGB m_init_color;
public:
	COORD m_elem_coord;
	BasicElement(COORD coord = {0,0}, RGB init_color = { 0.5, 0.0, 0.0 });
	~BasicElement();
	void DrawElem();
	void ClearElem();
	void MoveElem(COORD* direction);
	void SetCoord(int x, int y);
};