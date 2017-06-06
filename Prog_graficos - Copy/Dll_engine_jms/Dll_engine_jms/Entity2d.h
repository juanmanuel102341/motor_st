#ifndef ENTITY_2D_H
#define ENTITY_2D_H
#include"EngineApi.h"
#include"Entity.h"
#include<d3dx9.h>

#include<vector>
using namespace std;




struct Triangulo {
	float x, y;
//	CustomVertex vertices[3];

};
struct Cuadrado {
	float x, y;
	//CustomVertex vertices[4];
};
struct Sprites
{
	int x, y;
	RECT SourceRect;

};
//vector<CustomVertex>vectorPosicionesEntity2d(3);
class ENGINE_API Entity2d:Entity
{
public:
	
	int numVertices=0;
	Graphics* new_graphics;
//	Point point;
	
	virtual void Initialize(Graphics* n_graphics);
	virtual void Initialize(Graphics* n_graphics, LPDIRECT3DDEVICE9 dev, LPCWSTR ruta, UINT _width, UINT _height);
	Entity2d();
	virtual void Draw();

	void Update();
	
	//	virtual void Initialize(Graphics* n_graphics);
	//virtual void CreateTriangle(Point point_1, Point point_2, Point point_3);
	//virtual void TakeVertices(Point point_1, Point point_2, Point point_3);
	//virtual void CreateSquare(Point points[4]);
	//virtual void TakeVertices(p)
private:


	 int findex ;
	 int startIc=0;


	 
};


#endif // !ENTITY_2D_H

