#include "CPeople.h"

Point2D CPeople::GetTopLeft() {
	return this->top_left;
}
void CPeople::SetTopLeft(int x, int y) {
	this->top_left.SetX(x);
	this->top_left.SetY(y);
}
Point2D CPeople::GetBotRight() {
	return this->bot_right;
}

void CPeople::SetBotRight(int x, int y) {
	this->bot_right.SetX(x);
	this->bot_right.SetY(y);
}

void CPeople::Move(int x, int y) {
	this->top_left.SetX(this->top_left.GetX() + x);
	this->top_left.SetX(this->top_left.GetX() + x);
	this->bot_right.SetY(this->bot_right.GetY() - y);
	this->bot_right.SetY(this->bot_right.GetY() - y);
}

bool CPeople::CollisionAnimal(CAnimal& animal) {
	/*Point2D pTL = GetTopLeft();
	Point2D pBR = GetBotRight();
	Point2D aTL = animal.GetTopLeft();
	Point2D aBR = animal.GetBotRight();
	int distX = (pTL.GetX() + pBR.GetX() / 2) - (aTL.GetX() + aBR.GetX());
	if (distX < 0)
		distX = -distX;

	float distW = ((float)pBR.GetX() + (float)aBR.GetX()) / 2;

	int distY = (pTL.GetY() + pBR.GetY() / 2) - (aTL.GetY() + aBR.GetY() / 2);
	if (distY < 0)
		distY = -distY;
	float distH = ((float)pBR.GetY() + (float)aBR.GetY()) / 2;
	return (distX <= distW && distY <= distH) ? true : false;*/

	Point2D pTL = GetTopLeft();
	Point2D pBR = GetBotRight();
	Point2D aTL = animal.GetTopLeft();
	Point2D aBR = animal.GetBotRight();
	if (pTL.GetX() > aTL.GetX() && pTL.GetX() < aBR.GetX()) {
		if (pTL.GetY() > aTL.GetY() && pTL.GetY() < aBR.GetY())
			return true;
	}
	if (pTL.GetX() > aTL.GetX() && pTL.GetX() < aBR.GetX()) {
		if (pBR.GetY() > aTL.GetY() && pBR.GetY() < aBR.GetY())
			return true;
	}
	if (pBR.GetX() > aTL.GetX() && pBR.GetX() < aBR.GetX()) {
		if (pTL.GetY() > aTL.GetY() && pTL.GetY() < aBR.GetY())
			return true;
	}
	if (pBR.GetX() > aTL.GetX() && pBR.GetX() < aBR.GetX()) {
		if (pBR.GetY() > aTL.GetY() && pBR.GetY() < aBR.GetY())
			return true;
	}
}

bool CPeople::CollisionVehicle(CVehicle& vehicle) {
	Point2D pTL = GetTopLeft();
	Point2D pBR = GetBotRight();
	Point2D vTL = vehicle.GetTopLeft();
	Point2D vBR = vehicle.GetBotRight();
	if (pTL.GetX() > vTL.GetX() && pTL.GetX() < vBR.GetX()) {
		if (pTL.GetY() > vTL.GetY() && pTL.GetY() < vBR.GetY())
			return true;
	}
	if (pTL.GetX() > vTL.GetX() && pTL.GetX() < vBR.GetX()) {
		if (pBR.GetY() > vTL.GetY() && pBR.GetY() < vBR.GetY())
			return true;
	}
	if (pBR.GetX() > vTL.GetX() && pBR.GetX() < vBR.GetX()) {
		if (pTL.GetY() > vTL.GetY() && pTL.GetY() < vBR.GetY())
			return true;
	}
	if (pBR.GetX() > vTL.GetX() && pBR.GetX() < vBR.GetX()) {
		if (pBR.GetY() > vTL.GetY() && pBR.GetY() < vBR.GetY())
			return true;
	}
} 

