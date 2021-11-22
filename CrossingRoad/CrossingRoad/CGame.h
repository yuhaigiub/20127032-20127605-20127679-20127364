#ifndef C_GAME_
#define C_GAME_

#include"CPeople.h"
#include"CBird.h"
#include"CDinosaur.h"
#include"CCar.h"
#include"CTruck.h"
#include<vector>
using std::vector;

class CGame
{
private:
	int objectsPerRow;
	CPeople people;
	vector<CBird> birds;
	vector<CDinosaur> dinos;
	vector<CCar> cars;
	vector<CTruck> trucks;
public:
	CGame(int objectsPerRow = 0); //initialize variables for the game
	~CGame();
	void DrawGame();
	void UpdatePosTruck();
	void UpdatePosCar();
	void UpdatePosBird();
	void UpdatePosDino();
	void UpdatePosPeople(char);
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