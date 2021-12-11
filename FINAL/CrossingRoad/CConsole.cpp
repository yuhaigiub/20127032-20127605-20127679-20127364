#include "CConsole.h"

void GotoXY(int x, int y) {
	// move cursor to this position
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetWindowSize(LONG width, LONG height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}

void ShowScrollbar(BOOL Show) {
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void ShowConsoleCursor(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;
	GetConsoleCursorInfo(handle, &ConCurInf);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

void ScreenSetting(int width, int height) {
	SetWindowSize(width, height);
	//SetScreenBufferSize(width, height);
	FixConsoleWindow();
	ShowScrollbar(0);
	ShowConsoleCursor(0);
	SetConsoleTitle(L"Crossing Road");
	SetConsoleOutputCP(65001);
}

void TextColor(int x) {
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}

//draw 
void getObjectSize(int& height, int& width, const vector<string>& objSprite)
{
	width = 0;
	height = (int)objSprite.size();
	for (int i = 0; i < height; i++) {
		int len = (int)objSprite[i].length();
		width = width < len ? len : width;
	}
}

void DeleteObjectSprite(int x, int y, const vector<string>& objectSprite) {
	int index = 0, h, w;
	getObjectSize(h, w, objectSprite);
	string _space = "";
	for (int i = 0; i < w; i++) _space += " ";
	for (int i = 0; i < h; i++) {
		GotoXY(x, y + index);
		cout << _space;
		index++;
	}
}

void DrawObjectSprite(int x, int y, const vector<string>& objectSprite) {
	int index = 0;
	for (auto iter = objectSprite.begin(); iter != objectSprite.end(); iter++) {
		GotoXY(x, y + index);
		cout << *iter << '\n';
		index++;
	}
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

