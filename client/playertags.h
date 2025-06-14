//
// Version: $Id: newplayertags.h,v 1.6 2006/05/07 15:38:35 kyeman Exp $
//

#pragma once

class CPlayerTags
{
private:
	IDirect3DDevice9* m_pDevice;
	IDirect3DStateBlock9* m_pStateBlock;
	ID3DXSprite* m_pSprite;

public:
	CPlayerTags(IDirect3DDevice9* pDevice);
	~CPlayerTags();

	void LabelBegin();
	void DrawLabel(D3DXVECTOR3 PlayerPos, char* pNameText, DWORD dwColor, float fDistanceFromCamera, bool bNameTagStatus);
	void LabelEnd();

	void Begin_Bars();
	void DrawBars(D3DXVECTOR3 PlayerPos, float fHealth, float fArmour, float fDistanceFromCamera);
	void End_Bars();

	void DeleteDeviceObjects();
	void RestoreDeviceObjects();
};
