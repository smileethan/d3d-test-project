#include "D3DHelper.h"

D3DHelper::D3DHelper()
{
	m_pD3D = 0;
	m_pDevice = 0;
}

// ��ʼ��D3D
bool D3DHelper::InitD3D(HWND hWnd)
{
	// ����D3D���󣬲���ȡ��ָ�� ������ 2021.8.19
	m_pD3D = ::Direct3DCreate9(D3D_SDK_VERSION);

	// �����豸���ֲ��� ������ 2021.8.19
	D3DPRESENT_PARAMETERS d3dpp;
	memset(&d3dpp, 0, sizeof(d3dpp));
	d3dpp.Windowed = true; // ���ڻ� ������
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	// ����D3D���󣬴����豸���� ������ 2021.8.19
	m_pD3D->CreateDevice(
		D3DADAPTER_DEFAULT, //Ĭ���Կ� ������ 2021.8.19
		D3DDEVTYPE_HAL, // HAL���� ������ 2021.8.19
		hWnd,	//���ھ��
		D3DCREATE_HARDWARE_VERTEXPROCESSING, //Ӳ�����㴦��ʽ ������ 2021.8.19
		&d3dpp, &m_pDevice);

	// ���ù��գ���ѡ ������ 2021.8.19
	m_pDevice->SetRenderState(D3DRS_LIGHTING, false);
	// �����޳����棬��ѡ ������ 2021.8.19
	m_pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	return true;
}

// �ͷ�D3D
bool D3DHelper::ReleaseD3D()
{
	//�ͷ��豸���� ������ 2021.8.19
	m_pDevice->Release();
	//�ͷ�D3D���� ������ 2021.8.19
	m_pD3D->Release();
	return true;
}

// ��Ⱦ
bool D3DHelper::Render()
{
	if (!m_pDevice)
		return true;

	//ʹ��ָ����ɫ����󱸻����� ������
	m_pDevice->Clear(
		0,		// Ҫ����ľ��θ���
		NULL,	// Ҫ����ľ���ָ��
		D3DCLEAR_TARGET,   // Ҫ����Ļ���������
		D3DCOLOR_XRGB(0, 0, 255),  // Ŀ�껺����Ԥ��ֵ
		1.0f,  // z������Ԥ��ֵ
		0   // stencil������Ԥ��ֵ
	);

	// ��ʼ��Ⱦ ������ 2021.8.19
	m_pDevice->BeginScene();

	// ʵ����Ⱦ ������ 2021.8.19


	// ������Ⱦ ������ 2021.8.19
	m_pDevice->EndScene();

	// ����FrontBuffer&BackBuffer ������
	m_pDevice->Present(
		NULL,
		NULL,
		NULL,
		NULL
	);

	return true;
}
