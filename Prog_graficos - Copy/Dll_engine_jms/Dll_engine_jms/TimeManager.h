#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H
#include"EngineApi.h"
#include <windows.h>

class ENGINE_API TimeManager
{
public:
	double pcfrec=0.0f;
	int counterStart=0.0f;
	double deltaTime;
	LARGE_INTEGER timeFrecuency;
	LARGE_INTEGER timeLastFrame;
	LARGE_INTEGER deltaLastFrame;


	TimeManager();
//	~TimeManager();
	void StartCounter();
	double TimeLastFrame();
	void NewFrame();
private:

};


#endif // !TIME_MANAGER_H

