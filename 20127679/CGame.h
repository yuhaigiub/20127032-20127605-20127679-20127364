//update CGame with all the functions

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
	string RIPSpritefile;


	vector<string> birdSprite;
	vector<string> dinosaurSprite;
	vector<string> carSprite;
	vector<string> tankSprite;
	vector<string> peopleSprite;
	vector<string> RIPSprite;

	vector<string> lightSprite; 

	CLight tankLight; 
	CLight carLight; 

public:
	void SET_IS_RUNNING(bool state) { this->IS_RUNNING = state; }
	bool GET_IS_RUNNING() { return this->IS_RUNNING; }
	void SET_IS_PAUSING(bool state) { this->IS_PAUSING = state; }
	bool GET_IS_PAUSING() { return this->IS_PAUSING; }

	bool IS_FINISH();


	CGame(int width, int height, bool musicState); //initialize variables for the game
	~CGame();

	void InitializePosition(int&);
	void UpdatePosTank();
	void UpdatePosCar();
	void UpdatePosBird();
	void UpdatePosDino();
	void UpdatePosPeople(char);
	void UpdateDurationCount();

	//Draw
	void drawTitle();
	void RIP();
	void LoadingScreen(string message = "");
	void DrawBorder();

	//Game Settings
	void Setting();
	void StartMenu();
	void EndMenu();

	void StartGame();

	//
	void Clean();
	void GetInput();
	void Update();
	void Draw(); // main draw function


	bool CheckCollision();
	//
	void save_game(string name);
	bool load_game(string name);
};
