//add background music for menu

void CGame::StartMenu() {
	system("cls");
	ScreenSetting(830, 480);
	if (this->music_state) {
		sndPlaySound(L"BGM_Menu.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
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