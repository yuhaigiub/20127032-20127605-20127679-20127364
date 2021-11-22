#include "CVehicle.h"

// getter / setter

Point2D CVehicle::GetTopLeft() { return this->top_left; }

void CVehicle::SetTopLeft(int x, int y) { this->top_left.SetX(x); this->top_left.SetY(y); }

Point2D CVehicle::GetBotRight() { return this->bot_right; }

void CVehicle::SetBotRight(int x, int y) { this->bot_right.SetX(x); this->bot_right.SetY(y); }