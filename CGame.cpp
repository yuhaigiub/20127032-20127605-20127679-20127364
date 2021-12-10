#include "CGame.h"

void CGame::DrawBorder() {
	int x1 = this->topleft.GetX();
	int x2 = this->botright.GetX();
	int y1 = this->topleft.GetY();
	int y2 = this->botright.GetY();
	for (int i = x1; i <= x2; i++) {
		GotoXY(i, y1); cout << "=";
		GotoXY(i, y2); cout << "=";

		//draw lane
		GotoXY(i, 5); cout << "-";
		GotoXY(i, 9); cout << "-";
		GotoXY(i, 13); cout << "-";
		GotoXY(i, 21); cout << "-";
		GotoXY(i, 25); cout << "-";
	}
	for (int i = y1 + 1; i < y2; i++) {
		GotoXY(x1, i); cout << "|";
		GotoXY(x2, i); cout << "|";
	}


	//draw side menu
	int x = this->botright.GetX() + 10;
	int y = this->botright.GetY() / 3;

	GotoXY(++x, y++);
	cout << "LEVEL: " << this->level;
	GotoXY(x - 4, y++);
	cout << "------------------";
	x -= 2;
	GotoXY(x, y++);
	cout << "|----MENU----|";
	GotoXY(x, y++);
	cout << "|  Pause (P) |";
	GotoXY(x, y++);
	cout << "|  Save (O)  |";
	GotoXY(x, y++);
	cout << "|  Load (L)  |";
	GotoXY(x, y++);
	cout << "|  Exit (K)  |";
	GotoXY(x, y++);
	cout << "|------------|";

	x = this->topleft.GetX();
	y = this->botright.GetY() + 3;

	GotoXY(x, y++);
	cout << "Use W/A/S/D to move around. " << endl;
	GotoXY(x, y++);
	cout << "Your goal is to go up, avoid the obstacles and survive the levels! Good luck!" << endl;
	GotoXY(x, y++);
	cout << "SAVE the game and input your nickname." << endl;
	GotoXY(x, y++);
	cout << "LOAD the game using your nickname." << endl;
	GotoXY(x, y++);
	cout << "EXIT to return to main menu." << endl;
}

bool CGame::CheckCollision() {
	for (int i = 0; i < this->birds.size(); i++)
		if (this->people.CollisionAnimal(*this->birds[i])) {
			this->IS_RUNNING = false;
			return true;
		}

	for (int i = 0; i < this->dinos.size(); i++)
		if (this->people.CollisionAnimal(*this->dinos[i])) {
			this->IS_RUNNING = false;
			return true;
		}

	for (int i = 0; i < this->cars.size(); i++)
		if (this->people.CollisionVehicle(*this->cars[i])) {
			this->IS_RUNNING = false;
			return true;
		}

	for (int i = 0; i < this->tanks.size(); i++)
		if (this->people.CollisionVehicle(*this->tanks[i])) {
			this->IS_RUNNING = false;
			return true;
		}
	return false;
}

void CGame::drawTitle() {

	cout << "                                                                         00000000000" << endl;
	cout << "                                                                    0000000000000000000" << endl;
	cout << "                                                                000000000000000000000000000" << endl;
	cout << "                                                              00000000       ||       00000000" << endl;
	cout << "                                                            000000   \\       ||       //  000000" << endl;
	cout << " ******  *******   ******   ******   ******  ** **    **  ******       \\     ||     //     000000" << endl;
	cout << "**       **    ** **    ** **       **       ** ***   ** **              \\   ||   //        000000" << endl;
	cout << "**       ** * *   **    ** ********  ******  ** **  * ** **  ****          \\  - //           000000" << endl;
	cout << "**       **   **  **    **       **       ** ** **   *** **    **= = = = = =( 0 )= = = = = = 000000" << endl;
	cout << " ******  **    **  ******   ******   ******  ** **    **  ******           // - \\           000000" << endl;
	cout << "                                               *******   ******     **    ******* \\        000000" << endl;
	cout << "   ___________________________________________ **    ** **    **   **** / **    **  \\     000000" << endl;
	cout << "   ___________________________________________ ** * *   **    **  **  **  **    **    \\  000000" << endl;
	cout << "   ___________________________________________ **   **  **    ** ******** **    **      000000" << endl;
	cout << "                                               **    **  ******  **    ** *******   00000000" << endl;
	cout << "                                                                  0000000000000000000000" << endl;
	cout << "                                                                   000000000000000000" << endl;
	cout << "                                                                      000000000000" << endl;
}

void CGame::StartMenu() {
	system("cls");
	ScreenSetting(830, 480);
	/*
		CROSSING ROAD
		-------------
		new game
		load game
		setting
		exit
	*/
	const string menu[4] = { "New Game","Load Game","Setting","Exit" };
	int pos = 0;
	const int x = 30;
	const int y = 20;
	int flag;
	string filename;
	int currentOption = 1;
	while (true) {
		flag = 0;
		system("cls");
		int color = rand() % 7 + 9;
		TextColor(color);
		drawTitle();
		TextColor(7);
		//TextColor(238);

		/*for (int i = 20; i <= 50; i++) {
			for (int j = y - 2; j <= y + 5; j++) {
				if (j == y - 2 || j == y + 5 || i == 20 || i == 50) {
					GotoXY(i, j);
					cout << "##";
				}
			}
		}*/

		//New one
		for (int j = y - 2; j <= y + 5; j++) {
			GotoXY(x - 10, j);
			if (j == y - 2 || j == y + 5) {
				cout << "################################";
			}
			else {
				cout << "##";
				GotoXY(x + 20, j);
				cout << "##";
			}
		}

		TextColor(7);
		for (int i = 0; i < 4; i++) {
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
						pos = 3;
					break;
				}
				if (key == 'S' || key == 's') {
					if (pos < 3)
						pos++;
					else
						pos = 0;
					break;
				}
				if (key == 13) { // hit enter
					switch (pos) {
					case 0: // start game
						SET_IS_RUNNING(true);
						flag = 1;
						this->level = 1;
						break;
					case 1: // load game
						GotoXY(x + 25, y + 1); cout << "Please enter the file name: ";
						getline(cin, filename);
						GotoXY(x + 25, y + 2);
						if (!load_game(filename)) {
							cout << "Record not exist!";
							Sleep(2500);
							flag = 2;
							break;
						}
						LoadingScreen("Opening " + filename);
						SET_IS_RUNNING(true);
						flag = 1;
						break;
					case 2:
						Setting();
						return this->StartMenu();
					case 3:
						system("cls");
						exit(0);
						break;
					}
				}
			}
			if (flag == 1) {
				SET_IS_RUNNING(true);
				return;
			}
			else if (flag == 2) {
				break;
			}
		}
	}
}

void CGame::Setting() {
	system("cls");
	string setting[] = { "Mode", "Sound" ,"Menu" };
	int pos1 = 0;
	const int x = 30;
	const int y = 20;
	int flag = 0;
	while (true) {
		int color = rand() % 7 + 9;
		TextColor(color);
		drawTitle();
		TextColor(7);

		for (int i = 20; i <= 50; i++) {
			for (int j = y - 2; j <= y + 4; j++) {
				if (j == y - 2 || j == y + 4 || i == 20 || i == 50) {
					GotoXY(i, j);
					cout << "##";
				}
			}
		}

		TextColor(7);
		for (int i = 0; i < 3; i++) {
			GotoXY(x, y + i);
			if (i == pos1) {
				TextColor(227);
				cout << "> " << setting[i];
				TextColor(7);
			}
			else {
				cout << setting[i];
			}
		}
		while (true) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 'W' || key == 'w') {
					if (pos1 > 0)
						pos1--;
					else
						pos1 = 2;
					break;
				}
				if (key == 'S' || key == 's') {
					if (pos1 < 2)
						pos1++;
					else
						pos1 = 0;
					break;
				}
				if (key == 13) {
					switch (pos1) {
					case 0:
						//doSth
						this->difficult_state = !this->difficult_state;
						break;
					case 1:
						//doSth
						this->music_state = !this->music_state;
						break;
					case 2:
						//doSth
						break;
					}
					break;
				}
			}
		}
		system("cls");
	}
}

void CGame::EndMenu() {
	ScreenSetting(830, 480);
	/*
		YOU DIED
		continue
		main menu
	*/
	const string menu[2] = { "Continue","Main Menu" };
	int pos = 0;
	int x = 30;
	int y = 20;
	int flag = 0;
	while (true) {
		system("cls");
		int color = rand() % 7 + 9;
		TextColor(color);
		GotoXY(10, 10); cout << "**    **  ******  **    **    ******   ** ******* ******     !!! !!!" << endl;
		GotoXY(10, 11); cout << " **  **  **    ** **    **    **   **  ** **      **    **   !!! !!!" << endl;
		GotoXY(10, 12); cout << "  ****   **    ** **    **    **    ** ** ******  **     **  !!! !!!" << endl;
		GotoXY(10, 13); cout << "   **    **    ** **    **    **   **  ** **      **    **   !!! !!!" << endl;
		GotoXY(10, 14); cout << "   **     ******   ******     ******   ** ******* ******     @@@ @@@" << endl;
		TextColor(7);
		//Inefficient
		/*for (int i = 20; i <= 50; i++) {
			for (int j = y - 2; j <= y + 3; j++) {
				if (j == y - 2 || j == y + 3 || i == 20 || i == 50) {
					GotoXY(i, j);
					cout << "##";
				}
			}
		}*/

		for (int j = y - 2; j <= y + 3; j++) {
			GotoXY(x - 10, j);
			if (j == y - 2 || j == y + 3) {
				cout << "################################";
			}
			else {
				cout << "##";
				GotoXY(x + 20, j);
				cout << "##";
			}
		}

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
				if (key == 13) {
					switch (pos) {
					case 0:
						system("cls");
						SET_IS_RUNNING(true);
						flag = 1;
						this->level = 1;
						break;
					case 1:
						LoadingScreen("Back to Main Menu");
						return;
						break;
					}
				}
			}
			if (flag)
				return;
		}
	}
}

void CGame::LoadingScreen(string message) {
	ScreenSetting(830, 480);
	system("cls");
	drawTitle();
	GotoXY(40, 24);
	cout << message;
	GotoXY(20, 25);
	cout << "[";
	for (int i = 0; i <= 50; i++)
	{
		Sleep(35);
		GotoXY(20 + i, 25);
		cout << "=>";
		GotoXY(45, 26);
		cout << i * 2 << "%";
	}
	system("cls");
	ScreenSetting(1280, 720);
}

void CGame::RIP() {
	DrawObjectSprite(this->people.GetTopLeft().GetX(), this->people.GetTopLeft().GetY(), this->RIPSprite);
	Sleep(3000);
	//DeleteObjectSprite(this->people.GetTopLeft().GetX(), this->people.GetTopLeft().GetY(), this->RIPSprite);

}