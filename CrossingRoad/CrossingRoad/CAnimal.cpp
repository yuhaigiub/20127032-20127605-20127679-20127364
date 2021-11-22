#include "CAnimal.h"

// getter / setter

Point2D CAnimal::GetTopLeft() { return this->top_left; }

void CAnimal::SetTopLeft(int x, int y) { this->top_left.SetX(x); this->top_left.SetY(y); }

Point2D CAnimal::GetBotRight() { return this->bot_right; }

void CAnimal::SetBotRight(int x, int y) { this->bot_right.SetX(x); this->bot_right.SetY(y); }