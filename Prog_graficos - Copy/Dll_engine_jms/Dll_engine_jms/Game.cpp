#include"Game.h"


bool Game::StartUp(HINSTANCE hInstance)
{

	nuevaVentana = new Ventana;
	nuevaVentana->registerClass(hInstance);

	if (!nuevaVentana->createWindow(hInstance, L"PROYECTO", nuevaVentana->ancho,nuevaVentana->alto)) {
		return false;
	}
	else {
		
		nuevoGraphics = new Graphics;
		timeManager = new TimeManager;
		timeManager->StartCounter();
		if (!nuevoGraphics->Initialize(nuevaVentana)) {
		return false;
		}
		tm = new TextureManager(nuevoGraphics);
		
		
		return OnInitialize();
	//mensaje error
	}
}
void Game::Update() {
	static MSG	msg;			// Estructura de mensajes
	static bool	done = false;	// Si debo interrumpir el loop
	while (!done)
	{
		//timeManager->StartCounter();
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				done = true;			// ALT-F4
		}

		timeManager->NewFrame();
		nuevoGraphics->Clear();
		//nuevoGraphics->SetupEscene();
		nuevoGraphics->Begin();

		OnDraw();//PLAYSTATE //SHAPE
		// onDraw
		nuevoGraphics->End();
		nuevoGraphics->Present();
		// present

		done = !OnLoop();
	}
	

}

bool Game::ShutDown() {
	OnShutDown();
	return true;
}

bool Game::OnInitialize() {
	OutputDebugString(TEXT("initialize game"));
		
	return true;

	}
bool Game::OnLoop() {
	return true;
}
void Game::OnDraw() {

}
bool Game::OnShutDown() {
	return true;
}
Game::Game() {


}