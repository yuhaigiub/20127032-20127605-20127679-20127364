#ifndef POINT_2D_
#define POINT_2D_

class Point2D
{
private:
	int x, y;
public:
	int &GetX() { return this->x; }
	void SetX(int x) { this->x = x; }
	int &GetY() { return this->y; }
	void SetY(int y) { this->y = y; }
	
	Point2D(int x = 0, int y = 0);
};

#endif // !POINT_2D_


