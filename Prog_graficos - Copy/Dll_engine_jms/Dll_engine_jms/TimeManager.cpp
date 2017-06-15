
#include"TimeManager.h"

void TimeManager::StartCounter(){
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&timeFrecuency))
	

	pcfrec = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&timeLastFrame);
	counterStart = li.QuadPart;
//	OutputDebugString(TEXT("entity2d graphics"));
}
void TimeManager::NewFrame() {
	LARGE_INTEGER thisTime;
	QueryPerformanceCounter(&thisTime);
	LARGE_INTEGER delta;
	delta.QuadPart = thisTime.QuadPart - timeLastFrame.QuadPart;
	deltaTime = ((double)delta.QuadPart) / timeFrecuency.QuadPart;
	timeLastFrame.QuadPart = thisTime.QuadPart;
	
}
double TimeManager::TimeLastFrame() {
	return deltaTime;
}
TimeManager::TimeManager() {
	//StartCounter();
	Sleep(1000);

}