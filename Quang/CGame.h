#ifndef C_GAME_
#define C_GAME_

#include"CConsole.h"
#include"CPeople.h"
#include"CBird.h"
#include"CDinosaur.h"
#include"CCar.h"
#include"CTank.h"
#include<vector>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;

// HARD-CODED values (pls consider carefully before modifying)
#define FINISH_LINE 2
#define DEFAULT_BIRD_Y 6
#define DEFAULT_CAR_Y 10
#define DEFAULT_DINO_Y 14
#define DEFAULT_TANK_Y 22
#define DEFAULT_PEOPLE_Y 26
#define MAX_ENEMY 7

class CGame
{
private:
	int level;
	bool IS_RUNNING;
	bool IS_PAUSING;
	
	//border
	Point2D topleft;
	Point2D botright; 

	//row state 
	int birdNum, dinoNum, carNum, tankNum;
	int birdSpeed, dinoSpeed, carSpeed, tankSpeed;

	//Sounds control
	bool music_state;

	bool difficult_state;

	CPeople people;
	vector<CBird*> birds;
	vector<CDinosaur*> dinos;
	vector<CCar*> cars;
	vector<CTank*> tanks;

	string birdSpritefile;
	string dinosaurSpritefile;
	string carSpritefile;
	string tankSpritefile;
	string peopleSpritefile;
	
	vector<string> birdSprite;
	vector<string> dinosaurSprite;
	vector<string> carSprite;
	vector<string> tankSprite;
	vector<string> peopleSprite;
	vector<string> RIPSprite;
public:
	
	void SET_IS_RUNNING(bool state) { this->IS_RUNNING = state; }
	bool GET_IS_RUNNING() { return this->IS_RUNNING; }
	void SET_IS_PAUSING(bool state) { this->IS_PAUSING = state; }
	bool GET_IS_PAUSING() { return this->IS_PAUSING; }

	bool IS_FINISH();
	
	CGame(int width, int height); //initialize variables for the game
	~CGame();
	void InitializePosition(int&);
	void UpdatePosTank();
	void UpdatePosCar();
	void UpdatePosBird();
	void UpdatePosDino();
	void UpdatePosPeople(char);

	void ReadObjectSprite(string filename, vector<string>& objectSprite);
	void DrawObjectSprite(int x, int y, const vector<string>& objectSprite);
	void DeleteObjectSprite(int x, int y, const vector<string>& objectSprite);

	void DrawBorder();
	void Clean();
	void Update();
	void Draw();
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
