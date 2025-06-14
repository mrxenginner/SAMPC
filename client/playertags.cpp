//
// Version: $Id: newplayertags.cpp,v 1.12 2006/05/07 15:38:35 kyeman Exp $
//

#include "main.h"

extern D3DXMATRIX matView, matProj;

CPlayerTags::CPlayerTags(IDirect3DDevice9* pDevice)
{
	/*m_pDevice = pDevice;
	m_pSprite = NULL;
	m_pStateBlock = NULL;

	D3DXCreateSprite(pDevice, &m_pSprite);*/
}

CPlayerTags::~CPlayerTags()
{

}

void CPlayerTags::LabelBegin()
{
	/*if (m_pSprite)
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);*/
}

void CPlayerTags::LabelEnd()
{
	/*if (m_pSprite)
		m_pSprite->End();*/
}

void CPlayerTags::DrawLabel(D3DXVECTOR3 PlayerPos, char* pNameText, DWORD dwColor, float fDistanceFromLocalPlayer, bool bNameTagStatus)
{
	/*D3DXVECTOR3 TagPos = PlayerPos;
	TagPos.x += 0.2f + (fDistanceFromLocalPlayer * 0.0475f);

	D3DVIEWPORT9 Viewport;
	m_pDevice->GetViewport(&Viewport);

	D3DXVECTOR3 Out;
	D3DXMATRIX matIdent;
	D3DXMatrixIdentity(&matIdent);
	D3DXVec3Project(&Out, &TagPos, &Viewport, &matProj, &matView, &matIdent);

	if (Out.z > 1.0f)
		return;

	RECT rect = {(int)Out.x, (int)Out.y, (int)Out.x+1, (int)Out.y+1};
	SIZE size;
	pDefaultFont->MeasureSmallerText(&size, pNameText, DT_LEFT);
	rect.left -= size.cx / 2;
	rect.top += 17;

	pDefaultFont->RenderSmallerText(m_pSprite,pNameText,rect,DT_NOCLIP,dwColor,true);

	if (bNameTagStatus && pDeathWindow)
	{
		if (pDeathWindow->IsAuxFontInited())
			pDeathWindow->CreateAuxiliaryFont();

		ID3DXFont* m_pFont = pDeathWindow->GetAuxFont();
		ID3DXFont* m_pBoxFont = pDeathWindow->GetAuxBoxFont();
		if (m_pFont && m_pBoxFont)
		{
			RECT rectSize;
			m_pBoxFont->DrawTextA(0,"C",1,&rectSize,DT_CENTER|DT_VCENTER|DT_NOCLIP|DT_CALCRECT,0);

		}
	}*/
}

void CPlayerTags::Begin_Bars()
{
	/*if (m_pSprite)
		m_pSprite->OnResetDevice();
	m_pStateBlock;
	if (m_pSprite)
		m_pSprite->Begin(D3DXSPRITE_DONOTSAVESTATE);

	m_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	m_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	m_pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	m_pDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG2);
	m_pDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	m_pDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);

	m_pDevice->SetVertexShader(NULL);
	m_pDevice->SetPixelShader(NULL);

	m_pDevice->SetRenderState(D3DRS_ZENABLE, 0);*/
}

void CPlayerTags::End_Bars()
{
	/*if (m_pSprite)
		m_pSprite->End();

	if (m_pStateBlock)
		m_pStateBlock->Apply();*/
}

void CPlayerTags::DeleteDeviceObjects()
{
	/*SAFE_RELEASE(m_pStateBlock);

	if (m_pSprite)
		m_pSprite->OnLostDevice();*/
}

void CPlayerTags::RestoreDeviceObjects()
{
	/*if (m_pSprite)
		m_pSprite->OnResetDevice();

	if(!m_pStateBlock)
		m_pDevice->CreateStateBlock(D3DSBT_ALL, &m_pStateBlock);*/
}
