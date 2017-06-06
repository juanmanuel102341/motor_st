#ifndef GAME_H
#define GAME_H
#include"EngineApi.h"
#include"Graphics.h"
#include"Ventana.h"
#include"Entity2d.h"
#include<iostream>
#include"TextureManager.h"
using namespace std;


class ENGINE_API Game
{
public:
	//Entity2d* new_entity;
	Ventana* nuevaVentana;
	Graphics* nuevoGraphics;
	
	bool StartUp(HINSTANCE hInstance);
	
	
	TextureManager* tm;
	void Update();
	bool ShutDown();
	Game();
	

protected:
	 virtual bool OnInitialize();
	virtual bool OnLoop();
	virtual bool OnShutDown();
	virtual void OnDraw();
	//~Game();



};

#endif // !GAME_H

