#include"Texture.h"

void Texture::LoadTexture(LPCWSTR ruta, UINT _width, UINT _height){
	OutputDebugString(TEXT(" textura cargandose"));
	fileName = ruta;
	csprite = new CustomVertexSprite(_width, _height);
	graphics->LoadTexture(ruta, _width, _height);
}
void Texture::Draw() {
	graphics->DrawTexture(csprite);
}
Texture::Texture(Graphics* _graphics) {
	OutputDebugString(TEXT(" textura inicializada"));
	contadorTextura++;
	graphics = _graphics;

}