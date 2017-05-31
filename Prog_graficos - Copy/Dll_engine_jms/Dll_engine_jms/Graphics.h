#ifndef GRAPHICS_H
#define GRAPHICS_H

#include"EngineApi.h"

#include"Ventana.h"
#include<d3d9.h>
#include<d3dx9.h>
#include"Header_1.h"

#include"CustomVertex_01.h"
//#include"Shape.h"
//#include"Sprite.h"
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")

#include<string>
static const int VB_SIZE = 50;

enum Primitivas {
	
	D3DPT_POINTLIST_jms, D3DPT_LINELIST_jms, D3DPT_LINESTRIP_jms, D3DPT_TRIANGLELIST_jms, D3DPT_TRIANGLESTRIP_jms
};


struct Point {
	float ptox, ptoy;

};

 class ENGINE_API Graphics
{
public:
	
	//CustomVertex coleccionVertices_triangles_g[20];
	Graphics();
	int n[3];
		bool Initialize(Ventana* _objVentana);
		bool Shutdown();
		void Clear();
		void Draw(CustomVertex_01* c_vertex);
		void Begin();
		void End();
		void Present();//manda a la pantalla lo q dibujas
		
		bool SetupEscene();
		
		//	~Graphics();
		
	
private:
	//CustomVertex c[3];
	LPDIRECT3D9 pD3D;//objeto
	LPDIRECT3DDEVICE9 dispositivo;//device
	IDirect3DSurface9*backbufer;
	Ventana* nuevaVentana;
	
	IDirect3DVertexBuffer9*buffer_vertex_triangle;
	IDirect3DVertexBuffer9*buffer_vertex_square;
	

	bool InitDirect3D(void);


	void CleanUp(void);

	
//	CustomVertex coleccionVertices[3];
	HRESULT SetupVertexBuffer();
	//void DrawVertexBuffer();
	
	//CustomVertex coleccionVertices_Squares_g[20];
	
	int startIndex_triangle = 0;
	int startIndex_square = 0;
	D3DXMATRIX MatrizTraslacion(float x, float y);
	D3DXMATRIX MatrizRotacion(float angle);
	D3DXMATRIX MatrizScala(float x, float y);
	void SetPrimitivas();
	
 
 };



#endif // !GRAPHICS_H
