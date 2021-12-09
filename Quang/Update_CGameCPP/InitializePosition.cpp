void CGame::InitializePosition(int &level) {
	
	int w, h, multiplier, x;		// WRITE SEPARATE FUNCTIONS TO CALCULATE THESE

	//random variable
	int _rand;
	int _diff_val = 0;
	//initialize num and speed
	// NUMBER OF ENEMY PER ROW FROM 1->7(MAX_ENEMY) (easy mode)
	// NUMBER OF ENEMY PER ROW FROM 4->7(MAX_ENEMY) (hard mode)
	if (this->difficult_state == true) {
		_diff_val = rand() % (MAX_ENEMY - 4) + 3; //3->6
	}
	_rand = rand() % level + 1;
	this->birdNum = _rand % (MAX_ENEMY - _diff_val) + 1 + _diff_val;
	_rand = rand() % level;
	this->dinoNum = _rand % (MAX_ENEMY - _diff_val) + 1 + _diff_val;
	_rand = rand() % level;
	this->carNum = _rand % (MAX_ENEMY - _diff_val) + 1 + _diff_val;
	_rand = rand() % level + 1;
	this->tankNum = _rand % (MAX_ENEMY - _diff_val) + 1 + _diff_val;

	//SPEED RANDOM FROM 1->N-1 WHEN LESS THAN LEVEL X OF THE GAME
	//AFTER LEVEL X MAINTAIN THE CONSTANT N SPEED
	_rand = rand() % 3 + 1;
	this->birdSpeed = level >= 10? 4: (level % _rand == 0 ? _rand + 1 : _rand);
	_rand = rand() % 2 + 1;
	this->dinoSpeed = level >= 15? 3 : (level % _rand == 0 ? _rand + 1 : _rand);
	_rand = rand() % 2 + 1;
	this->carSpeed = level >= 10? 4 : (level % _rand == 0 ? _rand + 1 : _rand);
	_rand = rand() % 2 + 1;
	this->tankSpeed = level >= 15? 3 : (level % _rand == 0 ? _rand + 1 : _rand);
	this->people.SetSpeed(3, 4);	// DON'T RANDOM


	//BIRD
	//Get bird size (height and width from birdSprite, also hitbox)
	getObjectSize(h, w, this->birdSprite);
	//Starting point at the right/left (+/-1 because of the border)
	//x = this->topleft.GetX() + 1 //for left side
	x = this->botright.GetX() - w - 1; //right side
	multiplier = (this->botright.GetX() - 2 - w) / w; //All possible positions

	//Clear old data form the latest level
	this->birds.clear();

	//INITIAL POSITION OF ENEMY FOR NEW LEVEL
	for (int i = 0; i < this->birdNum; i++) {
		CBird* b = new CBird;
		//Random the position
		_rand = rand() % multiplier;
		//Since start at right side so we let them minus
		b->SetTopLeft(x - _rand*w, DEFAULT_BIRD_Y);
		b->SetBotRight(b->GetTopLeft().GetX() + w, DEFAULT_BIRD_Y + h - 1);
		this->birds.push_back(b);
	}

	//Those 4 below also have the same explaination as the BIRD
	
	//DINO
	getObjectSize(h, w, this->dinosaurSprite);
	x = this->botright.GetX() - w - 1;
	multiplier = (this->botright.GetX() - 2 - w) / w;

	this->dinos.clear();

	for (int i = 0; i < this->dinoNum; i++) {
		CDinosaur* d = new CDinosaur;
		_rand = rand() % multiplier;
		d->SetTopLeft(x - _rand* w, DEFAULT_DINO_Y);
		d->SetBotRight(d->GetTopLeft().GetX() + w, DEFAULT_DINO_Y + h - 1);
		this->dinos.push_back(d);
	}

	//CAR
	getObjectSize(h, w, this->carSprite);
	x = this->topleft.GetX() + 1;
	multiplier = (this->botright.GetX() - 2 - w)/ w;

	this->cars.clear();

	for (int i = 0; i < this->carNum; i++) {
		CCar* c = new CCar;
		_rand = rand() % multiplier;
		c->SetTopLeft(x + _rand * w, DEFAULT_CAR_Y);
		c->SetBotRight(c->GetTopLeft().GetX() + w, DEFAULT_CAR_Y + h - 1);
		this->cars.push_back(c);
	}

	//TANK
	getObjectSize(h, w, this->tankSprite);
	x = this->topleft.GetX() + 1;
	multiplier = (this->botright.GetX() - 2 - w) / w;

	this->tanks.clear();

	for (int i = 0; i < this->tankNum; i++) {
		CTank* t = new CTank;
		_rand = rand() % multiplier;
		t->SetTopLeft(x + _rand * w, DEFAULT_TANK_Y);
		t->SetBotRight(t->GetTopLeft().GetX() + w, DEFAULT_TANK_Y + h - 1);
		this->tanks.push_back(t);
	}

	//PEOPLE
	getObjectSize(h, w, this->peopleSprite);
	x = this->topleft.GetX() + 1;
	multiplier = (this->botright.GetX() - 2 - w) / w;
	_rand = rand() % multiplier;
	this->people.SetTopLeft(x + _rand * w, DEFAULT_PEOPLE_Y);
	this->people.SetBotRight(this->people.GetTopLeft().GetX() + w, DEFAULT_PEOPLE_Y + h - 1);
}