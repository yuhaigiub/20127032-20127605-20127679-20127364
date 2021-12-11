#ifndef C_PEOPLE_
#define C_PEOPLE_

#include"Point2D.h"
#include"CAnimal.h"
#include"CVehicle.h"
#include<iostream>
#include<vector>
using std::string;
using std::vector;

class CPeople
{
private:
	Point2D topleft;
	Point2D botright;
	Point2D speed;
public:
	CPeople(int speedX = 1, int speedY = 1);
	Point2D GetSpeed();
	void SetSpeed(int x, int y);
	Point2D GetTopLeft();
	void SetTopLeft(int x, int y);
	Point2D GetBotRight();
	void SetBotRight(int x, int y);
	void Move(int x, int y);
	bool CollisionAnimal(CAnimal& animal);
	bool CollisionVehicle(CVehicle& vehicle);
};

#endif // !C_PEOPLE_