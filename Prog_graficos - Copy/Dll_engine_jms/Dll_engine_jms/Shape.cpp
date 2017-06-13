#include"Shape.h"
//array verticces



void Shape::Update() {

}


void Shape::Initialize(Graphics* g) {
	OutputDebugString(TEXT("GGRAFICS SHAPE"));
	new_graphics = g;
}
void Shape::Draw() {
	
	//OutputDebugString(TEXT("draw SHAPE"));
	//Graphics::Draw(CustomVertex coleccionVercies[], int cantidadVertices, Primitivas p);
	LoadIdentity();
	//new_graphics->SetPosition(x, y);
	new_graphics->Draw(cv);

}
void Shape::SetPosition(float x, float y) {

	new_graphics->SetPosition(x, y);

}
void Shape::LoadIdentity() {
	new_graphics->LoadIdentity();
}
Shape::Shape() {
	
	cv[0].x = -25.0f;
	cv[0].y = 0.0f;
	cv[0].z = 0.0f;
	cv[0].color = D3DCOLOR_XRGB(0, 0, 255);

	cv[1].x = 0.0f;
	cv[1].y = 100.0f;
	cv[1].z = 0.0f;
	cv[1].color = D3DCOLOR_XRGB(0, 0, 255);

	cv[2].x = 25.0f;
	cv[2].y = 0.0f;
	cv[2].z = 0.0f;
	cv[2].color = D3DCOLOR_XRGB(0, 0, 255);
/*	coleccionVertices_triangles[0].x = 0.0f;
	coleccionVertices_triangles[0].y = 0.0f;
	coleccionVertices_triangles[0].z = 0.0f;

	coleccionVertices_triangles[0].color = D3DCOLOR_XRGB(0, 0, 0);

	//startIndex_triangle += 1;
	//numVertices += 1;
	coleccionVertices_triangles[1].x = -100.0f;
	coleccionVertices_triangles[1].y = 0.0f;
	coleccionVertices_triangles[1].z = 0.0f;
	coleccionVertices_triangles[1].color = D3DCOLOR_XRGB(0, 0, 0);

	//startIndex_triangle += 1;
	coleccionVertices_triangles[2].x = -50.0f;
	coleccionVertices_triangles[2].y = 100.0f;
	coleccionVertices_triangles[2].z = 0.0f;
	coleccionVertices_triangles[2].color = D3DCOLOR_XRGB(0, 0, 0);
	//startIndex_triangle += 1;
	//p = D3DPT_TRIANGLELIST;
	*/
}
