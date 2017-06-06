#include"CustomVertexSprite.h"




CustomVertexSprite::CustomVertexSprite(UINT _width, UINT _height) {
	cs.destino.left = 0;
	cs.destino.top = 0;
	cs.destino.right = cs.destino.left + _width;
	cs.destino.bottom = cs.destino.top + _height;

}
