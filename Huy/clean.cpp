// clean function (call before update)

void CGame::Clean() {
	Point2D pos;
	for (int i = 0; i < this->birds.size(); i++) {
		//bird
		pos = this->birds[i]->GetTopLeft();
		DeleteObjectSprite(pos.GetX(), pos.GetY(), this->birdSprite);
	}

	for (int i = 0; i < this->dinos.size(); i++) {
		//dino
		pos = this->dinos[i]->GetTopLeft();
		DeleteObjectSprite(pos.GetX(), pos.GetY(), this->dinosaurSprite);
	}

	for (int i = 0; i < this->cars.size(); i++) {
		//car
		pos = this->cars[i]->GetTopLeft();
		DeleteObjectSprite(pos.GetX(), pos.GetY(), this->carSprite);
	}

	for(int i = 0; i < this->tanks.size(); i++) {
		//tank
		pos = this->tanks[i]->GetTopLeft();
		DeleteObjectSprite(pos.GetX(), pos.GetY(), this->tankSprite);
	}
}
