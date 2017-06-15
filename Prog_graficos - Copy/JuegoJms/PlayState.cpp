#include"PlayState.h"



bool PlayState::OnInitialize() {
	OutputDebugString(TEXT("initialize playstate"));
	main_entity2d = new Shape;
	main_entity2d->Initialize(nuevoGraphics);

	main_entity2d_2 = new Shape;
	main_entity2d_2->Initialize(nuevoGraphics);

	sprite = new Sprite;
	sprite->Initialize( tm);
	sprite->LoadTexture(L"trooper.jpg", 299, 310);

		

//	sprite->Initialize(nuevoGraphics,nuevoGraphics->dispositivo,L"sprite3.png",59,57);

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
	main_entity2d_2->Draw();
	
	main_entity2d->SetPosition(200, 200);
	main_entity2d_2->SetPosition(0,100);
		
	sprite->Draw();

}
PlayState::PlayState() {

	
}
