#include "CGame.h"

CGame::CGame(int width, int height) {
	// set border
	this->topleft.SetX(1); this->topleft.SetY(1);
	this->botright.SetX(width); this->botright.SetY(height);
	
	//set spritefile
	this->birdSpritefile = "Bird.txt";
	this->dinosaurSpritefile = "Dinosaur.txt";
	this->carSpritefile = "Car.txt";
	this->tankSpritefile = "Tank.txt";
	this->peopleSpritefile = "People.txt";

	//set sprite vector
	ReadObjectSprite(this->birdSpritefile, this->birdSprite);
	ReadObjectSprite(this->dinosaurSpritefile, this->dinosaurSprite);
	ReadObjectSprite(this->carSpritefile, this->carSprite);
	ReadObjectSprite(this->tankSpritefile, this->tankSprite);
	ReadObjectSprite(this->peopleSpritefile, this->peopleSprite);
}

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
CGame::~CGame() {
	for (int i = 0; i < this->birds.size(); i++)
		delete this->birds[i];
	for (int i = 0; i < this->dinos.size(); i++)
		delete this->dinos[i];
	for (int i = 0; i < this->cars.size(); i++)
		delete this->cars[i];
	for (int i = 0; i < this->tanks.size(); i++)
		delete this->tanks[i];
}

void CGame::UpdatePosTank() { //tanks go left
	int w = this->tanks[0]->GetBotRight().GetX() - this->tanks[0]->GetTopLeft().GetX();
	for (int i = 0; i < this->tanks.size(); i++) {
		this->tanks[i]->Move(-1, 0);

		if (this->tanks[i]->GetTopLeft().GetX() <= this->topleft.GetX()) {
			this->tanks[i]->SetTopLeft(this->botright.GetX() - w, this->tanks[i]->GetTopLeft().GetY());
			this->tanks[i]->SetBotRight(this->tanks[i]->GetTopLeft().GetX() + w, this->tanks[i]->GetBotRight().GetY());
		}
	}
}

void CGame::UpdatePosCar() {
	int w = this->cars[0]->GetBotRight().GetX() - this->cars[0]->GetTopLeft().GetX() + 1;
	for (int i = 0; i < this->cars.size(); i++) {
		this->cars[i]->Move(-1, 0);

		if (this->cars[i]->GetTopLeft().GetX() <= this->topleft.GetX()) {
			this->cars[i]->SetTopLeft(this->botright.GetX() - w, this->cars[i]->GetTopLeft().GetY());
			this->cars[i]->SetBotRight(this->cars[i]->GetTopLeft().GetX() + w, this->cars[i]->GetBotRight().GetY());
		}
	}
}

void CGame::UpdatePosBird() {
	int w = this->birds[0]->GetBotRight().GetX() - this->birds[0]->GetTopLeft().GetX() + 1;
	for (int i = 0; i < this->birds.size(); i++) {
		this->birds[i]->Move(1, 0);

		if (this->birds[i]->GetBotRight().GetX() >= this->botright.GetX()) {
			this->birds[i]->SetTopLeft(this->topleft.GetX() + 1, this->birds[i]->GetTopLeft().GetY());
			this->birds[i]->SetBotRight(this->birds[i]->GetTopLeft().GetX() + w, this->birds[i]->GetBotRight().GetY());
		}

	}
}

void CGame::UpdatePosDino() {
	int w = this->dinos[0]->GetBotRight().GetX() - this->dinos[0]->GetTopLeft().GetX() + 1;
	for (int i = 0; i < this->birds.size(); i++) {
		this->dinos[i]->Move(1, 0);

		if (this->dinos[i]->GetBotRight().GetX() >= this->botright.GetX()) {
			this->dinos[i]->SetTopLeft(this->topleft.GetX() + 1, this->dinos[i]->GetTopLeft().GetY());
			this->dinos[i]->SetBotRight(this->dinos[i]->GetTopLeft().GetX() + w, this->dinos[i]->GetBotRight().GetY());
		}

	}
}

void CGame::UpdatePosPeople(char direction) {
	if (direction == 'w' && !(this->people.GetTopLeft().GetY() == this->topleft.GetY() + 1)) {
		this->people.Move(0, -1);
	}
	else if (direction == 's' && !(this->people.GetBotRight().GetY() == this->botright.GetY() - 1)) {
		this->people.Move(0, 1);
	}
	else if (direction == 'a'  && !(this->people.GetTopLeft().GetX() == this->topleft.GetX() + 1)) {
		this->people.Move(-1, 0);
	}
	else if (direction == 'd' && !(this->people.GetBotRight().GetX() == this->botright.GetX() - 1)) {
		this->people.Move(1, 0);
	}
}

void CGame::DeleteObjectSprite(int x, int y, const vector<string>& objectSprite) {
	int index = 0;
	for (auto iter = objectSprite.begin(); iter != objectSprite.end(); iter++) {
		GotoXY(x, y + index);
		for (int i = 0; i < (*iter).size(); i++) cout << " ";
		index++;
	}
}

void CGame::DrawObjectSprite(int x, int y, const vector<string>& objectSprite) {
	int index = 0;
	for (auto iter = objectSprite.begin(); iter != objectSprite.end(); iter++) {
		GotoXY(x, y + index);
		cout << *iter << endl;
		index++;
	}
}

void CGame::ReadObjectSprite(string filename, vector<string>& objectSprite) {
	ifstream fin(filename);
	string line;
	while (!fin.eof()) {
		getline(fin, line);
		objectSprite.push_back(line);
	}
	fin.close();
}

void CGame::Draw() {
	Point2D pos;
	for (int i = 0; i < this->objectsPerRow; i++) {
		//bird
		pos = this->birds[i]->GetTopLeft();
		DrawObjectSprite(pos.GetX(), pos.GetY(), this->birdSprite);
		//dino
		pos = this->dinos[i]->GetTopLeft();
		DrawObjectSprite(pos.GetX(), pos.GetY(), this->dinosaurSprite);
		//car
		pos = this->cars[i]->GetTopLeft();
		DrawObjectSprite(pos.GetX(), pos.GetY(), this->carSprite);
		//tank
		pos = this->tanks[i]->GetTopLeft();
		DrawObjectSprite(pos.GetX(), pos.GetY(), this->tankSprite);
	}
	//people
	pos = this->people.GetTopLeft();
	DrawObjectSprite(pos.GetX(), pos.GetY(), this->peopleSprite);
}

void CGame::Update() {
	UpdatePosBird();
	UpdatePosDino();
	UpdatePosCar();
	UpdatePosTank();
	if (_kbhit()) {
		DeleteObjectSprite(this->people.GetTopLeft().GetX(), this->people.GetTopLeft().GetY(), this->peopleSprite);
		char c = _getch();
		UpdatePosPeople(c);
	}
}
void CGame::Clean() {
	Point2D pos;
	for (int i = 0; i < this->objectsPerRow; i++) {
		//bird
		pos = this->birds[i]->GetTopLeft();
		DeleteObjectSprite(pos.GetX(), pos.GetY(), this->birdSprite);
		//dino
		pos = this->dinos[i]->GetTopLeft();
		DeleteObjectSprite(pos.GetX(), pos.GetY(), this->dinosaurSprite);
		//car
		pos = this->cars[i]->GetTopLeft();
		DeleteObjectSprite(pos.GetX(), pos.GetY(), this->carSprite);
		//tank
		pos = this->tanks[i]->GetTopLeft();
		DeleteObjectSprite(pos.GetX(), pos.GetY(), this->tankSprite);
	}
}

void CGame::DrawBorder() {
	int x1 = this->topleft.GetX();
	int x2 = this->botright.GetX();
	int y1 = this->topleft.GetY();
	int y2 = this->botright.GetY();
	for (int i = x1; i <= x2; i++) {
		GotoXY(i, y1); cout << "=";
		GotoXY(i, y2); cout << "=";
	}
	for (int i = y1 + 1; i < y2; i++) {
		GotoXY(x1, i); cout << "|";
		GotoXY(x2, i); cout << "|";
	}
}
