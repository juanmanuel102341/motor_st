#ifndef CUSTOM_VERTEX_SRPITE_H
#define CUSTOM_VERTEX_SRPITE_H
#include"EngineApi.h"
#include<d3dx9.h>
struct Custom_vertex_sprite {
	RECT destino;
	int x;
	int y;
};
class ENGINE_API CustomVertexSprite
{
public:
	int width;
	int height;
	CustomVertexSprite(UINT _width, UINT _height);
	//void Initialize(UINT _width, UINT _height);
	Custom_vertex_sprite cs;
	
	

	//	~CustomVertexSprite();

private:

};


#endif // !CUSTOM_VERTEX_SRPITE_H