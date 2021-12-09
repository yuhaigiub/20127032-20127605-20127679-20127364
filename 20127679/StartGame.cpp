//add background music for gameplay

void CGame::StartGame() {
	system("cls");
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	ScreenSetting(SCREEN_WIDTH, SCREEN_HEIGHT);
	this->DrawBorder();
	if (this->music_state) {
		sndPlaySound(L"BGM_Playing.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	InitializePosition(this->level);		//please rewrite this function (and use level)
}