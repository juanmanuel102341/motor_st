#ifndef SHAPE_H

#define SHAPE_H
#include"EngineApi.h"
#include "Entity2d.h"

//vector<CustomVertex>vectorShape(3);
class ENGINE_API Shape:public Entity2d
{
public:

	int n[3];
	Custom_vertex cv[3];
//	CustomVertex coleccionVertices[3];
	 Shape();
	 Primitivas p;
	// CustomVertex coleccionVertices_triangles[3];
	  void Initialize(Graphics* n_graphics);
	  virtual void LoadIdentity();
	  virtual void SetPosition(float x, float y);
//	~ Shape();
	// void CreateTriangle(Point point_1, Point point_2, Point point_3);
	 virtual void Draw();
	void Update();
	
private:

};


#endif // !SHAPE_H

