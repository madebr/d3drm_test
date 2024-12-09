// Helper.h : Helper functions for DirectMusic
//
// Copyright (c) 1998-1999 Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------

#ifndef _DMUSHELPER_H
#define _DMUSHELPER_H

#include <dmusici.h>

IDirectMusicGraph*			CreateGraph(void);
IDirectMusicLoader*			CreateLoader(void);
IDirectMusicPerformance*	CreatePerformance(void);
IDirectMusicComposer*		CreateComposer(void);
IDirectMusicSegment*		CreateSegmentFromFile(IDirectMusicLoader*, const WCHAR*);
IDirectMusicSegment*		CreateSegmentFromTemplate(IDirectMusicLoader*,
													  IDirectMusicSegment*,
													  IDirectMusicComposer*,
													  const WCHAR* wszStyle,
													  const WCHAR* wszChordMap);
IDirectMusicSegment*		GetMotif(IDirectMusicLoader*,
									 const WCHAR* wszStyle,
									 const WCHAR* wszMotif);

#define RELEASE(x) if(x) x->Release();

#endif // _DMUSHELPER_H



