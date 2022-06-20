#include "D3DHelper.h"

D3DHelper::D3DHelper()
{
	m_pD3D = 0;
	m_pDevice = 0;
}

// 初始化D3D
bool D3DHelper::InitD3D(HWND hWnd)
{
	// 创建D3D对象，并获取其指针 周宇哲 2021.8.19
	m_pD3D = ::Direct3DCreate9(D3D_SDK_VERSION);

	// 设置设备呈现参数 周宇哲 2021.8.19
	D3DPRESENT_PARAMETERS d3dpp;
	memset(&d3dpp, 0, sizeof(d3dpp));
	d3dpp.Windowed = true; // 窗口化 周宇哲
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	// 利用D3D对象，创建设备对象 周宇哲 2021.8.19
	m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT, //默认显卡 周宇哲 2021.8.19
		D3DDEVTYPE_HAL, // HAL类型 周宇哲 2021.8.19
		hWnd,	//窗口句柄
		D3DCREATE_HARDWARE_VERTEXPROCESSING, //硬件顶点处理方式 周宇哲 2021.8.19
		&d3dpp, &m_pDevice);

	// 禁用光照，可选 周宇哲 2021.8.19
	m_pDevice->SetRenderState(D3DRS_LIGHTING, false);
	// 禁用剔除反面，可选 周宇哲 2021.8.19
	m_pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	return true;
}

// 释放D3D
bool D3DHelper::ReleaseD3D()
{
	//释放设备对象 周宇哲 2021.8.19
	m_pDevice->Release();
	//释放D3D对象 周宇哲 2021.8.19
	m_pD3D->Release();
	return true;
}

// 渲染
bool D3DHelper::Render()
{
	if (!m_pDevice)
		return true;

	//使用指定颜色清除后备缓冲区 周宇哲
	m_pDevice->Clear(
		0,		// 要清除的矩形个数
		NULL,	// 要清楚的矩形指针
		D3DCLEAR_TARGET,   // 要清楚的缓冲区类型
		D3DCOLOR_XRGB(0, 0, 255),  // 目标缓冲区预设值
		1.0f,  // z缓冲区预设值
		0   // stencil缓冲区预设值
	);

	// 开始渲染 周宇哲 2021.8.19
	m_pDevice->BeginScene();

	// 实际渲染 周宇哲 2021.8.19


	// 结束渲染 周宇哲 2021.8.19
	m_pDevice->EndScene();

	// 交换FrontBuffer&BackBuffer 周宇哲
	m_pDevice->Present(
		NULL,
		NULL,
		NULL,
		NULL
	);

	return true;
}
