#include<iostream>
#include "CPeople.h"
#include"CConsole.h"
using namespace std;

bool CPeople::CollisionAnimal(CAnimal& animal) {		
	Point2D pTL = GetTopLeft();
	Point2D pBR = GetBotRight();
	Point2D aTL = animal.GetTopLeft();
	Point2D aBR = animal.GetBotRight();

	if (pTL.GetX() > aTL.GetX() && pTL.GetX() <= aBR.GetX()) {
		if (pTL.GetY() >= aTL.GetY() && pTL.GetY() <= aBR.GetY()) {
			/*GotoXY(5, 32); cout << "Here1";
			GotoXY(5, 33); cout << pTL.GetX() << " " << pTL.GetY() << " " << pBR.GetX() << " " << pBR.GetY();
			GotoXY(5, 34); cout << aTL.GetX() << " " << aTL.GetY() << " " << aBR.GetX() << " " << aBR.GetY();*/

			return true;
		}
		if (pBR.GetY() >= aTL.GetY() && pBR.GetY() <= aBR.GetY()) {
			/*GotoXY(5, 32); cout << "Here2";
			GotoXY(5, 33); cout << pTL.GetX() << " " << pTL.GetY() << " " << pBR.GetX() << " " << pBR.GetY();
			GotoXY(5, 34); cout << aTL.GetX() << " " << aTL.GetY() << " " << aBR.GetX() << " " << aBR.GetY();*/

			return true;
		}
	}

	if (pBR.GetX() > aTL.GetX() && pBR.GetX() <= aBR.GetX()) {
		if (pTL.GetY() >= aTL.GetY() && pTL.GetY() <= aBR.GetY()) {
			/*GotoXY(5, 32); cout << "Here3";
			GotoXY(5, 33); cout << pTL.GetX() << " " << pTL.GetY() << " " << pBR.GetX() << " " << pBR.GetY();
			GotoXY(5, 34); cout << aTL.GetX() << " " << aTL.GetY() << " " << aBR.GetX() << " " << aBR.GetY();*/

			return true;
		}
		if (pBR.GetY() >= aTL.GetY() && pBR.GetY() <= aBR.GetY()) {
			/*GotoXY(5, 32); cout << "Here4";
			GotoXY(5, 33); cout << pTL.GetX() << " " << pTL.GetY() << " " << pBR.GetX() << " " << pBR.GetY();
			GotoXY(5, 34); cout << aTL.GetX() << " " << aTL.GetY() << " " << aBR.GetX() << " " << aBR.GetY();*/

			return true;
		}
	}

	return false;
}

bool CPeople::CollisionVehicle(CVehicle& vehicle) {			//works well
	Point2D pTL = GetTopLeft();
	Point2D pBR = GetBotRight();
	Point2D vTL = vehicle.GetTopLeft();
	Point2D vBR = vehicle.GetBotRight();
	if (pTL.GetX() >= vTL.GetX() && pTL.GetX() < vBR.GetX()) {
		if (pTL.GetY() >= vTL.GetY() && pTL.GetY() <= vBR.GetY()) {
			/*GotoXY(5, 32); cout << "Here1";
			GotoXY(5, 33); cout << pTL.GetX() << " " << pTL.GetY() << " " << pBR.GetX() << " " << pBR.GetY();
			GotoXY(5, 34); cout << vTL.GetX() << " " << vTL.GetY() << " " << vBR.GetX() << " " << vBR.GetY();*/

			return true;
		}
		if (pBR.GetY() >= vTL.GetY() && pBR.GetY() <= vBR.GetY()) {
			/*GotoXY(5, 32); cout << "Here2";
			GotoXY(5, 33); cout << pTL.GetX() << " " << pTL.GetY() << " " << pBR.GetX() << " " << pBR.GetY();
			GotoXY(5, 34); cout << vTL.GetX() << " " << vTL.GetY() << " " << vBR.GetX() << " " << vBR.GetY();*/

			return true;
		}
	}

	if (pBR.GetX() >= vTL.GetX() && pBR.GetX() < vBR.GetX()) {
		if (pTL.GetY() >= vTL.GetY() && pTL.GetY() <= vBR.GetY()) {
			/*GotoXY(5, 32); cout << "Here3";
			GotoXY(5, 33); cout << pTL.GetX() << " " << pTL.GetY() << " " << pBR.GetX() << " " << pBR.GetY();
			GotoXY(5, 34); cout << vTL.GetX() << " " << vTL.GetY() << " " << vBR.GetX() << " " << vBR.GetY();*/

			return true;
		}
		if (pBR.GetY() >= vTL.GetY() && pBR.GetY() <= vBR.GetY()) {
			/*GotoXY(5, 32); cout << "Here4";
			GotoXY(5, 33); cout << pTL.GetX() << " " << pTL.GetY() << " " << pBR.GetX() << " " << pBR.GetY();
			GotoXY(5, 34); cout << vTL.GetX() << " " << vTL.GetY() << " " << vBR.GetX() << " " << vBR.GetY();*/

			return true;
		}
	}

	return false;
}