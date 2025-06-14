
#pragma once

typedef struct
{
	float x;
	float y;
} RwV2D;

typedef struct
{
	float x;
	float y;
	float z;
} RwV3D;

struct RwRaster
{

};

struct RwTexture
{

};

struct RwFrame
{

};

struct RpAtomic
{

};

struct RwCamera
{

};

struct RwRGBA
{

};

struct RwStream
{

};

struct RpClump
{

};

struct RpWorld
{

};

struct RpLight
{

};

struct RwRGBAReal
{

};

struct RwObject
{

};

typedef RwObject* (*RwObjectCallBack)(RwObject* object, void* data);
typedef RwStream* (*RwPluginDataChunkReadCallBack)(RwStream* stream, int binaryLength, void* object, int offsetInObject, int sizeInObject);

//void RwRenderStateSet(int iState, void* pValue); // unused
int RpClumpGetNumAtomics(RpClump* pClump);
RwFrame* RwFrameForAllObjects(RwFrame* pFrame, RwObjectCallBack Callback, void* pData);
RwRaster* RwRasterCreate(int iWidth, int iHeight, int iDepth, int iFlags);
RwTexture* RwTextureCreate(RwRaster* pRaster);
RwFrame* RwFrameCreate();
void RwFrameDestroy(RwFrame* pFrame);
void RpAtomicDestroy(RpAtomic* pAtomic);
RwCamera* RwCameraCreate();
void RpWorldAddCamera(RwCamera* pCamera);
void RwCameraClear(RwCamera* pCamera, RwRGBA* pColor, int iMode);
RwCamera* RwCameraBeginUpdate(RwCamera* pCamera);
void RwCameraEndUpdate(RwCamera* pCamera);
void rwObjectHasFrameSetFrame(void* pObject, RwFrame* pFrame);
void RpClumpRender(RpClump* pClump);
void RwCameraSetClipPlane(RwCamera* pCamera, float fFarClip, float fNearClip);
void RwCameraSetViewWindow(RwCamera* pCamera, RwV2D* pViewPoint);
RpLight* RpLightCreate(int iType);
void RpLightSetColor(RpLight* pLight, RwRGBAReal* pColor);
void RpWorldAddLight(RpLight* pLight);
void RpWorldRemoveLight(RpLight* pLight);
int RpClumpDestroy(RpClump* pClump);
void RwCameraSetProjection(RwCamera* pCamera, int iProjection);
void RwFrameTranslate(RwFrame* pFrame, RwV3D* pV, int iCombine);
RwFrame* RwFrameRotate(RwFrame* pFrame, RwV3D* pAxis, float fAngle, int iCombine);
void RpAnimBlendClumpUpdateAnimations(RpClump* pClump, float fTime, int bRender);
RwStream* RwStreamOpen(int iType, int iAccess, void* pData);
int RwStreamClose(RwStream* pStream, void* pData);
int RwStreamRead(RwStream* pStream, void* pBuffer, int iLength);
int RwStreamFindChunk(RwStream* pStream, int iType, int* pLength, int* pVersion);
RpClump* RpClumpStreamRead(RwStream* pStream);
int RpClumpRegisterPlugin(unsigned int uiPluginID);
int RpClumpRegisterPluginStream(unsigned int uiPluginID, RwPluginDataChunkReadCallBack fnReadCallback);
