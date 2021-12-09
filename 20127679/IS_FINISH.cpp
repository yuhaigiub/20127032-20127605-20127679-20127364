//add round success sound effect + background music for gameplay

bool CGame::IS_FINISH()
{
	if (this->people.GetTopLeft().GetY() == FINISH_LINE) {
		if (this->music_state) {
			sndPlaySound(L"success.wav", SND_FILENAME | SND_SYNC);
			sndPlaySound(L"BGM_Playing.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
		this->level++;
		return true;
	}
	else return false;
}