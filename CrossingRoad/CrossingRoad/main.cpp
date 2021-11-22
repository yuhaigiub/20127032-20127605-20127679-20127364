#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<Windows.h>
#include<conio.h>

using namespace std;

void GotoXY(int x, int y) {
	// move cursor to this position
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ReadPlayerSprite(string filename, vector<string>& playerSprite) {
	ifstream fin(filename);
	string line;
	while (!fin.eof()) {
		getline(fin, line);
		playerSprite.push_back(line);
	}
	fin.close();
}

void DeletePlayerSprite(int x, int y, vector<string>& playerSprite) {
	int index = 0;
	for (auto iter = playerSprite.begin(); iter != playerSprite.end(); iter++) {
		GotoXY(x, y + index);
		for (int i = 0; i < (*iter).size(); i++) cout << " ";
		index++;
	}
}

void DrawPlayer(int x, int y, const vector<string>& playerSprite) {	
	int index = 0;
	for (auto iter = playerSprite.begin(); iter != playerSprite.end(); iter++) {
		GotoXY(x, y + index);
		cout << *iter << endl;
		index++;
	}
}


int main() {
	vector<string> playerSprite;
	ReadPlayerSprite("Player.txt", playerSprite);
	int x = 3, y = 3;
	while (true) {
		if (_kbhit()) {
			char c = getchar();
			DeletePlayerSprite(x, y, playerSprite);
			if (c == 'a') {
				x = x > 0 ? (x - 1) : 0;
			}
			else if (c == 'd') {
				x = x < 30 ? (x + 1) : 30; 
			}
			else if (c == 'w') {
				y = y > 0 ? (y - 1) : 0;
			}
			else if (c == 's') {
				y = y < 20 ? (y + 1) : 20;
			}
			DrawPlayer(x, y, playerSprite);
		}
	}
}
