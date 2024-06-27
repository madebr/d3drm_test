#ifndef _DD_H_
#define _DD_H_

#include <windows.h>

extern void DDPreInit(void);

extern int DDInit(HWND hWnd);

extern void DDDone(void);

extern int DDCreateSurfaces(int bFullScreen);

extern BOOL DDLoadD3DRM(void);

extern void DDHeartBeat(void);

extern void DDEnableAnimation(BOOL pEnable);

#endif
