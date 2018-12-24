#include "GameScreen.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

GameScreen::GameScreen(int screen_size) : ScreenSize(screen_size)
{
	//Init GLFW and Minor, Major version
	glfwInit();
	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	// Making window static
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//Creating a window and checking its poiters
	GameWindow = glfwCreateWindow(
		ScreenSize,
		ScreenSize,
		"Main Window",
		nullptr,
		nullptr);
	if (GameWindow == nullptr) 
	{
		std::cout << "Error : Window wasn't initialized\n";
		std::cout << GetLastError() << std::endl;
		system("pause");
		glfwTerminate();
		return;
	}
	//Making Context for current window
	glfwMakeContextCurrent(GameWindow);
	//Init GLFW and checking errors if they occure
	//glewExperimental = GL_TRUE;
	/*if (glewInit() != GLEW_OK) {
	std::cout << "Error : Failed GLEW initialize\n";
	std::cout << GetLastError() << std::endl;
	system("pause");
	glfwTerminate();
	return;
	}*/
	//Creating a frame buffer and viewport
	glfwGetFramebufferSize(GameWindow, &ScreenWidth, &ScreenHeight);
	glViewport(0, 0, ScreenWidth, ScreenHeight);
	glfwSetWindowUserPointer(GameWindow, this);
	glfwSetKeyCallback(GameWindow, KeyboardCallback);
	std::cout << "Game screen creation is successful..." << std::endl;
}
GameScreen::~GameScreen() 
{
	glfwTerminate();
	std::cout << "destruction is successful..." << std::endl;
}
void GameScreen::Render() 
{
	glfwSwapBuffers(GameWindow);
}
void GameScreen::Run()
{
	while (!glfwWindowShouldClose(GameWindow)) {
		glfwPollEvents();
		Update();
		Render();
		//CStopwatch timer;
		//int sum = 0;
		//int counter = 0;
		//int deltaTime = 0;
		//while (1)
		//{
		//	timer.Start();
		//	if (_kbhit())
		//	{
		//		Keyboard(_getch(), _getch(), _getch(), _getch());
		//	}
		//	
		//	glfwPollEvents();
		//	Update((float)deltaTime / 1000.0f);
		//	Render();
		//	Sleep(50);
		//	while (1)
		//	{
		//		if (_kbhit())
		//		{
		//			Keyboard(_getch(), _getch(), _getch(), _getch());
		//		}
		//		deltaTime = timer.Now();
		//		if (deltaTime > 20)
		//			break;
		//	}
		//	sum += deltaTime;
		//	counter++;
		//	if (sum >= 1000)
		//	{
		//		//TCHAR  szbuff[255];
		//		/*StringCchPrintf(szbuff, 255, TEXT("FPS: %d"), counter);
		//		SetConsoleTitle(szbuff);*/
		//		counter = 0;
		//		sum = 0;
		//	}
		//}
	}
}

void GameScreen::KeyboardCallback(
	GLFWwindow* window,
	int key,
	int scancode,
	int action,
	int mods)
{
	GameScreen* callback_handler = static_cast<GameScreen*>(glfwGetWindowUserPointer(window));
	callback_handler->Keyboard(key, scancode, action, mods);
}

void GameScreen::DrawNet() 
{
	glColor3d(0.0, 0.0, 0.5);
	glBegin(GL_LINES);
	for (double i = -0.9; i < 0.9; i += 0.1)
	{
		glVertex2d(i, -1.0);
		glVertex2d(i, 1.0);
	}
	for (double i = -0.9; i < 1.0; i += 0.1)
	{
		glVertex2d(-1.0, i);
		glVertex2d(1.0, i);
	}
	glEnd();
}