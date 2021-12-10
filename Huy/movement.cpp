// Update movement of objects in the scene (no traffic lights involve)


void CGame::UpdatePosTank() { //TANKS GO LEFT
		int w, h;
		getObjectSize(h, w, this->tankSprite);
		for (int i = 0; i < this->tanks.size(); i++) {

			//move
			this->tanks[i]->Move(-1 * this->tankSpeed, 0);
			int distance = -this->tanks[i]->GetTopLeft().GetX() + this->topleft.GetX();
			if (distance >= 0) {
				this->tanks[i]->SetTopLeft(this->botright.GetX() - w - distance, this->tanks[i]->GetTopLeft().GetY());
				this->tanks[i]->SetBotRight(this->tanks[i]->GetTopLeft().GetX() + w, this->tanks[i]->GetBotRight().GetY());
			}
		}
}


void CGame::UpdatePosCar() { //CARS GO LEFT
		int h, w;
		getObjectSize(h, w, this->tankSprite);
		for (int i = 0; i < this->cars.size(); i++) {

			// move
			this->cars[i]->Move(-1 * this->carSpeed, 0);
			int distance = -this->cars[i]->GetTopLeft().GetX() + this->topleft.GetX();
			if (distance >= 0) {
				this->cars[i]->SetTopLeft(this->botright.GetX() - w - distance, this->cars[i]->GetTopLeft().GetY());
				this->cars[i]->SetBotRight(this->cars[i]->GetTopLeft().GetX() + w, this->cars[i]->GetBotRight().GetY());
			}
		}
}

void CGame::UpdatePosBird() { //BIRDS GO RIGHT
	int h, w;
	getObjectSize(h, w, this->tankSprite);
	for (int i = 0; i < this->birds.size(); i++) {
		this->birds[i]->Move(1 * this->birdSpeed, 0);
		int distance = this->birds[i]->GetBotRight().GetX() - this->botright.GetX();
		if (distance >= 0) {
			this->birds[i]->SetTopLeft(this->topleft.GetX() + 2 + distance, this->birds[i]->GetTopLeft().GetY());
			this->birds[i]->SetBotRight(this->birds[i]->GetTopLeft().GetX() + w, this->birds[i]->GetBotRight().GetY());
		}

	}
}

void CGame::UpdatePosDino() { //DINOS GO RIGHT
	int h, w;
	getObjectSize(h, w, this->tankSprite);
	for (int i = 0; i < this->dinos.size(); i++) {
		this->dinos[i]->Move(1 * this->dinoSpeed, 0);
		int distance = this->dinos[i]->GetBotRight().GetX() - this->botright.GetX() + 1;
		if (distance >= -1) {
			this->dinos[i]->SetTopLeft(this->topleft.GetX() + 2 + distance, this->dinos[i]->GetTopLeft().GetY());
			this->dinos[i]->SetBotRight(this->dinos[i]->GetTopLeft().GetX() + w, this->dinos[i]->GetBotRight().GetY());
		}

	}
}


void CGame::UpdatePosPeople(char direction) {
	if (direction == 'w') {
		if(this->people.GetTopLeft().GetY() - this->people.GetSpeed().GetY() > this->topleft.GetY())
			this->people.Move(0, 1);
	}
	else if (direction == 's') {
		if(this->people.GetBotRight().GetY() + this->people.GetSpeed().GetY() < this->botright.GetY())
			this->people.Move(0, -1);
	}
	else if (direction == 'a') {
		if(this->people.GetTopLeft().GetX() - this->people.GetSpeed().GetX() > this->topleft.GetX())
			this->people.Move(-1, 0);
	}
	else if (direction == 'd') {
		if(this->people.GetBotRight().GetX() + this->people.GetSpeed().GetX() < this->botright.GetX())
			this->people.Move(1, 0);
	}
}
