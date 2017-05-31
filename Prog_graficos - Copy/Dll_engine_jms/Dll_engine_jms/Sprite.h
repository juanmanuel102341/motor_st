#ifndef SPRITE_H

#define SPRITE_H

#include"EngineApi.h"
#include"Entity2d.h"
#include<cstring>
class ENGINE_API Sprite:public Entity2d
{

public:
	//LPCWSTR a = L"TestWindow";
	//D3DXIMAGE_INFO infoImage;
	IDirect3DSurface9* surface_sprite;
	IDirect3DTexture9* texture;
	Sprites sprite;
	
	Sprite();
	IDirect3DSurface9* CreateSurface(LPCWSTR ruta,UINT width,UINT height);
//	bool SetSpriteValues();
	//~Sprite();
	void CreacionTexture(LPCWSTR r, UINT width,UINT height);
	void GetDevice(LPDIRECT3DDEVICE9 _dev);
	wstring ChangeString(const std::string& s);
	virtual void Draw();
private:
	
	LPDIRECT3DDEVICE9 _dispositivo; 
};


#endif // !SPRITE_H

