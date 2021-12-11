#ifndef C_ANIMAL_
#define C_ANIMAL_

#include"Point2D.h"

class CAnimal
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

#endif // !C_ANIMAL_


