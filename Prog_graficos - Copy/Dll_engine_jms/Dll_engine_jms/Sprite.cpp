#include"Sprite.h"
//#include"../resources"

void Sprite::GetDevice(LPDIRECT3DDEVICE9 _dev) {

	_dispositivo = _dev;
}

IDirect3DSurface9* Sprite::CreateSurface(LPCWSTR ruta,UINT _width,UINT _height) {
	IDirect3DSurface9* surface=NULL;
	HRESULT hr=NULL;
	hr=_dispositivo->CreateOffscreenPlainSurface(_width, _height, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &surface, NULL);
	if (FAILED(hr)) {
		OutputDebugString(TEXT("surface no cargada"));
		return NULL;
	}

	hr = NULL;
	hr=D3DXLoadSurfaceFromFile(surface, NULL, NULL,ruta, NULL, D3DX_DEFAULT, 0, NULL);
	if (FAILED(hr)) {
		//MessageBox(NULL,ChangeString("lalllaa").c_str(), NULL, NULL);
		OutputDebugString(TEXT("imagen no cargada"));

		return NULL;
	}
	return surface;
}
void Sprite::CreacionTexture(LPCWSTR r,UINT _width,UINT __height) {
	HRESULT hr = NULL;
	hr=_dispositivo->CreateTexture(_width, __height, 1, D3DUSAGE_DYNAMIC, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &texture,NULL);
	if (FAILED(hr)) {
		OutputDebugString(TEXT("texture no generada"));
	}
	hr = NULL;
	hr=D3DXCreateTextureFromFile(_dispositivo, r, &texture);
	if (FAILED(hr)) {
		OutputDebugString(TEXT("texture no cargada"));
	}
}

wstring Sprite::ChangeString(const std::string& s) {
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;

}
void Sprite::Draw() {}



Sprite::Sprite() {

}