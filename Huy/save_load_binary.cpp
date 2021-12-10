// change the save method to binary files for more protection


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
//Huy
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
