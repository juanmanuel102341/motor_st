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
	new_graphics->Draw(cv);

}

Shape::Shape() {
	cv = new CustomVertex_01;
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
