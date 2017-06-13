
#include"TimeManager.h"

void TimeManager::StartCounter(){
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
	

	pcfrec = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	counterStart = li.QuadPart;
//	OutputDebugString(TEXT("entity2d graphics"));
}
double TimeManager::GetCounter() {
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - counterStart) / pcfrec;

}

TimeManager::TimeManager() {
	//StartCounter();
	Sleep(1000);

}