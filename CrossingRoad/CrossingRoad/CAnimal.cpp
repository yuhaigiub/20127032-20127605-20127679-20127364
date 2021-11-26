#include "CAnimal.h"

// getter / setter

Point2D CAnimal::GetTopLeft() { return this->topleft; }

void CAnimal::SetTopLeft(int x, int y) { this->topleft.SetX(x); this->topleft.SetY(y); }

Point2D CAnimal::GetBotRight() { return this->botright; }

void CAnimal::SetBotRight(int x, int y) { this->botright.SetX(x); this->botright.SetY(y); }

void CAnimal::Move(int x, int y) {
	this->topleft.SetX(this->topleft.GetX() + x);
	this->topleft.SetY(this->topleft.GetY() - y);
	this->botright.SetX(this->botright.GetX() + x);
	this->botright.SetY(this->botright.GetY() - y);
}