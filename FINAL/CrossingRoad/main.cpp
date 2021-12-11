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
	bool enableSound = StartWithSound();
	CGame game(GAME_WIDTH, GAME_HEIGHT, enableSound);
	srand((unsigned int)time(NULL));
	//DisableMouse();
	game.StartMenu();
	thread game_run(subThread, &game);
	while (true) {
	}
	


}


bool StartWithSound() {
	ShowConsoleCursor(0);
	int x = 65, y = 15;
	int pos = 0;
	const string menu[2] = { "Yes", "No" };

	while (true) {
		system("cls");
		GotoXY(x - 15, y - 1);
		cout << "Do you want to start with sound on?";
		TextColor(7);
		for (int i = 0; i < 2; i++) {
			if (i == pos) {
				TextColor(227);
				GotoXY(x, y + i);
				cout << "> " << menu[i];
				TextColor(7);
			}
			else {
				GotoXY(x, y + i);
				cout << menu[i];
			}
		}
		while (true) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 'W' || key == 'w') {
					if (pos > 0)
						pos--;
					else
						pos = 1;
					break;
				}
				if (key == 'S' || key == 's') {
					if (pos < 1)
						pos++;
					else
						pos = 0;
					break;
				}
				if (key == 13) { // hit enter
					switch (pos) {
					case 0: // start game
						return true;
					case 1: // load game
						return false;
					}
				}
			}
		}
	}
}
