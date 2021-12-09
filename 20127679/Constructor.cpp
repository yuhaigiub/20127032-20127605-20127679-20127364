//update constructor with CLight sprite intialization 

CGame::CGame(int width, int height, bool musicState) {
	//PREPARE INITIAL VALUES
	this->level = 1;
	this->IS_RUNNING = false;
	this->IS_PAUSING = false;
	this->difficult_state = false;
	this->music_state = musicState;
	
	// set border
	this->topleft.SetX(1); this->topleft.SetY(1);
	this->botright.SetX(width); this->botright.SetY(height);

	//set spritefile
	this->birdSpritefile = "Bird.txt";
	this->dinosaurSpritefile = "Dinosaur.txt";
	this->carSpritefile = "Car.txt";
	this->tankSpritefile = "Tank.txt";
	this->peopleSpritefile = "People.txt";
	this->RIPSpritefile = "RIP.txt";
	
	//set sprite vector
	ReadObjectSprite(this->birdSpritefile, this->birdSprite);
	ReadObjectSprite(this->dinosaurSpritefile, this->dinosaurSprite);
	ReadObjectSprite(this->carSpritefile, this->carSprite);
	ReadObjectSprite(this->tankSpritefile, this->tankSprite);
	ReadObjectSprite(this->peopleSpritefile, this->peopleSprite);
	ReadObjectSprite(this->RIPSpritefile, this->RIPSprite);

	this->lightSprite.push_back("\xE2\x96\xA0"); //Use the hexa code of small black square
}