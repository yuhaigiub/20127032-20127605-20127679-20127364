//Nguyen added this
#include "CLight.h"

CLight::CLight() {
	duration = 0; // =0 -> changing on/off state nonstop?
	state = true; //green
	duration_count = 0; //start at 0
}

bool CLight::UpdateDurationStatus() {
	if (duration_count >= duration) {
		duration_count = 0;
		state = !state;
		return true;
	}
	else {
		duration_count++;
	}
	return false;
}

void CLight::SetTopLeft(int x, int y) {
	this->topleft.SetX(x);
	this->topleft.SetY(y);
}

void CLight::SetBotRight(int x, int y) {
	this->botright.SetX(x);
	this->botright.SetY(y);
}