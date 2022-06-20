#pragma once

#include <d3d9.h> // ��ͷ�ļ�
#include <d3dx9math.h> //��ѧ���
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

class D3DHelper
{
public:
	D3DHelper();

	// ��ʼ��D3D
	bool InitD3D(HWND hWnd);
	// �ͷ�D3D
	bool ReleaseD3D();

	// ��Ⱦ
	bool Render();

private:
	LPDIRECT3D9 m_pD3D;				// D3D ����
	LPDIRECT3DDEVICE9 m_pDevice;	// Device ����



};

