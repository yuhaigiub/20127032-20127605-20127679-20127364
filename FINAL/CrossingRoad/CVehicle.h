#ifndef C_VEHICLE_
#define C_VEHICLE_

#include"Point2D.h"

class CVehicle
{
private:
	Point2D topleft;
	Point2D botright;
public:
	// getter/ setter
	Point2D GetTopLeft();
	void SetTopLeft(int x, int y);
	Point2D GetBotRight();
	void SetBotRight(int x, int y);
	void Move(int x, int y);
};

#endif // !C_VEHICLE_


