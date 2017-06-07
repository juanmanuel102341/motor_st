#include"TextureManager.h"



void TextureManager::DrawTexture(){
	
		OutputDebugString(TEXT("entrando draw tmanager"));
	
		aux->Draw();
	
}
TextureManager::TextureManager(Graphics* g) {
	graphics = g;
	
}
void TextureManager::LoadedTexture(LPCWSTR ruta, UINT _width, UINT _height) {
	//pregunta si carga
	
		 aux= new Texture(graphics);
		aux->LoadTexture(ruta, _width, _height);
		listaTexture.push_back(aux);
	

}