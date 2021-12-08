//load game progress from a series of .txt files, with player's name as keyword

bool CGame::load_game(string name) {
	string tail1("_people.txt");
	string tail2("_bird.txt");
	string tail3("_dinosaur.txt");
	string tail4("_car.txt");
	string tail5("_tank.txt");
	ifstream fin1, fin2, fin3, fin4, fin5;
	fin1.open(name + tail1);
	fin2.open(name + tail2);
	fin3.open(name + tail3);
	fin4.open(name + tail4);
	fin5.open(name + tail5);
	// can't open one of the files
	if (!fin1 || !fin2 || !fin3 || !fin4 || !fin5) return false;
	int n;
	int x, y;
	//read player
	fin1 >> this->level;
	fin1 >> x >> y;
	this->people.SetTopLeft(x, y);
	fin1 >> x >> y;
	this->people.SetBotRight(x, y);

	//read bird
	CBird* b;
	this->birds.clear();
	fin2 >> n;
	for (int i = 0; i < n; i++) {
		b = new CBird;
		fin2 >> x >> y;
		b->SetTopLeft(x, y);
		fin2 >> x >> y;
		b->SetBotRight(x, y);
		this->birds.push_back(b);
	}
	//read dinosaur
	CDinosaur* d;
	this->dinos.clear();
	fin3 >> n;
	for (int i = 0; i < n; i++) {
		d = new CDinosaur;
		fin3 >> x >> y;
		d->SetTopLeft(x, y);
		fin3 >> x >> y;
		d->SetBotRight(x, y);
		this->dinos.push_back(d);
	}
	//read car
	CCar* c;
	this->cars.clear();
	fin4 >> n;
	for (int i = 0; i < n; i++) {
		c = new CCar;
		fin4 >> x >> y;
		c->SetTopLeft(x, y);
		fin4 >> x >> y;
		c->SetBotRight(x, y);
		this->cars.push_back(c);
	}
	//read tank
	CTank* t;
	this->tanks.clear();
	fin5 >> n;
	for (int i = 0; i < n; i++) {
		t = new CTank;
		fin5 >> x >> y;
		t->SetTopLeft(x, y);
		fin5 >> x >> y;
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