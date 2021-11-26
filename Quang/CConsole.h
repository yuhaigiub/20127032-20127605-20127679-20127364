#ifndef C_CONSOLE_
#define C_CONSOLE_

#include<Windows.h>
#include<iostream>
using namespace std;

void GotoXY(int x, int y);
void SetWindowSize(LONG width, LONG height);
void SetScreenBufferSize(SHORT width, SHORT height);
void ShowScrollbar(BOOL Show);
void FixConsoleWindow();
void ScreenSetting(int width, int height);
void ShowCur(bool CursorVisibility);

#endif // !C_CONSOLE_


