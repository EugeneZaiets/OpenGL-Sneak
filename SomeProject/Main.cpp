#pragma comment(lib, "glfw3.lib")
#pragma comment(lib,"glew32.lib")
#include <iostream>
#include "GameScreen.h"
#include "Game.h"
int main() {
	GameScreen* GameWindow = new GameScreen(500);
	GameWindow->Run();
	system("pause");
	return 0;
}


