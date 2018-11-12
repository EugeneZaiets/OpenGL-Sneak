#pragma once
#ifndef _GAMESCREEN_H_
#define _GAMESCREEN_H_
#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>
#include <gl/GL.h>
#include <gl/GLU.h>

class GameScreen {
	GLFWwindow* GameWindow;
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
	//virtual void Update();
	virtual void Keyboard(
		int key, 
		int scancode, 
		int action, 
		int mods);
	void Run();
};

#endif // _GAMESCREEN_H_