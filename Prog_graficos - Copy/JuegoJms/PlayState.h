#ifndef PLAY_STATE

#define PLAY_STATE
#include"../Dll_engine_jms/Dll_engine_jms/Game.h"
#include"../Dll_engine_jms/Dll_engine_jms/Shape.h"
#include"..//Dll_engine_jms/Dll_engine_jms/Sprite.h"
class PlayState:public Game
{
	Shape* main_entity2d;
	Sprite* sprite;
public:
  PlayState();
protected:
  virtual bool OnInitialize();
 virtual bool OnLoop();
virtual bool OnShutDown();
virtual void OnDraw();
//~PlayState();
  


};



#endif // !PLAY_STATE
