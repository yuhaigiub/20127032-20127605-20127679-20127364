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
	static string spritefile;
	static vector<string> sprite;
	Point2D top_left;
	Point2D bot_right;
public:
	void Up();
	void Down();
	void Left();
	void Right();

	Point2D GetTopLeft();
	void SetTopLeft(int x, int y);
	Point2D GetBotRight();
	void SetBotRight(int x, int y);
	void Move(int x, int y);
	bool CollisionAnimal(CAnimal& animal);
	bool CollisionVehicle(CVehicle& vehicle);
};

#endif // !C_PEOPLE_


