#include"Entity2d.h"
//posicion//rotacion//escala

Entity2d::Entity2d() {
	OutputDebugString(TEXT("entity2d objeto"));
	x = 0;
	y = 0;
}
void Entity2d::Draw() {
	
	
	//new_graphics->Draw();
}
void Entity2d::Initialize(Graphics* g) {
	OutputDebugString(TEXT("entity2d graphics"));
	new_graphics = g;
}
void Entity2d::LoadEntity(){}

void Entity2d::SetPosition(float posx, float posy) {

}
void Entity2d::Initialize(Graphics* n_graphics, LPDIRECT3DDEVICE9 dev, LPCWSTR ruta, UINT _width, UINT _height) {
}
void Entity2d::Update() {
	
}



