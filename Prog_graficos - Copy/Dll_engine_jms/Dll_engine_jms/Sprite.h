#ifndef SPRITE_H

#define SPRITE_H

#include"EngineApi.h"
#include"Entity2d.h"
#include<cstring>
#include"CustomVertexSprite.h"
#include"TextureManager.h"

class ENGINE_API Sprite:public Entity2d
{

public:
	//LPCWSTR a = L"TestWindow";
	//D3DXIMAGE_INFO infoImage;
	IDirect3DSurface9* surface_sprite;
	IDirect3DTexture9* texture;
	Sprites sprite;
	CustomVertexSprite*csprite;
	TextureManager* tm;
	Sprite();
void Draw();
//	bool SetSpriteValues();
	//~Sprite();
	//void CreacionTexture(LPCWSTR r, UINT width,UINT height);
	void GetDevice(LPDIRECT3DDEVICE9 _dev);
	//wstring ChangeString(const std::string& s);
	void Initialize(Graphics* n_graphics);
	//void Initialize(Graphics* n_graphics, LPDIRECT3DDEVICE9 dev, LPCWSTR ruta, UINT _width, UINT _height);
	void LoadTexture(LPCWSTR ruta, UINT _width, UINT _height);
private:
	
	LPDIRECT3DDEVICE9 _dispositivo; 
};


#endif // !SPRITE_H

