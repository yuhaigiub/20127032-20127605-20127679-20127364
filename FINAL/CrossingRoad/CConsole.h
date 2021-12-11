#ifndef C_CONSOLE_
#define C_CONSOLE_

#include<Windows.h>
#include<vector>
#include<fstream>
#include<string>
#include<iostream>
#pragma comment(lib, "Winmm.lib")
using namespace std;

void GotoXY(int x, int y);
void SetWindowSize(LONG width, LONG height);
void SetScreenBufferSize(SHORT width, SHORT height);
void ShowScrollbar(BOOL Show);
void FixConsoleWindow();
void ScreenSetting(int width, int height);
void ShowConsoleCursor(bool CursorVisibility);

void getObjectSize(int& height, int& width, const vector<string>& objSprite);

void TextColor(int x);

void ReadObjectSprite(string filename, vector<string>& objectSprite);
void DrawObjectSprite(int x, int y, const vector<string>& objectSprite);
void DeleteObjectSprite(int x, int y, const vector<string>& objectSprite);

#endif // !C_CONSOLE_