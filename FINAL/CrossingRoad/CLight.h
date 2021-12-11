//Nguyen added this

#ifndef C_LIGHT_
#define C_LIGHT_

#include"Point2D.h"
#include<cstdlib>

class CLight
{
private:
	Point2D topleft;
	Point2D botright;
	int duration;
	bool state; // 0=red, 1=green
	int duration_count;
public:
	CLight();
	Point2D GetTopLeft() { return topleft; }
	Point2D GetBotRight() { return botright; }

	bool getState() { return state; }
	void setState(bool change) { state = change; }

	int getDuration() { return duration; }
	void setDuration(int x) { duration = x; }

	int getDurationCount() { return duration_count; }

	bool UpdateDurationStatus();

	void SetTopLeft(int x, int y);
	void SetBotRight(int x, int y);
};

#endif
