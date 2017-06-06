#include"Graphics.h"
//#include"../"
void Graphics::Draw(CustomVertex_01* _c_vertex) {
	//OutputDebugString(TEXT("DRAW GRAPHICS"));
	VOID* punterosVacios;
	HRESULT hr;
	hr = buffer_vertex_triangle->Lock(0, 0, (VOID**)&punterosVacios, 0);
		
	memcpy(punterosVacios,_c_vertex->cv2, sizeof(_c_vertex->cv2));
	
	hr=buffer_vertex_triangle->Unlock();
	dispositivo->SetStreamSource(0, buffer_vertex_triangle, 0, sizeof(Custom_vertex));
	dispositivo->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE);
	dispositivo->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
	//dispositivo->SetStreamSource(0, buffer_vertex_square, 0, sizeof(CustomVertex));
	//dispositivo->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE);
	//dispositivo->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, cantidadVertices / 2);
	//dibujo escena
}

void Graphics::DrawTexture(IDirect3DSurface9* surface_sprite, CustomVertexSprite*_customVertexSprite) {
	dispositivo->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbufer);
//	OutputDebugString(TEXT("DRAW de sprite GRAPHICS"));
	dispositivo->StretchRect(surface_sprite,NULL,backbufer,&_customVertexSprite->cs.destino,D3DTEXF_NONE);
		

}
void Graphics::Begin() {
	dispositivo->BeginScene();
}
void Graphics::End() {
	dispositivo->EndScene();
}
void Graphics::Clear() {
	dispositivo->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 0, 0), 1.0f, 0);
}

void Graphics::Present() {
	if (NULL == dispositivo)
		return;

	dispositivo->Present(NULL, NULL, NULL, NULL);
}
bool Graphics::Shutdown() {
	return true;
}

bool Graphics::InitDirect3D(void) {
	OutputDebugString(TEXT("inicio direct x device objeto"));
	pD3D = NULL;
	dispositivo = NULL;
	//objeto dtx;
	if (NULL == (pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return false;
	}
	//parametros objeto direct x

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = nuevaVentana->ancho;
	d3dpp.BackBufferHeight = nuevaVentana->alto;
	d3dpp.hDeviceWindow = nuevaVentana->hWnd;

	//creamos device

	if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, nuevaVentana->hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &dispositivo))) {
		return false;
	}
	return true;
	
}

bool Graphics::Initialize(Ventana* _ventana) {
	//aca empieza //viene de game
	nuevaVentana = _ventana;

	if (!InitDirect3D()) {
		return false;
	}
	
//	newEntity = new Entity2d();
	//TakeVertices();
	//if (!) {
		//return false;
	//}
	SetupVertexBuffer();
	
		
	return true;
	
		
}

HRESULT Graphics::SetupVertexBuffer() {
	HRESULT hr;
	OutputDebugString(TEXT("vertex buffer"));
	buffer_vertex_triangle = NULL;
	hr = dispositivo->CreateVertexBuffer(VB_SIZE * sizeof(Custom_vertex), 0, D3DFVF_XYZ | D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &buffer_vertex_triangle, NULL);
	//chequeo
	if (FAILED(hr)) {
		return NULL;
	}
	//hr = NULL;
	//hr = dispositivo->CreateVertexBuffer(VB_SIZE * sizeof(Custom_vertex), 0, D3DFVF_XYZ | D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &buffer_vertex_square, NULL);

	//chequeo
//	if (FAILED(hr)) {
	//	return NULL;
	//}
	return S_OK;
		//COPIA VERTEX TRIANGLE
}


D3DXMATRIX Graphics::MatrizTraslacion(float _x, float _y) {
	D3DXMATRIX matTraslacion;
	D3DXMatrixTranslation(&matTraslacion, _x, _y, 0.0f);
	return matTraslacion;
}
D3DXMATRIX Graphics::MatrizRotacion(float _angle) {
	D3DXMATRIX matRotacion;
	D3DXMatrixRotationZ(&matRotacion, _angle);
	return matRotacion;
}
D3DXMATRIX Graphics::MatrizScala(float _x, float _y) {
	D3DXMATRIX matScale;
	D3DXMatrixScaling(&matScale, _x, _y, 0.0f);
	return matScale;
}


bool Graphics::SetupEscene() {
	
	
	D3DVIEWPORT9 vp{ 0, 0, nuevaVentana->ancho, nuevaVentana->alto, 0, 1 };
	
	dispositivo->SetViewport(&vp);
	//dispositivo->GetViewport(_viewport);
	
	D3DXMATRIX d3dmat;
	D3DXMATRIX matTrans;
	D3DXMatrixIdentity(&d3dmat);
	

	D3DXMatrixTranslation(&matTrans, 0.0f, 0.0f, 0.0f);
	D3DXMatrixMultiply(&d3dmat, &matTrans, &d3dmat);
	dispositivo->SetTransform(D3DTS_WORLD,&d3dmat);
	

	D3DXMATRIX mView;
	D3DXVECTOR3 eyePos(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 lookPos(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 upVec(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&mView, &eyePos, &lookPos, &upVec);
	dispositivo->SetTransform(D3DTS_VIEW,&mView);

	D3DXMATRIX mProjectionMatrix;
	float fAspectRatio = (float) vp.Width/ vp.Height;
	D3DXMatrixOrthoLH(&mProjectionMatrix, (float) vp.Width, (float) vp.Height, -25.0f, 25.0f);
	 dispositivo->SetTransform(D3DTS_PROJECTION, &mProjectionMatrix);

	 dispositivo->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // D3DCULL_CCW
																// Deshabilito los speculars
	 dispositivo->SetRenderState(D3DRS_SPECULARENABLE, FALSE);
	 // Deshabilito el stencil
	 dispositivo->SetRenderState(D3DRS_STENCILENABLE, FALSE);


	 dispositivo->SetRenderState(D3DRS_LIGHTING, FALSE);
	
	return true;
}
void Graphics::SetPrimitivas() {



}


void Graphics::CleanUp(void) {
      if (dispositivo != NULL){
		dispositivo->Release();
		}
	

	if (pD3D != NULL) {
		pD3D->Release();
	}
}
Graphics::Graphics() {
	


}