//for every rotation with certain duration, update the status of car's traffic light and tank's traffic light (red/green)

void CGame::UpdateDurationCount() {
	//while (this->IS_RUNNING) {
	carLight.UpdateDurationStatus();
	tankLight.UpdateDurationStatus();
	//}
}