void CGame::GetInput() {
	if (_kbhit()) {
		char c = tolower(_getch());
		if (c == 'p') { // pause
			this->IS_PAUSING = !this->IS_PAUSING;
		}
		else if (c == 'k') { // exit
			this->IS_RUNNING = false;
			this->StartMenu();
			this->StartGame();
		}
		else if (c == 'o') { // save
			string filename;
			int x = this->botright.GetX() + 3;
			int y = this->botright.GetY() / 3 + 8;
			GotoXY(x, y);
			cout << "Please enter the file name: ";
			getline(cin, filename);
			save_game(filename);
			GotoXY(x, y);
			cout << "                                        ";
		}
		else if (c == 'l') { // load
			string filename;
			int x = this->botright.GetX() + 3;
			int y = this->botright.GetY() / 3 + 8;
			GotoXY(x, y);
			cout << "Please enter the file name: ";
			getline(cin, filename);
			if (!load_game(filename)) {
				GotoXY(x, y + 1);
				cout << "Record not exist!";
				Sleep(2500);
			}
			LoadingScreen("Opening " + filename);
			DrawBorder();
		}
		else { //move player command
			if (this->IS_PAUSING == false) {
				DeleteObjectSprite(this->people.GetTopLeft().GetX(), this->people.GetTopLeft().GetY(), this->peopleSprite);
				UpdatePosPeople(c);
			}
		}
	}
}