//update condition of cars and tanks affected by traffic lights

void CGame::UpdatePosTank() { //TANKS GO LEFT
	if (this->tankLight.getState()) {
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
}

void CGame::UpdatePosCar() { //CARS GO LEFT
	if (this->carLight.getState()) {
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
}