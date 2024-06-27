#ifndef _DD_H_
#define _DD_H_

#include <ddraw.h>

extern int DDInit(HWND hWnd);

extern void DDDone(void);

extern int DDCreateSurfaces(int bFullScreen);

//extern void DDCheckSurfaces(void);

extern void DDHeartBeat(void);

#endif
