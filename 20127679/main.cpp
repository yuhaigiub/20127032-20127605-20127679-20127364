//implemented threading

#include"CConsole.h"
#include"CGame.h"
#include <thread>
using namespace std;

const int GAME_WIDTH = 129;
const int GAME_HEIGHT = 29;

bool StartWithSound();

void subThread(CGame* game) {
	game->StartGame();
	while (game->GET_IS_RUNNING()) {
		if (!game->GET_IS_PAUSING()) {
			game->Clean();
			game->Update();
			
			if (game->IS_FINISH()) {
				game->StartGame();
			}
			game->Draw();

			Sleep(75);
		}
		if (game->CheckCollision()) {
			//Xe cap cuu/Bia mo... 
			// _ _ _ 
			//|		|
			//| RIP |
			//|_ _ _| 
			//
			game->RIP();
			game->EndMenu();
			if (!game->GET_IS_RUNNING()) {
				game->StartMenu();
			}
			game->StartGame();
		}

		game->GetInput();
	}
}

int main() {
	CGame game(GAME_WIDTH, GAME_HEIGHT, true);
	srand((unsigned int)time(NULL));
	game.StartMenu();
	thread game_run(subThread, &game);
	while (true) {
	}
	
}