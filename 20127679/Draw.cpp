//added portion with traffic light

void CGame::Draw() {
	Point2D pos;
	for (int i = 0; i < this->birds.size(); i++) {
		//bird
		pos = this->birds[i]->GetTopLeft();
		DrawObjectSprite(pos.GetX(), pos.GetY(), this->birdSprite);
	}

	for (int i = 0; i < this->dinos.size(); i++) {
		//dino
		pos = this->dinos[i]->GetTopLeft();
		DrawObjectSprite(pos.GetX(), pos.GetY(), this->dinosaurSprite);
	}

	for (int i = 0; i < this->cars.size(); i++) {
		//car
		pos = this->cars[i]->GetTopLeft();
		DrawObjectSprite(pos.GetX(), pos.GetY(), this->carSprite);
	}

	for (int i = 0; i < this->tanks.size(); i++) {
		//tank
		pos = this->tanks[i]->GetTopLeft();
		DrawObjectSprite(pos.GetX(), pos.GetY(), this->tankSprite);
	}

	//people
	pos = this->people.GetTopLeft();
	DrawObjectSprite(pos.GetX(), pos.GetY(), this->peopleSprite);

	//traffic light 
	//-----------------------------------------------------------------
	// carLight
	pos = this->carLight.GetTopLeft();
	if (carLight.getState() == false) { //red
		TextColor(4);
		DrawObjectSprite(pos.GetX() + 2, pos.GetY(), this->lightSprite);
		TextColor(0);
		DrawObjectSprite(pos.GetX() + 2, pos.GetY() + 2, this->lightSprite);
	}
	else { // green
		TextColor(2);
		DrawObjectSprite(pos.GetX() + 2, pos.GetY() + 2, this->lightSprite);
		TextColor(0);
		DrawObjectSprite(pos.GetX() + 2, pos.GetY(), this->lightSprite);
	}

	if (carLight.getDurationCount() >= 0.5 * carLight.getDuration()) { // yellow
		TextColor(6);
	}
	else {
		TextColor(0);
	}
	DrawObjectSprite(pos.GetX() + 2, pos.GetY() + 1, this->lightSprite); //draw yellow light


	// tankLight
	pos = this->tankLight.GetTopLeft();
	if (tankLight.getState() == false) { //red
		TextColor(4);
		DrawObjectSprite(pos.GetX() + 2, pos.GetY(), this->lightSprite);
		TextColor(0);
		DrawObjectSprite(pos.GetX() + 2, pos.GetY() + 2, this->lightSprite);
	}
	else { // green
		TextColor(2);
		DrawObjectSprite(pos.GetX() + 2, pos.GetY() + 2, this->lightSprite);
		TextColor(0);
		DrawObjectSprite(pos.GetX() + 2, pos.GetY(), this->lightSprite);
	}

	if (tankLight.getDurationCount() >= 0.5 * tankLight.getDuration()) { // yellow
		TextColor(6);
	}
	else {
		TextColor(0);
	}
	DrawObjectSprite(pos.GetX() + 2, pos.GetY() + 1, this->lightSprite); //draw yellow light

	TextColor(7); // set TextColor back to white
}