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

void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}

void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

int main() {
	SetWindowSize(150,150);
	DisableResizeWindow();
	ShowScrollbar(0);

	vector<string> playerSprite;
	vector<string> tankSprite;
	ReadObjectSprite("Player.txt", playerSprite);
	ReadObjectSprite("Tank.txt", tankSprite);
	int xP = 3, yP = 3;
	int xT = 30, yT = 30;
	DrawObject(xP, yP, playerSprite);
	while (true) {
		DeleteObjectSprite(xT, yT, tankSprite);
		if (xT == 0) {
			xT = 30;
		}
		else {
			xT--;
			DrawObject(xT, yT, tankSprite);
			Sleep(150);
		}

		if (_kbhit()) {
			char c = _getch();
			DeleteObjectSprite(xP, yP, playerSprite);
			
			if (c == 'a') {
				xP = xP > 0 ? (xP - 1) : 0;
			}
			else if (c == 'd') {
				xP = xP < 800 ? (xP + 1) : 800; 
			}
			else if (c == 'w') {
				yP = yP > 0 ? (yP - 1) : 0;
			}
			else if (c == 's') {
				yP = yP < 600 ? (yP + 1) : 600;
			}
			DrawObject(xP, yP, playerSprite);
		}		
	}
}
