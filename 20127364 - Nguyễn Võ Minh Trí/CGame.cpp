#include "CGame.h"

CGame::CGame(int objectsPerRow) {
	this->objectsPerRow = objectsPerRow;

	// there's more


}

CGame::~CGame() {

}

//void CGame::DrawGame() {
//	people.draw();
//	GoToXY(topleft.GetX(), botright.GetY());
//	//cout << m_level - LV_MIN + 1;
//	for (int i = 0; i < m_level; i++) {
//		tanks[i].draw();
//		cars[i].draw();
//		birds[i].draw();
//		dinos[i]draw();
//	}
//	if (trafic.getStatus())
//		TextColor(ColorCode_Red);
//	else
//		textColor(ColoCode_Green);
//}

void CGame::UpdatePosTank() {
	for (int i = botright.GetX(); i < topleft.GetX(); i--) {
		tanks[i].deleteChar();
		tanks[i].move();
	}
}

void CGame::UpdatePosCar() {
	for (int i = botright.GetX(); i < topleft.GetX(); i--) {
		cars[i].deleteChar();
		cars[i].move();
	}
}

void CGame::UpdatePosBird() {
	for (int i = topleft.GetX(); i < botright.GetX(); i++) {
		birds[i].deleteChar();
		birds[i].move();
	}
}

void CGame::UpdatePosDino() {
	for (int i = topleft.GetX(); i < botright.GetX(); i++) {
		dinos[i].deleteChar();
		dinos[i].move();
	}
}

void CGame::UpdatePosPeople(char moving) {
	//people.deleteChar();
	if (moving == 'a' || moving == 'A')
		people.Left();
	if (moving == 'd' || moving == 'D')
		people.Right();
	if (moving == 'w' || moving == 'W')
		people.Up();
	if (moving == 's' || moving == 'S')
		people.Down();
}