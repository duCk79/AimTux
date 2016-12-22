#pragma once

#include "../SDK/SDK.h"
#include "../interfaces.h"
#include "../hacks.h"
#include "../atgui.h"
#include "../hooker.h"

typedef void (*FrameStageNotifyFn) (void*, int);
typedef void (*PaintTraverseFn) (void*, VPANEL, bool, bool);
typedef void (*DrawModelExecuteFn) (void*, void*, void*, const ModelRenderInfo_t&, matrix3x4_t*);
typedef bool (*CreateMoveFn) (void*, float, CUserCmd*);
typedef bool (*FireEventClientSideFn) (void*, IGameEvent*);
typedef int (*IN_KeyEventFn) (void*, int, int, const char*);
typedef void (*RenderViewFn) (void*, CViewSetup&, CViewSetup&, unsigned int, int);
typedef void (*SetKeyCodeStateFn) (void*, ButtonCode_t, bool);
typedef void (*SetMouseCodeStateFn) (void*, ButtonCode_t, MouseCodeState_t);
typedef void (*OnScreenSizeChangedFn) (void*, int, int);
typedef void (*PlaySoundFn) (void*, const char*);
typedef void (*BeginFrameFn) (void*, float);
typedef int (*PumpWindowsMessageLoopFn) (void*, void*);
typedef void (*PaintFn) (void*, PaintMode_t);
typedef void (*EmitSoundFn) (void*, IRecipientFilter&, int, int, const char*, unsigned int, const char*, float, float, int, soundlevel_t, int, int, const Vector*, const Vector*, void*, bool, float, int);

namespace Hooks
{
	void PaintTraverse(void* thisptr, VPANEL vgui_panel, bool force_repaint, bool allow_force);
	void FrameStageNotify(void* thisptr, ClientFrameStage_t stage);
	void DrawModelExecute(void* thisptr, void* context, void *state, const ModelRenderInfo_t &pInfo, matrix3x4_t *pCustomBoneToWorld);
	bool CreateMove(void* thisptr, float flInputSampleTime, CUserCmd* cmd);
	bool FireEventClientSide(void* thisptr, IGameEvent* event);
	int IN_KeyEvent(void* thisptr, int eventcode, int keynum, const char* currentbinding);
	void RenderView(void* thisptr, CViewSetup& setup, CViewSetup& hudViewSetup, unsigned int nClearFlags, int whatToDraw);
	void SetKeyCodeState(void* thisptr, ButtonCode_t code, bool bPressed);
	void SetMouseCodeState(void* thisptr, ButtonCode_t code, MouseCodeState_t state);
	void OnScreenSizeChanged(void* thisptr, int oldwidth, int oldheight);
	void PlaySound(void* thisptr, const char* filename);
	void BeginFrame(void* thisptr, float frameTime);
	int PumpWindowsMessageLoop(void* thisptr, void* unknown);
	void Paint(void* thisptr, PaintMode_t mode);
	void EmitSound(void* thisptr, IRecipientFilter& filter, int iEntIndex, int iChannel, const char* pSoundEntry, unsigned int nSoundEntryHash, const char *pSample, float flVolume, float flAttenuation, int nSeed, soundlevel_t iSoundLevel, int iFlags, int iPitch, const Vector* pOrigin, const Vector* pDirection, void* pUtlVecOrigins, bool bUpdatePositions, float soundtime, int speakerentity);
}

namespace CreateMove
{
	extern bool SendPacket;
}

namespace RenderView
{
	extern float currentFOV;
}

namespace SetKeyCodeState
{
	extern bool shouldListen;
	extern ButtonCode_t* keyOutput;
}
