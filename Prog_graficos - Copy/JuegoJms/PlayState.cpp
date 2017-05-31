#include"PlayState.h"



bool PlayState::OnInitialize() {
	OutputDebugString(TEXT("initialize playstate"));
	main_entity2d = new Shape;
	main_entity2d->Initialize(nuevoGraphics);
	
	return true;
}
bool PlayState::OnLoop() {
	return true;
}
bool PlayState::OnShutDown() {
	return true;
}

void PlayState::OnDraw() {
	//OutputDebugString(TEXT("DRAW PLAYSTATE"));
	main_entity2d->Draw();

}
PlayState::PlayState() {

	
}
