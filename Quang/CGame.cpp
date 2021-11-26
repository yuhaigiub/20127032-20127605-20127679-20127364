#include "CGame.h"

CGame::CGame(int objectsPerRow, int width, int height) {
	this->objectsPerRow = objectsPerRow;
	
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

	//set objects initial position
	InitializePosition();
}

void CGame::InitializePosition() {
	int DEFAULT_BIRD_Y = 7;
	int DEFAULT_CAR_Y = 11;
	int DEFAULT_DINO_Y = 14;
	int DEFAULT_TANK_Y = 19;
	int DEFAULT_PEOPLE_Y = 25;
	//bird
	int w = 1, multiplier, x;
	for (int i = 0; i < this->birdSprite.size(); i++)
		if (w < this->birdSprite[i].size())
			w = this->birdSprite[i].size();
	x = this->botright.GetX() - w;
	multiplier = this->botright.GetX() / w;

	this->birds.clear();
	
	for (int i = 0; i < this->objectsPerRow; i++) {
		CBird* b = new CBird;
		b->SetTopLeft(x - i * multiplier, DEFAULT_BIRD_Y); 
		b->SetBotRight(b->GetTopLeft().GetX() + w, DEFAULT_BIRD_Y);
		this->birds.push_back(b);
	}

	//dino
	w = 1;
	for (int i = 0; i < this->dinosaurSprite.size(); i++)
		if (w < this->dinosaurSprite[i].size())
			w = this->dinosaurSprite[i].size();
	x = this->botright.GetX() - w;
	multiplier = this->botright.GetX() / w;

	this->dinos.clear();

	for (int i = 0; i < this->objectsPerRow; i++) {
		CDinosaur* d = new CDinosaur;
		d->SetTopLeft(x - i * multiplier, DEFAULT_DINO_Y);
		d->SetBotRight(d->GetTopLeft().GetX() + w, DEFAULT_DINO_Y);
		this->dinos.push_back(d);
	}

	//car
	w = 1;
	for (int i = 0; i < this->carSprite.size(); i++)
		if (w < this->carSprite[i].size())
			w = this->carSprite[i].size();
	x = this->topleft.GetX() + 1;
	multiplier = this->botright.GetX() / w;

	this->cars.clear();

	for (int i = 0; i < this->objectsPerRow; i++) {
		CCar* c = new CCar;
		c->SetTopLeft(x + i * multiplier, DEFAULT_CAR_Y);
		c->SetBotRight(c->GetTopLeft().GetX() + w, DEFAULT_CAR_Y);
		this->cars.push_back(c);
	}

	//tank
	w = 1;
	for (int i = 0; i < this->tankSprite.size(); i++)
		if (w < this->tankSprite[i].size())
			w = this->tankSprite[i].size();
	x = this->topleft.GetX() + 1;
	multiplier = this->botright.GetX() / w;

	this->tanks.clear();

	for (int i = 0; i < this->objectsPerRow; i++) {
		CTank* t = new CTank;
		t->SetTopLeft(x + i * multiplier, DEFAULT_TANK_Y);
		t->SetBotRight(t->GetTopLeft().GetX() + w, DEFAULT_TANK_Y);
		this->tanks.push_back(t);
	}

	//People
	this->people.SetTopLeft(2*this->botright.GetX() / 3,DEFAULT_PEOPLE_Y);
	this->people.SetBotRight(this->people.GetTopLeft().GetX() + 3,DEFAULT_PEOPLE_Y + 3);
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