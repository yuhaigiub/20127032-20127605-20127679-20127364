#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<Windows.h>
#include"CConsole.h"
#include"CGame.h"
using namespace std;


void ReadObjectSprite(string filename, vector<string>& objectSprite) {
	ifstream fin(filename);
	string line;
	while (!fin.eof()) {
		getline(fin, line);
		objectSprite.push_back(line);
	}
	fin.close();
}

void DeleteObjectSprite(int x, int y, vector<string>& objectSprite) {
	int index = 0;
	for (auto iter = objectSprite.begin(); iter != objectSprite.end(); iter++) {
		GotoXY(x, y + index);
		for (int i = 0; i < (*iter).size(); i++) cout << " ";
		index++;
	}
}

void DrawObject(int x, int y, const vector<string>& objectSprite) {
	int index = 0;
	for (auto iter = objectSprite.begin(); iter != objectSprite.end(); iter++) {
		GotoXY(x, y + index);
		cout << *iter << endl;
		index++;
	}
}

//int main() {
//	SetWindowSize(900, 60);
//	//ScreenSetting(30, 100);
//
//	vector<string> playerSprite;
//	vector<string> tankSprite;
//	ReadObjectSprite("Player.txt", playerSprite);
//	ReadObjectSprite("Tank.txt", tankSprite);
//	int xP = 3, yP = 3;
//	int xT = 3, yT = 3;
//	DrawObject(xP, yP, playerSprite);
//	while (true) {
//		DeleteObjectSprite(xT, yT, tankSprite);
//		if (xT == 0) {
//			xT = 30;
//		}
//		else {
//			xT--;
//			DrawObject(xT, yT, tankSprite);
//			Sleep(150);
//		}
//
//		if (_kbhit()) {
//			char c = _getch();
//			DeleteObjectSprite(xP, yP, playerSprite);
//
//			if (c == 'a') {
//				xP = xP > 0 ? (xP - 1) : 0;
//			}
//			else if (c == 'd') {
//				xP = xP < 800 ? (xP + 1) : 800;
//			}
//			else if (c == 'w') {
//				yP = yP > 0 ? (yP - 1) : 0;
//			}
//			else if (c == 's') {
//				yP = yP < 600 ? (yP + 1) : 600;
//			}
//			DrawObject(xP, yP, playerSprite);
//		}
//	}
//}


int main() {
	const int SCREEN_WIDTH = 100;
	const int SCREEN_HEIGHT = 40;
	ScreenSetting(SCREEN_WIDTH, SCREEN_HEIGHT);
	CGame game(5, SCREEN_WIDTH, SCREEN_HEIGHT);
	game.DrawBorder();
	while (true) {
		game.Clean();
		game.Update();
		game.Draw();
		//Sleep(20);
	}
}

