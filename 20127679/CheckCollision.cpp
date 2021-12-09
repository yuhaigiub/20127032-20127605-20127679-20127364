//add sound effect for object collision

bool CGame::CheckCollision() {
	for (int i = 0; i < this->birds.size(); i++)
		if (this->people.CollisionAnimal(*this->birds[i])) {
			this->IS_RUNNING = false;
			if (this->music_state) {
				sndPlaySound(L"bird_laugh.wav", SND_FILENAME | SND_ASYNC);
			}
			return true;
		}

	for (int i = 0; i < this->dinos.size(); i++)
		if (this->people.CollisionAnimal(*this->dinos[i])) {
			this->IS_RUNNING = false;
			if (this->music_state) {
				sndPlaySound(L"dino.wav", SND_FILENAME | SND_ASYNC);
			}
			return true;
		}

	for (int i = 0; i < this->cars.size(); i++)
		if (this->people.CollisionVehicle(*this->cars[i])) {
			this->IS_RUNNING = false;
			if (this->music_state) {
				sndPlaySound(L"car_crash.wav", SND_FILENAME | SND_ASYNC);
			}
			return true;
		}

	for (int i = 0; i < this->tanks.size(); i++)
		if (this->people.CollisionVehicle(*this->tanks[i])) {
			this->IS_RUNNING = false;
			if (this->music_state) {
				sndPlaySound(L"tank_shooting.wav", SND_FILENAME | SND_ASYNC);
			}
			return true;
		}
	return false;
}