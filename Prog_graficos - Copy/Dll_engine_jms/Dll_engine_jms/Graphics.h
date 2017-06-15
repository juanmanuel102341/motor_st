#ifndef GRAPHICS_H
#define GRAPHICS_H

#include"EngineApi.h"

#include"Ventana.h"
#include<d3d9.h>
#include<d3dx9.h>
#include"Header_1.h"


#include"CustomVertexSprite.h"
//#include"Shape.h"
//#include"Sprite.h"
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")

#include<string>
static const int VB_SIZE = 50;
#include"VertexBufferManager.h"
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)
enum Primitivas {
	
	D3DPT_POINTLIST_jms, D3DPT_LINELIST_jms, D3DPT_LINESTRIP_jms, D3DPT_TRIANGLELIST_jms, D3DPT_TRIANGLESTRIP_jms
};


struct Point {
	float ptox, ptoy;

};

struct Custom_vertex {
	float x, y, z;
	DWORD color;

};
 class ENGINE_API Graphics
{
public:
		LPDIRECT3DDEVICE9 dispositivo;//device
		IDirect3DSurface9* surface_sprite;
		VertexBufferManager<Custom_vertex, D3DFVF_CUSTOMVERTEX>* vertexManager;
	//CustomVertex coleccionVertices_triangles_g[20];
	Graphics();
	int n[3];
		bool Initialize(Ventana* _objVentana);
		bool Shutdown();
		void Clear();
		void Draw(Custom_vertex* c_vertex);
		void DrawTexture(CustomVertexSprite*_customVertexSorite);//sobrecarga metodo
		void Begin();
		void End();
		void Present();//manda a la pantalla lo q dibujas
		void LoadTexture(LPCWSTR ruta, UINT _width, UINT _height);
		bool SetupEscene();
		D3DXMATRIX LoadIdentity();
		void SetPosition(float x, float y);
		void SetRotation(float angle);
		void SetScale(float _scale_x, float _scale_y);
		//void SetScale();
		//	~Graphics();
	
	
private:
	
	LPDIRECT3D9 pD3D;//objeto

	IDirect3DSurface9*backbufer;
	Ventana* nuevaVentana;
	IDirect3DVertexBuffer9*buffer_vertex_triangle;
	IDirect3DVertexBuffer9*buffer_vertex_square;
	
	//IDirect3DVertexBuffer9*bufferVertexShape;
	int startIndex_triangle = 0;
	int startIndex_square = 0;
	
	D3DXMATRIX MatrizTraslacion(float x, float y);
	D3DXMATRIX MatrizRotacion(float angle);
	D3DXMATRIX MatrizScala(float x, float y);
	HRESULT SetupVertexBuffer();

	
	bool InitDirect3D(void);

	void CleanUp(void);

 
 };



#endif // !GRAPHICS_H
