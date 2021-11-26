#include "CVehicle.h"

// getter / setter

Point2D CVehicle::GetTopLeft() { return this->topleft; }

void CVehicle::SetTopLeft(int x, int y) { this->topleft.SetX(x); this->topleft.SetY(y); }

Point2D CVehicle::GetBotRight() { return this->botright; }

void CVehicle::SetBotRight(int x, int y) { this->botright.SetX(x); this->botright.SetY(y); }

void CVehicle::Move(int x, int y) {
	this->topleft.SetX(this->topleft.GetX() + x);
	this->topleft.SetY(this->topleft.GetY() - y);
	this->botright.SetX(this->botright.GetX() + x);
	this->botright.SetY(this->botright.GetY() - y);
}