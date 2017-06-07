#ifndef TEXTURE_H
#define TEXTURE_H
#include"EngineApi.h"
#include<d3dx9.h>
#include<cstring>
#include"Graphics.h"
#include"CustomVertexSprite.h"
class ENGINE_API Texture
{
	
public:
	
	CustomVertexSprite* csprite;
	int contadorTextura;
	LPCWSTR fileName;
	Graphics* graphics;
	void LoadTexture(LPCWSTR ruta, UINT _width, UINT _height);
	Texture(Graphics*_graphics);
	void Draw();
	//~Texture();

private:

};

#endif // !TEXTURE_H

