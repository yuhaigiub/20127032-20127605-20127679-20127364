#include "CPeople.h"

Point2D CPeople::GetTopLeft() {
	return this->topleft;
}
void CPeople::SetTopLeft(int x, int y) {
	this->topleft.SetX(x);
	this->topleft.SetY(y);
}
Point2D CPeople::GetBotRight() {
	return this->botright;
}

void CPeople::SetBotRight(int x, int y) {
	this->botright.SetX(x);
	this->botright.SetY(y);
}

void CPeople::Move(int x, int y) {
	this->topleft.SetX(this->topleft.GetX() + x);
	this->topleft.SetX(this->topleft.GetX() + x);
	this->botright.SetY(this->botright.GetY() - y);
	this->botright.SetY(this->botright.GetY() - y);
}

bool CPeople::CollisionAnimal(CAnimal& animal) {
	return true;
}

bool CPeople::CollisionVehicle(CVehicle& vehicle) {
	return true;
}