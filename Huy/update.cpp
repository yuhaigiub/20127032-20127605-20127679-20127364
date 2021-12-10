// main update function


void CGame::Update() {
	//update traffic light
	UpdateDurationCount();

	//update enemy's position
	UpdatePosBird();
	UpdatePosDino();
	UpdatePosCar();
	UpdatePosTank();
}
