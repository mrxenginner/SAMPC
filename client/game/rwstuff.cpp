
#include "../main.h"
#include "rwstuff.h"

#define F(eu10,usa10) \
	(iGtaVersion != GTASA_VERSION_USA10) ? (eu10) : (usa10)

// Unused, also same as what already had in main.cpp
/*void RwRenderStateSet(int iState, void* pValue)
{
	_asm mov edx, 0xC97B24
	_asm mov eax, [edx]
	_asm push pValue
	_asm push iState
	_asm call [eax+32]
	_asm pop eax
	_asm pop eax
}*/

int RpClumpGetNumAtomics(RpClump* pClump)
{
	int iRetVal = 0;

	_asm push pClump
	_asm mov edx, 0x7498E0
	_asm call edx
	_asm pop edx
	_asm mov iRetVal, eax

	return iRetVal;
}

RwFrame* RwFrameForAllObjects(RwFrame* pFrame, RwObjectCallBack Callback, void* pData)
{
	DWORD dwFunc = F(0x7F1240, 0x7F1200);
	RwFrame* pRetVal = NULL;

	_asm push pData
	_asm push Callback
	_asm push pFrame
	_asm mov eax, dwFunc
	_asm call eax
	_asm mov pRetVal, eax
	_asm pop eax
	_asm pop eax
	_asm pop eax

	return pRetVal;
}

RwRaster* RwRasterCreate(int iWidth, int iHeight, int iDepth, int iFlags)
{
	DWORD dwFunc = F(0x7FB270, 0x7FB230);
	RwRaster* pRetVal = NULL;

	_asm push iFlags
	_asm push iDepth
	_asm push iHeight
	_asm push iWidth
	_asm mov edx, dwFunc
	_asm call edx
	_asm mov pRetVal, eax
	_asm pop edx
	_asm pop edx
	_asm pop edx
	_asm pop edx

	return pRetVal;
}

RwTexture* RwTextureCreate(RwRaster* pRaster)
{
	DWORD dwFunc = F(0x7F3800, 0x7F37C0);
	RwTexture* pRetVal = NULL;

	_asm push pRaster
	_asm mov edx, dwFunc
	_asm call edx
	_asm mov pRetVal, eax
	_asm pop edx

	return pRetVal;
}


RwFrame* RwFrameCreate()
{
	DWORD dwFunc = F(0x7F0450, 0x7F0410);
	RwFrame* pRetVal = NULL;

	_asm mov edx, dwFunc
	_asm call edx
	_asm mov pRetVal, eax

	return pRetVal;
}

void RwFrameDestroy(RwFrame* pFrame)
{
	DWORD dwFunc = F(0x7F05E0, 0x7F05A0);

	_asm push pFrame
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
}

void RpAtomicDestroy(RpAtomic* pAtomic)
{
	DWORD dwFunc = F(0x749E10, 0x749DC0);

	_asm push pAtomic
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
}

RwCamera* RwCameraCreate()
{
	DWORD dwFunc = F(0x7EE530, 0x7EE4F0);
	RwCamera* pRetVal = NULL;

	_asm mov edx, dwFunc
	_asm call edx
	_asm mov pRetVal, eax

	return pRetVal;
}

void RpWorldAddCamera(RwCamera* pCamera)
{
	RpWorld* pGtaWorld = (RpWorld*)0xC17038;

	if (pGtaWorld)
	{
		DWORD dwFunc = F(0x750F70, 0x750F20);

		_asm push pCamera
		_asm push pGtaWorld
		_asm mov edx, dwFunc
		_asm call edx
		_asm pop edx
		_asm pop edx
	}
}

void RwCameraClear(RwCamera* pCamera, RwRGBA* pColor, int iMode)
{
	DWORD dwFunc = F(0x7EE380, 0x7EE340);

	_asm push iMode
	_asm push pColor
	_asm push pCamera
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
	_asm pop edx
	_asm pop edx
}

RwCamera* RwCameraBeginUpdate(RwCamera* pCamera)
{
	DWORD dwFunc = F(0x7EE1D0, 0x7EE190);

	_asm push pCamera
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
}

void RwCameraEndUpdate(RwCamera* pCamera)
{
	DWORD dwFunc = F(0x7EE1C0, 0x7EE180);

	_asm push pCamera
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
}

void rwObjectHasFrameSetFrame(void* pObject, RwFrame* pFrame)
{
	DWORD dwFunc = F(0x804F30, 0x804EF0);

	_asm push pFrame
	_asm push pObject
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
	_asm pop edx
}

void RpClumpRender(RpClump* pClump)
{
	DWORD dwFunc = F(0x749B70, 0x749B20);

	_asm push pClump
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
}

void RwCameraSetClipPlane(RwCamera* pCamera, float fFarClip, float fNearClip)
{
	DWORD dwFarFunc, dwNearFunc;

	if (iGtaVersion == GTASA_VERSION_USA10)
	{
		dwFarFunc = 0x7EE2A0;
		dwNearFunc = 0x7EE1D0;
	}
	else
	{
		dwFarFunc = 0x7EE2E0;
		dwNearFunc = 0x7EE210;
	}

	_asm push fFarClip
	_asm push pCamera
	_asm mov edx, dwFarFunc
	_asm call edx
	_asm pop edx
	_asm pop edx

	_asm push fNearClip
	_asm push pCamera
	_asm mov edx, dwNearFunc
	_asm call edx
	_asm pop edx
	_asm pop edx
}

void RwCameraSetViewWindow(RwCamera* pCamera, RwV2D* pViewPoint)
{
	DWORD dwFunc = F(0x7EE450, 0x7EE410);

	_asm push pViewPoint
	_asm push pCamera
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
	_asm pop edx
}

RpLight* RpLightCreate(int iType)
{
	DWORD dwFunc = F(0x752160, 0x752110);
	RpLight* pRetVal = NULL;

	_asm push iType
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
	_asm mov pRetVal, eax

	return pRetVal;
}

void RpLightSetColor(RpLight* pLight, RwRGBAReal* pColor)
{
	DWORD dwFunc = F(0x751AE0, 0x751A90);

	_asm push pColor
	_asm push pLight
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
	_asm pop edx
}

void RpWorldAddLight(RpLight* pLight)
{
	RpWorld* pGtaWorld = (RpWorld*)0xC17038;

	if (pGtaWorld)
	{
		DWORD dwFunc = F(0x751960, 0x751910);

		_asm push pLight
		_asm push pGtaWorld
		_asm mov edx, dwFunc
		_asm call edx
		_asm pop edx
		_asm pop edx
	}
}

void RpWorldRemoveLight(RpLight* pLight)
{
	RpWorld* pGtaWorld = (RpWorld*)0xC17038;

	if (pGtaWorld)
	{
		DWORD dwFunc = F(0x7519B0, 0x751960);

		_asm push pLight
		_asm push pGtaWorld
		_asm mov edx, dwFunc
		_asm call edx
		_asm pop edx
		_asm pop edx
	}
}

int RpClumpDestroy(RpClump* pClump)
{
	DWORD dwFunc = F(0x74A360, 0x74A310);
	int iRetVal = 0;

	_asm push pClump
	_asm mov eax, dwFunc
	_asm call eax
	_asm mov iRetVal, eax
	_asm pop eax

	return iRetVal;
}

void RwCameraSetProjection(RwCamera* pCamera, int iProjection)
{
	DWORD dwFunc = F(0x7EE3E0, 0x7EE3A0);

	_asm push iProjection
	_asm push pCamera
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
	_asm pop edx
}

void RwFrameTranslate(RwFrame* pFrame, RwV3D* pV, int iCombine)
{
	DWORD dwFunc = F(0x7F0E70, 0x7F0E30);

	_asm push iCombine
	_asm push pV
	_asm push pFrame
	_asm mov edx, dwFunc
	_asm call edx
	_asm pop edx
	_asm pop edx
	_asm pop edx
}

RwFrame* RwFrameRotate(RwFrame* pFrame, RwV3D* pAxis, float fAngle, int iCombine)
{
	// TODO
	return NULL;
}

void RpAnimBlendClumpUpdateAnimations(RpClump* pClump, float fTime, int bRender)
{
	_asm push bRender
	_asm push fTime
	_asm push pClump
	_asm mov edx, 0x4D34F0
	_asm call edx
	_asm pop edx
	_asm pop edx
	_asm pop edx
}

RwStream* RwStreamOpen(int iType, int iAccess, void* pData)
{
	DWORD dwFunc = F(0x7ECF30, 0x7ECEF0);
	RwStream* pRetVal = NULL;

	_asm push pData
	_asm push iAccess
	_asm push iType
	_asm mov eax, dwFunc;
	_asm call eax
	_asm mov pRetVal, eax
	_asm pop eax
	_asm pop eax
	_asm pop eax

	return pRetVal;
}

int RwStreamClose(RwStream* pStream, void* pData)
{
	DWORD dwFunc = F(0x7ECE60, 0x7ECE20);
	int iRetVal = 0;

	_asm push pData
	_asm push pStream
	_asm mov eax, dwFunc;
	_asm call eax
	_asm mov iRetVal, eax
	_asm pop eax
	_asm pop eax

	return iRetVal;
}

int RwStreamRead(RwStream* pStream, void* pBuffer, int iLength)
{
	DWORD dwFunc = F(0x7ECA10, 0x7EC9D0);
	int iRetVal = 0;

	_asm push iLength
	_asm push pBuffer
	_asm push pStream
	_asm mov eax, dwFunc;
	_asm call eax
	_asm mov iRetVal, eax
	_asm pop eax
	_asm pop eax
	_asm pop eax

	return iRetVal;
}

int RwStreamFindChunk(RwStream* pStream, int iType, int* pLength, int* pVersion)
{
	DWORD dwFunc = F(0x7ED310, 0x7ED2D0);
	int iRetVal = 0;

	_asm push pVersion
	_asm push pLength
	_asm push iType
	_asm push pStream
	_asm mov eax, dwFunc;
	_asm call eax
	_asm mov iRetVal, eax
	_asm pop eax
	_asm pop eax
	_asm pop eax
	_asm pop eax

	return iRetVal;
}

RpClump* RpClumpStreamRead(RwStream* pStream)
{
	DWORD dwFunc = F(0x74B470, 0x74B420);
	RpClump* pRetVal = NULL;

	_asm push pStream
	_asm mov eax, dwFunc;
	_asm call eax
	_asm mov pRetVal, eax
	_asm pop eax

	return pRetVal;
}

int RpClumpRegisterPlugin(unsigned int uiPluginID)
{
	DWORD dwFunc = F(0x74BE20, 0x74BDD0);
	int iRetVal = 0;

	*(DWORD*)0xC97B20 = 0;

	_asm push 0x41B1B0
	_asm push 0x41B1C0
	_asm push 0x41B1A0
	_asm push uiPluginID
	_asm push 0
	_asm mov edx, dwFunc
	_asm call edx
	_asm mov iRetVal, eax
	_asm pop edx
	_asm pop edx
	_asm pop edx
	_asm pop edx
	_asm pop edx

	*(DWORD*)0xC97B20 = 1;

	return iRetVal;
}

int RpClumpRegisterPluginStream(unsigned int uiPluginID,
	RwPluginDataChunkReadCallBack fnReadCallback)
{
	DWORD dwFunc = F(0x74BEC0, 0x74BE70);
	int iRetVal = 0;

	*(DWORD*)0xC97B20 = 0;

	_asm push 0x41B300
	_asm push 0x41B2F0
	_asm push fnReadCallback
	_asm push uiPluginID
	_asm mov edx, dwFunc
	_asm call edx
	_asm mov iRetVal, eax
	_asm pop edx
	_asm pop edx
	_asm pop edx
	_asm pop edx

	*(DWORD*)0xC97B20 = 1;

	return iRetVal;
}
