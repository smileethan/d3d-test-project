#pragma once

#include <d3d9.h> // 主头文件
#include <d3dx9math.h> //数学相关
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

class D3DHelper
{
public:
	D3DHelper();

	// 初始化D3D
	bool InitD3D(HWND hWnd);
	// 释放D3D
	bool ReleaseD3D();

	// 渲染
	bool Render();

private:
	LPDIRECT3D9 m_pD3D;				// D3D 对象
	LPDIRECT3DDEVICE9 m_pDevice;	// Device 对象



};

