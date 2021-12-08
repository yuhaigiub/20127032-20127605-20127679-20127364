//save game progress into a series of .txt files, with player's name as keyword

void CGame::save_game(string name) {
	string tail1("_people.txt");
	string tail2("_bird.txt");
	string tail3("_dinosaur.txt");
	string tail4("_car.txt");
	string tail5("_tank.txt");
	string temp;
	Point2D tl, br;
	ofstream fout;

	//	output player
	temp = name + tail1;
	fout.open(temp);
	tl = this->people.GetTopLeft();
	br = this->people.GetBotRight();
	fout << this->level << endl;
	fout << tl.GetX() << " " << tl.GetY() << " " << br.GetX() << " " << br.GetY() << endl;
	fout.close();

	//	output bird
	temp = name + tail2;
	fout.open(temp);

	fout << this->birds.size() << endl;
	for (int i = 0; i < this->birds.size(); i++) {
		tl = this->birds[i]->GetTopLeft();
		br = this->birds[i]->GetBotRight();
		fout << tl.GetX() << " " << tl.GetY() << " " << br.GetX() << " " << br.GetY() << endl;
	}
	fout.close();

	//	output dinosaur
	temp = name + tail3;
	fout.open(temp);

	fout << this->dinos.size() << endl;
	for (int i = 0; i < this->dinos.size(); i++) {
		tl = this->dinos[i]->GetTopLeft();
		br = this->dinos[i]->GetBotRight();
		fout << tl.GetX() << " " << tl.GetY() << " " << br.GetX() << " " << br.GetY() << endl;
	}
	fout.close();

	//	output car 
	temp = name + tail4;
	fout.open(temp);

	fout << this->cars.size() << endl;
	for (int i = 0; i < this->cars.size(); i++) {
		tl = this->cars[i]->GetTopLeft();
		br = this->cars[i]->GetBotRight();
		fout << tl.GetX() << " " << tl.GetY() << " " << br.GetX() << " " << br.GetY() << endl;
	}
	fout.close();

	// output tank
	temp = name + tail5;
	fout.open(temp);

	fout << this->tanks.size() << endl;
	for (int i = 0; i < this->tanks.size(); i++) {
		tl = this->tanks[i]->GetTopLeft();
		br = this->tanks[i]->GetBotRight();
		fout << tl.GetX() << " " << tl.GetY() << " " << br.GetX() << " " << br.GetY() << endl;
	}
	fout.close();
}
