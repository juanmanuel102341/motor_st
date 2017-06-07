#include"Sprite.h"
//#include"../resources"

void Sprite::GetDevice(LPDIRECT3DDEVICE9 _dev) {

	_dispositivo = _dev;
}

void Sprite::Draw() {
	tm->DrawTexture();

	

}


void Sprite::LoadTexture(LPCWSTR ruta, UINT _width, UINT _height) {
	tm->LoadedTexture(ruta, _width, _height);

}

void Sprite::Initialize(TextureManager* _tm) {

	tm = _tm;
}

/*
void Sprite::Initialize(Graphics* g, LPDIRECT3DDEVICE9 dev, LPCWSTR ruta, UINT _width, UINT _height) {
	OutputDebugString(TEXT("GGRAFICS Sprite"));
	new_graphics = g;
	_dispositivo = dev;
	
	HRESULT hr = NULL;
	hr = _dispositivo->CreateOffscreenPlainSurface(_width, _height, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &surface_sprite, NULL);
	if (FAILED(hr)) {
		OutputDebugString(TEXT("surface no cargada"));
		//return NULL;
	}
	OutputDebugString(TEXT("surface cargada"));

	hr = NULL;
	hr = D3DXLoadSurfaceFromFile(surface_sprite, NULL, NULL, ruta, NULL, D3DX_DEFAULT, 0, NULL);
	if (FAILED(hr)) {
		//MessageBox(NULL,ChangeString("lalllaa").c_str(), NULL, NULL);
		OutputDebugString(TEXT(" imagen no cargada"));
		//	return NULL;
	}
	OutputDebugString(TEXT("imagen cargada"));
	csprite = new CustomVertexSprite(_width,_height);
}

*/
Sprite::Sprite() {
	

}