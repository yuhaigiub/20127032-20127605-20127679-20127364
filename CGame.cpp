#include "CGame.h"

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
			return true;
		}

	for (int i = 0; i < this->dinos.size(); i++)
		if (this->people.CollisionAnimal(*this->dinos[i])) {
			this->IS_RUNNING = false;
			return true;
		}

	for (int i = 0; i < this->cars.size(); i++)
		if (this->people.CollisionVehicle(*this->cars[i])) {
			this->IS_RUNNING = false;
			return true;
		}

	for (int i = 0; i < this->tanks.size(); i++)
		if (this->people.CollisionVehicle(*this->tanks[i])) {
			this->IS_RUNNING = false;
			return true;
		}
	return false;
}