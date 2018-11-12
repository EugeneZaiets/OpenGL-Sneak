#include "GameScreen.h"
#include <iostream>
#include <Windows.h>

GameScreen::GameScreen(int screen_size) : ScreenSize(screen_size) {
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
	if (GameWindow == nullptr) {
		std::cout << "Error : Window wasn't initialized\n";
		std::cout << GetLastError() << std::endl;
		system("pause");
		glfwTerminate();
		return;
	}
	//Making Context for current window
	glfwMakeContextCurrent(GameWindow);
	//Init GLFW and checking errors if they occure
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Error : Failed GLEW initialize\n";
		std::cout << GetLastError() << std::endl;
		system("pause");
		glfwTerminate();
		return;
	}
	//Creating a frame buffer and viewport
	glfwGetFramebufferSize(GameWindow, &ScreenWidth, &ScreenHeight);
	glViewport(0, 0, ScreenWidth, ScreenHeight);
	glfwSetWindowUserPointer(GameWindow, this);
	glfwSetKeyCallback(GameWindow, KeyboardCallback);

	std::cout << "creation is successful..." << std::endl;
}
GameScreen::~GameScreen() {
	glfwTerminate();
	std::cout << "destruction is successful..." << std::endl;
}
void GameScreen::Render() {
	glfwSwapBuffers(GameWindow);
}
void GameScreen::Run(){
	while (!glfwWindowShouldClose(GameWindow)) {

		glfwPollEvents();
		Render();
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
void GameScreen::Keyboard(
	int key, 
	int scancode, 
	int action, 
	int mods) 
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwTerminate();
		this->~GameScreen();
		system("pause");
		exit(0);
	}
}



