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
using namespace std;

class CGame
{
private:
	Point2D topleft;
	Point2D botright; 
	int objectsPerRow;
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
public:
	CGame(int objectsPerRow, int width, int height); //initialize variables for the game
	~CGame();
	void InitializePosition();
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

/*
save(string name) {
	//name_people.txt
	//name_bird.txt
	//open(file)
	save:
	numberofobject
	topleft.x topleft.y botright.x botright.y


	Ex:

	3
	0 0 1 1
	12 12 34 34

}

load(string name) {

	load:
	read n;
	for(i = 0; i < n; i++)
		assign object[i].topleft object[i].botright

}

*/
