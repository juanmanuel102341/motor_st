#include"TextureManager.h"




TextureManager::TextureManager(Graphics* g) {
	graphics = g;
	
}
void TextureManager::LoadedTexture(LPCWSTR ruta, UINT _width, UINT _height) {
	if (listaTexture.size() ==0) {
		Texture* aux = new Texture;
		
	}

}