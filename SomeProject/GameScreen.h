#pragma once
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib,"glew32.lib")
#pragma comment(lib, "opengl32.lib")

#ifndef _GAMESCREEN_H_
#define _GAMESCREEN_H_
#include <glew.h>
#include <glfw3.h>
#include <gl/GL.h>
#include <gl/GLU.h>
//#include "PerfomanceCounter.h"
#define GLEW_STATIC
#define MY_PERFORMENCE_COUNTER

class GameScreen {
	GLFWwindow* GameWindow;
	static const GLfloat g_vertex_buffer_data[];
	GLuint vertexbuffer;
	int ScreenSize;
	int ScreenWidth;
	int	ScreenHeight;
	void Render();
	static void KeyboardCallback(
		GLFWwindow* window,
		int key,
		int scancode,
		int action,
		int mods);
public:
	GameScreen(int screen_size = 500);
	virtual ~GameScreen();
	virtual void Update() = 0;
	virtual void Keyboard(
		int key,
		int scancode,
		int action,
		int mods) = 0;
	void Run();
	void DrawNet();
};
#endif // _GAMESCREEN_H_