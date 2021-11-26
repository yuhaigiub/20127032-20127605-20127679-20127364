/*
#include"Point2D.h"
#include"CPeople.h"
#include"CAnimal.h"
#include"CVehicle.h"
*/

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//	in CGame class
void save_game(string name) {
	string tail1("_player.txt");
	string tail2("_bird.txt");
	string tail3("_dinosaur.txt");
	string tail4("_car.txt");
	string tail5("_tank.txt");

	//	output player
	string temp = name;
	temp += tail1;
	ofstream fout1(temp);
		//	should make a player.output(); Point2D.output() instead
	//fout1 << player.GetTopLeft().GetX() << " " << player.GetTopLeft().GetY() << " " << player.GetBotRight().GetX() << " " << player.GetBotRight().GetY() << endl;


	//	output bird (bird vector)
	temp = name;
	temp += tail2;
	ofstream fout2(temp);
	
	/*fout2 << bird.size() << endl;
	for (int i = 0;i < bird.size();i++) {
		fout2 << bird[i].GetTopLeft().GetX() << " " << bird[i].GetTopLeft().GetY() << " " << bird[i].GetBotRight().GetX() << " " << bird[i].GetBotRight().GetY() << endl;
	}*/


	//	output dinosaur (dino vector)
	temp = name;
	temp += tail3;
	ofstream fout3(temp);

	/*fout3 << dino.size() << endl;
	for (int i = 0;i < dino.size();i++) {
		//	output each element like above
	}*/


	//	output car (car vector)
	temp = name;
	temp += tail4;
	ofstream fout4(temp);

	/*fout3 << car.size() << endl;
	for (int i = 0;i < car.size();i++) {
		//output each element like above
	}*/


	//	output tank (tank vector)
	temp = name;
	temp += tail5;
	ofstream fout5(temp);

	/*fout5 << tank.size() << endl;
	for (int i = 0;i < tank.size();i++) {
		//output each element like above
	}*/
}

void load_game(string name) {
	string tail1("_player.txt");
	string tail2("_bird.txt");
	string tail3("_dinosaur.txt");
	string tail4("_car.txt");
	string tail5("_tank.txt");
	int n;

	//	input player
	string temp = name;
	temp += tail1;
	ifstream fin1(temp);
	if (fin1) {
		//player.input();
	}
	else cout << "Can't open " << temp << endl;

	//	input bird
	temp = name;
	temp += tail2;
	ifstream fin2(temp);
	if (fin2) {
		cin >> n;
		for (int i = 0;i < n;i++) {
			//bird.input();
			//bird_vector.pushback(bird);
		}
	}
	else cout << "Can't open " << temp << endl;

	//	input dinosaur
	temp = name;
	temp += tail3;
	ifstream fin3(temp);
	if (fin3) {
		cin >> n;
		for (int i = 0;i < n;i++) {
			//dino.input();
			//dino_vector.pushback(dino);
		}
	}
	else cout << "Can't open " << temp << endl;

	//	input car
	temp = name;
	temp += tail4;
	ifstream fin4(temp);
	if (fin4) {
		cin >> n;
		for (int i = 0;i < n;i++) {
			//car.input();
			//car_vector.pushback(car);
		}
	}
	else cout << "Can't open " << temp << endl;

	//	input tank
	temp = name;
	temp += tail5;
	ifstream fin5(temp);
	if (fin5) {
		cin >> n;
		for (int i = 0;i < n;i++) {
			//tank.input();
			//tank_vector.pushback(bird);
		}
	}
	else cout << "Can't open " << temp << endl;
}

int main()
{

}