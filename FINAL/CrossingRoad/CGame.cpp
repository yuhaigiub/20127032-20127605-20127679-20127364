#include "CGame.h"

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

//INITIALIZE ENEMIES FOR NEW LEVEL
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

	//TRAFFIC LIGHT
	this->carLight.SetTopLeft(128,10);
	this->tankLight.SetTopLeft(128,22);
	this->carLight.setState(true);
	this->tankLight.setState(true);
	
	_rand = rand() % (rand() % (200 - level) + 45 - level) + 45;
	this->tankLight.setDuration(_rand);
	_rand = rand() % (rand() % (200 - level) + 45 - level) + 45;
	this->carLight.setDuration(_rand);
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

void CGame::UpdateDurationCount() {
	//while (this->IS_RUNNING) {
	carLight.UpdateDurationStatus();
	tankLight.UpdateDurationStatus();
	//}
}

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

	for(int i = 0; i < this->tanks.size(); i++) {
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

void CGame::Update() {
	//update traffic light 
	UpdateDurationCount();

	//update enemy's position
	UpdatePosBird();
	UpdatePosDino();
	UpdatePosCar();
	UpdatePosTank();
}

void CGame::GetInput() {
	if (_kbhit()) {
		char c = tolower(_getch());
		if (c == 'p') { // pause
			this->IS_PAUSING = !this->IS_PAUSING;
		}
		else if (c == 'k') { // exit
			this->IS_RUNNING = false;
			this->StartMenu();
			this->StartGame();
		}
		else if (c == 'o') { // save
			string filename;
			int x = this->botright.GetX() + 3;
			int y = this->botright.GetY() / 3 + 8;
			GotoXY(x, y);
			cout << "Please enter the file name: ";
			getline(cin, filename);
			save_game(filename);
			GotoXY(x, y);
			cout << "                                        ";
		}
		else if (c == 'l') { // load
			string filename;
			int x = this->botright.GetX() + 3;
			int y = this->botright.GetY() / 3 + 8;
			GotoXY(x, y);
			cout << "Please enter the file name: ";
			getline(cin, filename);
			if (!load_game(filename)) {
				GotoXY(x, y + 1);
				cout << "Record not exist!";
				Sleep(2500);
			}
			LoadingScreen("Opening " + filename);
			DrawBorder();
		}
		else { //move player command
			if (this->IS_PAUSING == false) {
				DeleteObjectSprite(this->people.GetTopLeft().GetX(), this->people.GetTopLeft().GetY(), this->peopleSprite);
				UpdatePosPeople(c);
			}
		}
	}
}

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

void CGame::DrawBorder() {
	int x1 = this->topleft.GetX();
	int x2 = this->botright.GetX();
	int y1 = this->topleft.GetY();
	int y2 = this->botright.GetY();
	for (int i = x1; i <= x2; i++) {
		GotoXY(i, y1); cout << "=";
		GotoXY(i, y2); cout << "=";

		//draw lane
		GotoXY(i, 5); cout << "-";
		GotoXY(i, 9); cout << "-";
		GotoXY(i, 13); cout << "-";
		GotoXY(i, 21); cout << "-";
		GotoXY(i, 25); cout << "-";
	}
	for (int i = y1 + 1; i < y2; i++) {
		GotoXY(x1, i); cout << "|";
		GotoXY(x2, i); cout << "|";
	}


	//draw side menu
	int x = this->botright.GetX() + 10;
	int y = this->botright.GetY() / 3;

	GotoXY(++x, y++);
	cout << "LEVEL: " << this->level;
	GotoXY(x - 4, y++);
	cout << "------------------";
	x -= 2;
	GotoXY(x, y++);
	cout << "|----MENU----|";
	GotoXY(x, y++);
	cout << "|  Pause (P) |";
	GotoXY(x, y++);
	cout << "|  Save (O)  |";
	GotoXY(x, y++);
	cout << "|  Load (L)  |";
	GotoXY(x, y++);
	cout << "|  Exit (K)  |";
	GotoXY(x, y++);
	cout << "|------------|";

	x = this->topleft.GetX();
	y = this->botright.GetY() + 3;

	GotoXY(x, y++);
	cout << "Use W/A/S/D to move around. " << endl;
	GotoXY(x, y++);
	cout << "Your goal is to go up, avoid the obstacles and survive the levels! Good luck!" << endl;
	GotoXY(x, y++);
	cout << "SAVE the game and input your nickname." << endl;
	GotoXY(x, y++);
	cout << "LOAD the game using your nickname." << endl;
	GotoXY(x, y++);
	cout << "EXIT to return to main menu." << endl;
}

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

void CGame::drawTitle() {

	cout << "                                                                         00000000000" << endl;
	cout << "                                                                    0000000000000000000" << endl;
	cout << "                                                                000000000000000000000000000" << endl;
	cout << "                                                              00000000       ||       00000000" << endl;
	cout << "                                                            000000   \\       ||       //  000000" << endl;
	cout << " ******  *******   ******   ******   ******  ** **    **  ******       \\     ||     //     000000" << endl;
	cout << "**       **    ** **    ** **       **       ** ***   ** **              \\   ||   //        000000" << endl;
	cout << "**       ** * *   **    ** ********  ******  ** **  * ** **  ****          \\  - //           000000" << endl;
	cout << "**       **   **  **    **       **       ** ** **   *** **    **= = = = = =( 0 )= = = = = = 000000" << endl;
	cout << " ******  **    **  ******   ******   ******  ** **    **  ******           // - \\           000000" << endl;
	cout << "                                               *******   ******     **    ******* \\        000000" << endl;
	cout << "   ___________________________________________ **    ** **    **   **** / **    **  \\     000000" << endl;
	cout << "   ___________________________________________ ** * *   **    **  **  **  **    **    \\  000000" << endl;
	cout << "   ___________________________________________ **   **  **    ** ******** **    **      000000" << endl;
	cout << "                                               **    **  ******  **    ** *******   00000000" << endl;
	cout << "                                                                  0000000000000000000000" << endl;
	cout << "                                                                   000000000000000000" << endl;
	cout << "                                                                      000000000000" << endl;
}

//Change the print for loop (border of options)
void CGame::StartMenu() {
	system("cls");
	ScreenSetting(830, 480);
	if (this->music_state) {
		sndPlaySound(L"BGM_Menu.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	/*
		CROSSING ROAD
		-------------
		new game
		load game
		setting
		exit
	*/
	const string menu[4] = { "New Game","Load Game","Setting","Exit" };
	int pos = 0;
	const int x = 30;
	const int y = 20;
	int flag;
	string filename;
	int currentOption = 1;
	while (true) {
		flag = 0;
		system("cls");
		int color = rand() % 7 + 9;
		TextColor(color);
		drawTitle();
		TextColor(7);
		//TextColor(238);

		/*for (int i = 20; i <= 50; i++) {
			for (int j = y - 2; j <= y + 5; j++) {
				if (j == y - 2 || j == y + 5 || i == 20 || i == 50) {
					GotoXY(i, j);
					cout << "##";
				}
			}
		}*/

		//New one
		for (int j = y - 2; j <= y + 5; j++) {
			GotoXY(x - 10, j);
			if (j == y - 2 || j == y + 5) {
				cout << "################################";
			}
			else {
				cout << "##";
				GotoXY(x + 20, j);
				cout << "##";
			}
		}

		TextColor(7);
		for (int i = 0; i < 4; i++) {
			if (i == pos) {
				TextColor(227);
				GotoXY(x, y + i);
				cout << "> " << menu[i];
				TextColor(7);
			}
			else {
				GotoXY(x, y + i);
				cout << menu[i];
			}
		}
		while (true) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 'W' || key == 'w') {
					if (pos > 0)
						pos--;
					else
						pos = 3;	
					break;
				}
				if (key == 'S' || key == 's') {
					if (pos < 3)
						pos++;
					else
						pos = 0;
					break;
				}
				if (key == 13) { // hit enter
					switch (pos) {
					case 0: // start game
						SET_IS_RUNNING(true);
						flag = 1;
						this->level = 1;
						break;
					case 1: // load game
						GotoXY(x + 25, y + 1); cout << "Please enter the file name: ";
						getline(cin, filename);
						GotoXY(x + 25, y + 2);
						if (!load_game(filename)) {
							cout << "Record not exist!";
							Sleep(2500);
							flag = 2;
							break;
						}
						LoadingScreen("Opening " + filename);
						SET_IS_RUNNING(true);
						flag = 1;
						break;
					case 2:
						Setting();
						return this->StartMenu();
					case 3:
						system("cls");
						exit(0);
						break;
					}
				}
			}
			if (flag == 1) {
				SET_IS_RUNNING(true);
				return;
			}
			else if (flag == 2) {
				break;
			}
		}
	}
}

void CGame::Setting() {
	system("cls");
	string setting[] = { "Mode", "Sound" ,"Menu" };
	string mode_state[] = { ": EASY", ": HARD" };
	string sound_state[] = { ": OFF", ": ON" };
	int pos1 = 0;
	const int x = 30;
	const int y = 20;
	int flag = 0;
	while (true) {
		int color = rand() % 7 + 9;
		TextColor(color);
		drawTitle();
		TextColor(7);

		/*for (int i = 20; i <= 50; i++) {
			for (int j = y - 2; j <= y + 4; j++) {
				if (j == y - 2 || j == y + 4 || i == 20 || i == 50) {
					GotoXY(i, j);
					cout << "##";
				}
			}
		}*/

		//New one
		for (int j = y - 2; j <= y + 4; j++) {
			GotoXY(x - 10, j);
			if (j == y - 2 || j == y + 4) {
				cout << "################################";
			}
			else {
				cout << "##";
				GotoXY(x + 20, j);
				cout << "##";
			}
		}

		TextColor(7);
		for (int i = 0; i < 3; i++) {
			GotoXY(x, y + i);
			if (i == pos1) {
				TextColor(227);
				if (i == 0) {
					cout << "> " << setting[i] << mode_state[this->difficult_state];
				}
				else if (i == 1) {
					cout << "> " << setting[i] << sound_state[this->music_state];
				}
				else {
					cout << "> " << setting[i];
				}
				TextColor(7);
			}
			else {
				if (i == 0) {
					cout << setting[i] << mode_state[this->difficult_state];
				}
				else if (i == 1) {
					cout << setting[i] << sound_state[this->music_state];
				}
				else {
					cout << setting[i];
				}
			}
		}
		while (true) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 'W' || key == 'w') {
					if (pos1 > 0)
						pos1--;
					else
						pos1 = 2;
					break;
				}
				if (key == 'S' || key == 's') {
					if (pos1 < 2)
						pos1++;
					else
						pos1 = 0;
					break;
				}
				if (key == 13) {
					switch (pos1) {
					case 0:
						//doSth
						this->difficult_state = !this->difficult_state;
						break;
					case 1:
						//doSth
						this->music_state = !this->music_state;
						if (this->music_state == false) {
							sndPlaySound(NULL, SND_ASYNC);
						}
						else {
							sndPlaySound(L"BGM_Menu.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
						}
						break;
					case 2:
						//doSth
						//end settings and run the StartMenu
						return;
					}
					break;
				}
			}
		}
		system("cls");
	}
}

void CGame::EndMenu() {
	ScreenSetting(830, 480);
	/*
		YOU DIED
		continue
		main menu
	*/
	const string menu[2] = { "Continue","Main Menu" };
	int pos = 0;
	int x = 30;
	int y = 20;
	int flag = 0;
	while (true) {
		system("cls");
		int color = rand() % 7 + 9;
		TextColor(color);
		GotoXY(10, 10); cout << "**    **  ******  **    **    ******   ** ******* ******     !!! !!!" << endl;
		GotoXY(10, 11); cout << " **  **  **    ** **    **    **   **  ** **      **    **   !!! !!!" << endl;
		GotoXY(10, 12); cout << "  ****   **    ** **    **    **    ** ** ******  **     **  !!! !!!" << endl;
		GotoXY(10, 13); cout << "   **    **    ** **    **    **   **  ** **      **    **   !!! !!!" << endl;
		GotoXY(10, 14); cout << "   **     ******   ******     ******   ** ******* ******     @@@ @@@" << endl;
		TextColor(7);
		//Inefficient
		/*for (int i = 20; i <= 50; i++) {
			for (int j = y - 2; j <= y + 3; j++) {
				if (j == y - 2 || j == y + 3 || i == 20 || i == 50) {
					GotoXY(i, j);
					cout << "##";
				}
			}
		}*/

		for (int j = y - 2; j <= y + 3; j++) {
			GotoXY(x - 10, j);
			if (j == y - 2 || j == y + 3) {
				cout << "################################";
			}
			else {
				cout << "##";
				GotoXY(x + 20, j);
				cout << "##";
			}
		}

		TextColor(7);
		for (int i = 0; i < 2; i++) {
			if (i == pos) {
				TextColor(227);
				GotoXY(x, y + i);
				cout << "> " << menu[i];
				TextColor(7);
			}
			else {
				GotoXY(x, y + i);
				cout << menu[i];
			}
		}
		while (true) {
			if (_kbhit()) {
				char key = _getch();
				if (key == 'W' || key == 'w') {
					if (pos > 0)
						pos--;
					else
						pos = 1;
					break;
				}
				if (key == 'S' || key == 's') {
					if (pos < 1)
						pos++;
					else
						pos = 0;
					break;
				}
				if (key == 13) {
					switch (pos) {
					case 0:
						system("cls");
						SET_IS_RUNNING(true);
						flag = 1;
						this->level = 1;
						break;
					case 1:
						LoadingScreen("Back to Main Menu");
						return;
						break;
					}
				}
			}
			if (flag)
				return;
		}
	}
}

void CGame::StartGame() {
	system("cls");
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	ScreenSetting(SCREEN_WIDTH, SCREEN_HEIGHT);
	this->DrawBorder();
	if (this->music_state) {
		sndPlaySound(L"BGM_Playing.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	InitializePosition(this->level);		//please rewrite this function (and use level)
}

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

// modify to binary file for more protection
void CGame::save_game(string name) {
	string prefix("save/");
	string tail1("_people.bin");
	string tail2("_bird.bin");
	string tail3("_dinosaur.bin");
	string tail4("_car.bin");
	string tail5("_tank.bin");
	string temp;
	Point2D tl, br;
	ofstream fout;
	int n;
	//	output player
	temp = prefix + name + tail1;
	fout.open(temp, ios::binary, ios::trunc);
	tl = this->people.GetTopLeft();
	br = this->people.GetBotRight();
	fout.write((char*) &this->level, sizeof(int));
	fout.write((char*) &tl.GetX(), sizeof(int));
	fout.write((char*) &tl.GetY(), sizeof(int));
	fout.write((char*) &br.GetX(), sizeof(int));
	fout.write((char*) &br.GetY(), sizeof(int));
	fout.close();

	//	output bird
	temp = prefix + name + tail2;
	fout.open(temp, ios::binary, ios::trunc);
	n = this->birds.size();
	fout.write((char*) &n, sizeof(int));
	for (int i = 0; i < this->birds.size(); i++) {
		tl = this->birds[i]->GetTopLeft();
		br = this->birds[i]->GetBotRight();
		fout.write((char*) &tl.GetX(), sizeof(int));
		fout.write((char*) &tl.GetY(), sizeof(int));
		fout.write((char*) &br.GetX(), sizeof(int));
		fout.write((char*) &br.GetY(), sizeof(int));
	}
	fout.close();

	//	output dinosaur
	temp = prefix + name + tail3;
	fout.open(temp, ios::binary, ios::trunc);
	n = this->dinos.size();
	fout.write((char*)&n, sizeof(int));
	for (int i = 0; i < this->dinos.size(); i++) {
		tl = this->dinos[i]->GetTopLeft();
		br = this->dinos[i]->GetBotRight();
		fout.write((char*) &tl.GetX(), sizeof(int));
		fout.write((char*) &tl.GetY(), sizeof(int));
		fout.write((char*) &br.GetX(), sizeof(int));
		fout.write((char*) &br.GetY(), sizeof(int));
	}
	fout.close();

	//	output car 
	temp = prefix + name + tail4;
	fout.open(temp, ios::binary, ios::trunc);

	n = this->cars.size();
	fout.write((char*)&n, sizeof(int));
	for (int i = 0; i < this->cars.size(); i++) {
		tl = this->cars[i]->GetTopLeft();
		br = this->cars[i]->GetBotRight();
		fout.write((char*) &tl.GetX(), sizeof(int));
		fout.write((char*) &tl.GetY(), sizeof(int));
		fout.write((char*) &br.GetX(), sizeof(int));
		fout.write((char*) &br.GetY(), sizeof(int));
	}
	fout.close();

	// output tank
	temp = prefix + name + tail5;
	fout.open(temp, ios::binary, ios::trunc);

	n = this->tanks.size();
	fout.write((char*)&n, sizeof(int));
	for (int i = 0; i < this->tanks.size(); i++) {
		tl = this->tanks[i]->GetTopLeft();
		br = this->tanks[i]->GetBotRight();
		fout.write((char*) &tl.GetX(), sizeof(int));
		fout.write((char*) &tl.GetY(), sizeof(int));
		fout.write((char*) &br.GetX(), sizeof(int));
		fout.write((char*) &br.GetY(), sizeof(int));
	}
	fout.close();
}

bool CGame::load_game(string name) {
	string prefix("save/");
	string tail1("_people.bin");
	string tail2("_bird.bin");
	string tail3("_dinosaur.bin");
	string tail4("_car.bin");
	string tail5("_tank.bin");
	ifstream fin1, fin2, fin3, fin4, fin5;
	fin1.open(prefix + name + tail1, ios::binary);
	fin2.open(prefix + name + tail2, ios::binary);
	fin3.open(prefix + name + tail3, ios::binary);
	fin4.open(prefix + name + tail4, ios::binary);
	fin5.open(prefix + name + tail5, ios::binary);
	// can't open one of the files
	if (!fin1 || !fin2 || !fin3 || !fin4 || !fin5) return false;
	int n;
	int x, y;
	//read player
	fin1.read((char*) &this->level, sizeof(int));
	fin1.read((char*) &x, sizeof(int));
	fin1.read((char*) &y, sizeof(int));

	this->people.SetTopLeft(x, y);
	fin1.read((char*)&x, sizeof(int));
	fin1.read((char*)&y, sizeof(int));
	this->people.SetBotRight(x, y);

	//read bird
	CBird* b;
	this->birds.clear();
	fin2.read((char*)&n, sizeof(int));
	for (int i = 0; i < n; i++) {
		b = new CBird;
		fin2.read((char*)&x, sizeof(int));
		fin2.read((char*)&y, sizeof(int));
		b->SetTopLeft(x, y);
		fin2.read((char*)&x, sizeof(int));
		fin2.read((char*)&y, sizeof(int));
		b->SetBotRight(x, y);
		this->birds.push_back(b);
	}
	//read dinosaur
	CDinosaur* d;
	this->dinos.clear();
	fin3.read((char*)&n, sizeof(int));
	for (int i = 0; i < n; i++) {
		d = new CDinosaur;
		fin3.read((char*)&x, sizeof(int));
		fin3.read((char*)&y, sizeof(int));
		d->SetTopLeft(x, y);
		fin3.read((char*)&x, sizeof(int));
		fin3.read((char*)&y, sizeof(int));
		d->SetBotRight(x, y);
		this->dinos.push_back(d);
	}
	//read car
	CCar* c;
	this->cars.clear();
	fin4.read((char*)&n, sizeof(int));
	for (int i = 0; i < n; i++) {
		c = new CCar;
		fin4.read((char*)&x, sizeof(int));
		fin4.read((char*)&y, sizeof(int));
		c->SetTopLeft(x, y);
		fin4.read((char*)&x, sizeof(int));
		fin4.read((char*)&y, sizeof(int));
		c->SetBotRight(x, y);
		this->cars.push_back(c);
	}
	//read tank
	CTank* t;
	this->tanks.clear();
	fin5.read((char*)&n, sizeof(int));
	for (int i = 0; i < n; i++) {
		t = new CTank;
		fin5.read((char*)&x, sizeof(int));
		fin5.read((char*)&y, sizeof(int));
		t->SetTopLeft(x, y);
		fin5.read((char*)&x, sizeof(int));
		fin5.read((char*)&y, sizeof(int));
		t->SetBotRight(x, y);
		this->tanks.push_back(t);
	}

	fin1.close();
	fin2.close();
	fin3.close();
	fin4.close();
	fin5.close();
	return true;
}

void CGame::RIP() {
	DrawObjectSprite(this->people.GetTopLeft().GetX(), this->people.GetTopLeft().GetY(), this->RIPSprite);
	Sleep(3000);
	//DeleteObjectSprite(this->people.GetTopLeft().GetX(), this->people.GetTopLeft().GetY(), this->RIPSprite);

}

void CGame::LoadingScreen(string message) {
	ScreenSetting(830, 480);
	system("cls");
	drawTitle();
	GotoXY(40, 24);
	cout << message;
	GotoXY(20, 25);
	cout << "[";
	for (int i = 0; i <= 50; i++)
	{
		Sleep(35);
		GotoXY(20 + i, 25);
		cout << "=>";
		GotoXY(45, 26);
		cout << i * 2 << "%";
	}
	system("cls");
	ScreenSetting(1280, 720);
}