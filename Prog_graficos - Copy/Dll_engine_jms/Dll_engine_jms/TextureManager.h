#ifndef TEXTURE_MANAGER_H

#define TEXTURE_MANAGER_H
#include"EngineApi.h"
#include<d3dx9.h>
#include<cstring>
#include<list> 
#include"Texture.h"
#include"Graphics.h"
using namespace std;
class ENGINE_API TextureManager
{
public:
	Texture* aux;
	Graphics* graphics;
	list<Texture*>listaTexture;
	TextureManager( Graphics* g);
//	~TextureManager();
	void LoadedTexture(LPCWSTR ruta, UINT _width, UINT _height);
	void DrawTexture();


private:

};



#endif // !TEXTURE_MANAGER_H

