#pragma comment(lib, "glfw3.lib")
#pragma comment(lib,"glew32.lib")
#include "GameScreen.h"
#include "Game.h"

int main() {
	Game* game = new Game();
	game->Run();
	delete game;
	return 0;
}


