//pre-start menu option (start with sound on ?)

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
					if (pos < 2)
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
