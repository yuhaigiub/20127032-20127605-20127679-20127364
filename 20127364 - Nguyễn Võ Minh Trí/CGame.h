#ifndef C_GAME_
#define C_GAME_

#include"CPeople.h"
#include"CBird.h"
#include"CDinosaur.h"
#include"CCar.h"
#include"CTank.h"
#include<vector>
using std::vector;

class CGame
{
private:
	Point2D topleft;
	Point2D botright;
	int objectsPerRow;
	CPeople people;
	vector<CBird> birds;
	vector<CDinosaur> dinos;
	vector<CCar> cars;
	vector<CTank> tanks;
public:
	CGame(int objectsPerRow = 0); //initialize variables for the game
	~CGame();
	void DrawGame();
	void UpdatePosTank();
	void UpdatePosCar();
	void UpdatePosBird();
	void UpdatePosDino();
	void UpdatePosPeople(char moving);
};

#endif // !C_GAME_

/*
* Default board structure
* 
* 
	* *************************************************************************************************
	*                                                                                                 *
	* |--------------------------------------------------------|         score: xxx                   *
	* |                  player safe zone                      |   ----------------------             *
	* |--------------------------------------------------------|     |------MENU------|               *
	* |                      bird lane --->                    |     | pause game (p) |               *
	* |--------------------------------------------------------|     | load game  (l) |               * 
	* |                 <--- car lane                          |     | exit       (q) |               *  
	* |--------------------------------------------------------|     |----------------|               *
	* |                    dinosaur lane --->                  |                                      *
	* |--------------------------------------------------------|                                      *
	* |                 <--- tank lane                         |                                      *
	* |--------------------------------------------------------|                                      *
	* |                  player safe zone                      |                                      *
	* |--------------------------------------------------------|                                      *
	*                                                                                                 *
	* *************************************************************************************************
*
* 
*/