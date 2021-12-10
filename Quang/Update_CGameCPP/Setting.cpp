void CGame::Setting() {
	system("cls");
	string setting[] = { "Mode", "Sound" ,"Menu" };
	string mode_state[] = { ": EASY", ": HARD" };
	string sound_state[] = { ": OFF", ": ON" };
	int pos1 = 0;
	const int x = 30;
	const int y = 20;
	int flag = 0;
	while (true) {
		int color = rand() % 7 + 9;
		TextColor(color);
		drawTitle();
		TextColor(7);

		/*for (int i = 20; i <= 50; i++) {
			for (int j = y - 2; j <= y + 4; j++) {
				if (j == y - 2 || j == y + 4 || i == 20 || i == 50) {
					GotoXY(i, j);
					cout << "##";
				}
			}
		}*/

		//New one
		for (int j = y - 2; j <= y + 4; j++) {
			GotoXY(x - 10, j);
			if (j == y - 2 || j == y + 4) {
				cout << "################################";
			}
			else {
				cout << "##";
				GotoXY(x + 20, j);
				cout << "##";
			}
		}

		TextColor(7);
		for (int i = 0; i < 3; i++) {
			GotoXY(x, y + i);
			if (i == pos1) {
				TextColor(227);
				if (i == 0) {
					cout << "> " << setting[i] << mode_state[this->difficult_state];
				}
				else if (i == 1) {
					cout << "> " << setting[i] << sound_state[this->music_state];
				}
				else {
					cout << "> " << setting[i];
				}
				TextColor(7);
			}
			else {
				if (i == 0) {
					cout << setting[i] << mode_state[this->difficult_state];
				}
				else if (i == 1) {
					cout << setting[i] << sound_state[this->music_state];
				}
				else {
					cout << setting[i];
				}
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
						if (this->music_state == false) {
							sndPlaySound(NULL, SND_ASYNC);
						}
						else {
							sndPlaySound(L"BGM_Menu.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
						}
						break;
					case 2:
						//doSth
						//end settings and run the StartMenu
						return;
					}
					break;
				}
			}
		}
		system("cls");
	}
}