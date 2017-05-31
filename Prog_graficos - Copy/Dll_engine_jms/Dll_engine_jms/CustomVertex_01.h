#ifndef CUSTOM_VERTEX_H
#include"EngineApi.h"
#include<d3dx9.h>
#define CUSTOM_VERTEX_H
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)
struct Custom_vertex {
	float x, y, z;
	DWORD color;

};
class ENGINE_API CustomVertex_01
{
public:
	CustomVertex_01();
	

	Custom_vertex cv[3] =
	{ 
	{ 0.0f,0.0f,0.0f,D3DCOLOR_XRGB(0, 0, 255), },
	{-100.0f,0.0f,0.0f, D3DCOLOR_XRGB(0, 0, 255), },
	{-50.0f,100.0f,0.0f, D3DCOLOR_XRGB(0, 0, 255), },

	};
	Custom_vertex cv2[3];
//	~CustomVertex();
	//
private:


};
#endif // !CUSTOM_VERTEX_H

