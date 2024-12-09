/* Based on https://scorpioncity.com/dj3.html */

#include "dd.h"

#include <ddraw.h>

#include <stdio.h>

static LPDIRECTDRAW g_pDD;
static LPDIRECTDRAWSURFACE g_pDDS;
static LPDIRECTDRAWSURFACE g_pDDSBack;
static LPDIRECTDRAWCLIPPER g_pClipper;
static HWND g_hWnd;
static int g_bFullScreen;
static int g_iBpp;

static const char *DDErrorString(HRESULT hr) {
    switch (hr) {
    case DDERR_ALREADYINITIALIZED:           return "DDERR_ALREADYINITIALIZED";
    case DDERR_CANNOTATTACHSURFACE:          return "DDERR_CANNOTATTACHSURFACE";
    case DDERR_CANNOTDETACHSURFACE:          return "DDERR_CANNOTDETACHSURFACE";
    case DDERR_CURRENTLYNOTAVAIL:            return "DDERR_CURRENTLYNOTAVAIL";
    case DDERR_EXCEPTION:                    return "DDERR_EXCEPTION";
    case DDERR_GENERIC:                      return "DDERR_GENERIC";
    case DDERR_HEIGHTALIGN:                  return "DDERR_HEIGHTALIGN";
    case DDERR_INCOMPATIBLEPRIMARY:          return "DDERR_INCOMPATIBLEPRIMARY";
    case DDERR_INVALIDCAPS:                  return "DDERR_INVALIDCAPS";
    case DDERR_INVALIDCLIPLIST:              return "DDERR_INVALIDCLIPLIST";
    case DDERR_INVALIDMODE:                  return "DDERR_INVALIDMODE";
    case DDERR_INVALIDOBJECT:                return "DDERR_INVALIDOBJECT";
    case DDERR_INVALIDPARAMS:                return "DDERR_INVALIDPARAMS";
    case DDERR_INVALIDPIXELFORMAT:           return "DDERR_INVALIDPIXELFORMAT";
    case DDERR_INVALIDRECT:                  return "DDERR_INVALIDRECT";
    case DDERR_LOCKEDSURFACES:               return "DDERR_LOCKEDSURFACES";
    case DDERR_NO3D:                         return "DDERR_NO3D";
    case DDERR_NOALPHAHW:                    return "DDERR_NOALPHAHW";
    case DDERR_NOCLIPLIST:                   return "DDERR_NOCLIPLIST";
    case DDERR_NOCOLORCONVHW:                return "DDERR_NOCOLORCONVHW";
    case DDERR_NOCOOPERATIVELEVELSET:        return "DDERR_NOCOOPERATIVELEVELSET";
    case DDERR_NOCOLORKEY:                   return "DDERR_NOCOLORKEY";
    case DDERR_NOCOLORKEYHW:                 return "DDERR_NOCOLORKEYHW";
    case DDERR_NODIRECTDRAWSUPPORT:          return "DDERR_NODIRECTDRAWSUPPORT";
    case DDERR_NOEXCLUSIVEMODE:              return "DDERR_NOEXCLUSIVEMODE";
    case DDERR_NOFLIPHW:                     return "DDERR_NOFLIPHW";
    case DDERR_NOGDI:                        return "DDERR_NOGDI";
    case DDERR_NOMIRRORHW:                   return "DDERR_NOMIRRORHW";
    case DDERR_NOTFOUND:                     return "DDERR_NOTFOUND";
    case DDERR_NOOVERLAYHW:                  return "DDERR_NOOVERLAYHW";
    case DDERR_NORASTEROPHW:                 return "DDERR_NORASTEROPHW";
    case DDERR_NOROTATIONHW:                 return "DDERR_NOROTATIONHW";
    case DDERR_NOSTRETCHHW:                  return "DDERR_NOSTRETCHHW";
    case DDERR_NOT4BITCOLOR:                 return "DDERR_NOT4BITCOLOR";
    case DDERR_NOT4BITCOLORINDEX:            return "DDERR_NOT4BITCOLORINDEX";
    case DDERR_NOT8BITCOLOR:                 return "DDERR_NOT8BITCOLOR";
    case DDERR_NOTEXTUREHW:                  return "DDERR_NOTEXTUREHW";
    case DDERR_NOVSYNCHW:                    return "DDERR_NOVSYNCHW";
    case DDERR_NOZBUFFERHW:                  return "DDERR_NOZBUFFERHW";
    case DDERR_NOZOVERLAYHW:                 return "DDERR_NOZOVERLAYHW";
    case DDERR_OUTOFCAPS:                    return "DDERR_OUTOFCAPS";
    case DDERR_OUTOFMEMORY:                  return "DDERR_OUTOFMEMORY";
    case DDERR_OUTOFVIDEOMEMORY:             return "DDERR_OUTOFVIDEOMEMORY";
    case DDERR_OVERLAYCANTCLIP:              return "DDERR_OVERLAYCANTCLIP";
    case DDERR_OVERLAYCOLORKEYONLYONEACTIVE: return "DDERR_OVERLAYCOLORKEYONLYONEACTIVE";
    case DDERR_PALETTEBUSY:                  return "DDERR_PALETTEBUSY";
    case DDERR_COLORKEYNOTSET:               return "DDERR_COLORKEYNOTSET";
    case DDERR_SURFACEALREADYATTACHED:       return "DDERR_SURFACEALREADYATTACHED";
    case DDERR_SURFACEALREADYDEPENDENT:      return "DDERR_SURFACEALREADYDEPENDENT";
    case DDERR_SURFACEBUSY:                  return "DDERR_SURFACEBUSY";
    case DDERR_CANTLOCKSURFACE:              return "DDERR_CANTLOCKSURFACE";
    case DDERR_SURFACEISOBSCURED:            return "DDERR_SURFACEISOBSCURED";
    case DDERR_SURFACELOST:                  return "DDERR_SURFACELOST";
    case DDERR_SURFACENOTATTACHED:           return "DDERR_SURFACENOTATTACHED";
    case DDERR_TOOBIGHEIGHT:                 return "DDERR_TOOBIGHEIGHT";
    case DDERR_TOOBIGSIZE:                   return "DDERR_TOOBIGSIZE";
    case DDERR_TOOBIGWIDTH:                  return "DDERR_TOOBIGWIDTH";
    case DDERR_UNSUPPORTED:                  return "DDERR_UNSUPPORTED";
    case DDERR_UNSUPPORTEDFORMAT:            return "DDERR_UNSUPPORTEDFORMAT";
    case DDERR_UNSUPPORTEDMASK:              return "DDERR_UNSUPPORTEDMASK";
    case DDERR_VERTICALBLANKINPROGRESS:      return "DDERR_VERTICALBLANKINPROGRESS";
    case DDERR_WASSTILLDRAWING:              return "DDERR_WASSTILLDRAWING";
    case DDERR_XALIGN:                       return "DDERR_XALIGN";
    case DDERR_INVALIDDIRECTDRAWGUID:        return "DDERR_INVALIDDIRECTDRAWGUID";
    case DDERR_DIRECTDRAWALREADYCREATED:     return "DDERR_DIRECTDRAWALREADYCREATED";
    case DDERR_NODIRECTDRAWHW:               return "DDERR_NODIRECTDRAWHW";
    case DDERR_PRIMARYSURFACEALREADYEXISTS:  return "DDERR_PRIMARYSURFACEALREADYEXISTS";
    case DDERR_NOEMULATION:                  return "DDERR_NOEMULATION";
    case DDERR_REGIONTOOSMALL:               return "DDERR_REGIONTOOSMALL";
    case DDERR_CLIPPERISUSINGHWND:           return "DDERR_CLIPPERISUSINGHWND";
    case DDERR_NOCLIPPERATTACHED:            return "DDERR_NOCLIPPERATTACHED";
    case DDERR_NOHWND:                       return "DDERR_NOHWND";
    case DDERR_HWNDSUBCLASSED:               return "DDERR_HWNDSUBCLASSED";
    case DDERR_HWNDALREADYSET:               return "DDERR_HWNDALREADYSET";
    case DDERR_NOPALETTEATTACHED:            return "DDERR_NOPALETTEATTACHED";
    case DDERR_NOPALETTEHW:                  return "DDERR_NOPALETTEHW";
    case DDERR_BLTFASTCANTCLIP:              return "DDERR_BLTFASTCANTCLIP";
    case DDERR_NOBLTHW:                      return "DDERR_NOBLTHW";
    case DDERR_NODDROPSHW:                   return "DDERR_NODDROPSHW";
    case DDERR_OVERLAYNOTVISIBLE:            return "DDERR_OVERLAYNOTVISIBLE";
    case DDERR_NOOVERLAYDEST:                return "DDERR_NOOVERLAYDEST";
    case DDERR_INVALIDPOSITION:              return "DDERR_INVALIDPOSITION";
    case DDERR_NOTAOVERLAYSURFACE:           return "DDERR_NOTAOVERLAYSURFACE";
    case DDERR_EXCLUSIVEMODEALREADYSET:      return "DDERR_EXCLUSIVEMODEALREADYSET";
    case DDERR_NOTFLIPPABLE:                 return "DDERR_NOTFLIPPABLE";
    case DDERR_CANTDUPLICATE:                return "DDERR_CANTDUPLICATE";
    case DDERR_NOTLOCKED:                    return "DDERR_NOTLOCKED";
    case DDERR_CANTCREATEDC:                 return "DDERR_CANTCREATEDC";
    case DDERR_NODC:                         return "DDERR_NODC";
    case DDERR_WRONGMODE:                    return "DDERR_WRONGMODE";
    case DDERR_IMPLICITLYCREATED:            return "DDERR_IMPLICITLYCREATED";
    case DDERR_NOTPALETTIZED:                return "DDERR_NOTPALETTIZED";
    case DDERR_UNSUPPORTEDMODE:              return "DDERR_UNSUPPORTEDMODE";
    case DDERR_NOMIPMAPHW:                   return "DDERR_NOMIPMAPHW";
    case DDERR_INVALIDSURFACETYPE:           return "DDERR_INVALIDSURFACETYPE";
    case DDERR_DCALREADYCREATED:             return "DDERR_DCALREADYCREATED";
    case DDERR_CANTPAGELOCK:                 return "DDERR_CANTPAGELOCK";
    case DDERR_CANTPAGEUNLOCK:               return "DDERR_CANTPAGEUNLOCK";
    case DDERR_NOTPAGELOCKED:                return "DDERR_NOTPAGELOCKED";
    case DDERR_NOTINITIALIZED:               return "DDERR_NOTINITIALIZED";
    }
    return "Unknown Error";
}

static int DDFailedCheck(HRESULT hr, const char *szMessage) {
    if (FAILED(hr)) {
        char buf[1024];
        sprintf_s(buf, sizeof(buf), "%s (%s)\n", szMessage, DDErrorString(hr));
        fprintf(stderr, buf);
        return 1;
    }
    return 0;
}

int DDInit(HWND hWnd) {
    HRESULT hr;

    g_hWnd = hWnd;

    // Initialize DirectDraw
    hr = DirectDrawCreate(NULL, &g_pDD, NULL);
    if (DDFailedCheck(hr, "DirectDrawCreate failed")) {
        return 0;
    }

    return 1;
}

int DDCreateSurfaces(int bFullScreen) {

    /* Setting the screen mode */

    HRESULT hr; // Holds return values for DirectX function calls

    g_bFullScreen = bFullScreen;

    // If we want to be in full-screen mode
    if (g_bFullScreen) {
        // Set the "cooperative level" so we can use full-screen mode
        hr = IDirectDraw_SetCooperativeLevel(g_pDD, g_hWnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN | DDSCL_NOWINDOWCHANGES);
        if (DDFailedCheck(hr, "SetCooperativeLevel")) {
            return 0;
        }

        // Set 640x480x256 full-screen mode
        g_iBpp = 16;
        hr = IDirectDraw_SetDisplayMode(g_pDD, 640, 480, g_iBpp);
        if (DDFailedCheck(hr, "SetDisplayMode")) {
            return 0;
        }
    } else {
        // Set DDSCL_NORMAL to use windowed mode
        hr = IDirectDraw_SetCooperativeLevel(g_pDD, g_hWnd, DDSCL_NORMAL);
        if (DDFailedCheck(hr, "SetCooperativeLevel windowed")) {
            return 0;
        }

        DDSURFACEDESC surfaceDesc;
        memset(&surfaceDesc, 0, sizeof(surfaceDesc));
        surfaceDesc.dwSize = sizeof(surfaceDesc);

        IDirectDraw_GetDisplayMode(g_pDD, &surfaceDesc);
        if (DDFailedCheck(hr, "GetDisplayMode windowed")) {
            return 0;
        }

        g_iBpp = surfaceDesc.ddpfPixelFormat.dwRGBBitCount;

    }

    /* Creating surfaces */

    DDSURFACEDESC ddsd; // A structure to describe the surfaces we want
    // Clear all members of the structure to 0
    memset(&ddsd, 0, sizeof(ddsd));
    // The first parameter of the structure must contain the size of the structure
    ddsd.dwSize = sizeof(ddsd);

    if (g_bFullScreen) {
        // Screw the full-screen mode (for now) (FIXME)
    } else {

        //-- Create the primary surface

        // The dwFlags paramater tell DirectDraw which DDSURFACEDESC
        // fields will contain valid values
        ddsd.dwFlags = DDSD_CAPS;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

        hr = IDirectDraw_CreateSurface(g_pDD, &ddsd, &g_pDDS, NULL);
        if (DDFailedCheck(hr, "CreateSurface (primary)")) {
            return 0;
        }

        //-- Create the back buffer

        ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
        // Make our off-screen surface 320x240
        ddsd.dwWidth = 320;
        ddsd.dwHeight = 240;
        // Create an offscreen surface
        ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;

        hr = IDirectDraw_CreateSurface(g_pDD, &ddsd, &g_pDDSBack, NULL);
        if (DDFailedCheck(hr, "CreateSurface (back)")) {
            return 0;
        }

    }

    /* Creating the Clipper */

    if (!g_bFullScreen) {

        // Create the clipper using the DirectDraw object
        hr = IDirectDraw_CreateClipper(g_pDD, 0, &g_pClipper, NULL);
        if (DDFailedCheck(hr, "CreateClipper")) {
            return 0;
        }

        // Assign your window's HWND to the clipper
        hr = IDirectDrawClipper_SetHWnd(g_pClipper, 0, g_hWnd);
        if (DDFailedCheck(hr, "SetHWnd")) {
            return 0;
        }

        // Attach the clipper to the primary surface
        hr = IDirectDrawSurface_SetClipper(g_pDDS, g_pClipper);
        if (DDFailedCheck(hr, "SetClipper")) {
            return 0;
        }
    }
    return 1;
}

void DDCheckSurfaces() {
    // Check the primary surface
    if (g_pDDS) {
        if (IDirectDrawSurface_IsLost(g_pDDS) == DDERR_SURFACELOST) {
            IDirectDrawSurface_Restore(g_pDDS);
        }
    }
    // Check the back buffer
    if (g_pDDSBack) {
        if (IDirectDrawSurface_IsLost(g_pDDSBack) == DDERR_SURFACELOST) {
            IDirectDrawSurface_Restore(g_pDDSBack);
        }
    }
}

static void DDFlip(void) {
    HRESULT hr;

    // if we're windowed do the blit, else just Flip
    if (!g_bFullScreen)
    {
        RECT    rcSrc;  // source blit rectangle
        RECT    rcDest; // destination blit rectangle
        POINT   p;

        // find out where on the primary surface our window lives
        p.x = 0; p.y = 0;
        ClientToScreen(g_hWnd, &p);
        GetClientRect(g_hWnd, &rcDest);
        OffsetRect(&rcDest, p.x, p.y);
        SetRect(&rcSrc, 0, 0, 320, 240);
        hr = IDirectDrawSurface_Blt(g_pDDS, &rcDest, g_pDDSBack, &rcSrc, DDBLT_WAIT, NULL);
        if (DDFailedCheck(hr, "Blt")) {
        }
    } else {
        hr = IDirectDrawSurface_Flip(g_pDDS, NULL, DDFLIP_WAIT);
    }
}

static unsigned int CreateRGB(int r, int g, int b) {
    unsigned int pixel;
    switch (g_iBpp) {
    case 8:
        // Here you should do a palette lookup to find the closest match.
        // I'm not going to bother with that. Many modern games no
        // longer support 256-color modes.
        break;
    case 16:
        // Break down r,g,b into 5-6-5 format.
        pixel = ((r / 8) << 11) | (( g / 4) << 5) | (b / 8);
        break;
    case 24:
    case 32:
        pixel = (r << 16) | (g << 8) | (b);
        break;
    default:
        pixel = 0;
    }
    return pixel;
}

static void DDPutPixel(LPDDSURFACEDESC pSurfaceDesc, int x, int y, int r, int g, int b) {
    DWORD color = CreateRGB(r, g, b);
    void *pixelAddress = ((char*)pSurfaceDesc->lpSurface) + y * pSurfaceDesc->lPitch + x * pSurfaceDesc->ddpfPixelFormat.dwRGBBitCount / 8;
    switch (pSurfaceDesc->ddpfPixelFormat.dwRGBBitCount) {
    case 32:
        *(unsigned int *)pixelAddress = (unsigned int)color;
        break;
    case 16:
        *(unsigned short *)pixelAddress = (unsigned short)color;
        break;
    case 8:
        *(unsigned char *)pixelAddress = (unsigned char)color;
        break;
    }
}

static void DDClear(LPDIRECTDRAWSURFACE pDDS, int pX, int pY, int pW, int pH, int r, int g, int b) {
    HRESULT hr;
    DDBLTFX ddbfx;
    RECT rcDest;

    // Safety net
    if (g_pDDS == NULL) {
        return;
    }

    // Initialize the DDBLTFX structure with the pixel color
    memset(&ddbfx, 0, sizeof(ddbfx));
    ddbfx.dwSize = sizeof(ddbfx);
    static int ii = 0;
    ddbfx.dwFillColor = CreateRGB(r, g, b);
    ii++;

    // Prepare the destination rectangle as a 1x1 (1 pixel) rectangle
    SetRect(&rcDest, pX, pY, pX + pW, pY + pH);

    hr = IDirectDrawSurface_Blt(pDDS, &rcDest, NULL, NULL, DDBLT_WAIT | DDBLT_COLORFILL, &ddbfx);
    if (DDFailedCheck(hr, "Blt")) {
    }

}

void DDHeartBeat() {
    // Check for lost surfaces
    DDCheckSurfaces();

    // Clear the back buffer
    DDClear(g_pDDSBack, 0, 0, 320, 240, 255, 0, 0);

    HRESULT hr;
    DDSURFACEDESC surfaceDesc;
    memset(&surfaceDesc, 0, sizeof(surfaceDesc));
    surfaceDesc.dwSize = sizeof(surfaceDesc);
    hr = IDirectDrawSurface_Lock(g_pDDSBack, NULL, &surfaceDesc, DDLOCK_WAIT, NULL);
    if (DDFailedCheck(hr, "Lock")) {
    }

    const int W = 160;
    const int H = 120;
    static int iFoo = 0;
    // Draw a weird looking color square
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            DDPutPixel(&surfaceDesc, x, y, (y * 2 + iFoo) % 256, (x + iFoo) % 256, (2*x + 2*y) % 256);
        }
    }
    iFoo++;

    hr = IDirectDrawSurface_Unlock(g_pDDSBack, NULL);
    if (DDFailedCheck(hr, "Unlock")) {
    }

    // Blit the back buffer to the front buffer
    DDFlip();
}

void DDDone() {
    if (g_pDDSBack != NULL) {
        IDirectDrawSurface_Release(g_pDDSBack);
        g_pDDSBack = NULL;
    }
    if (g_pDDS != NULL) {
        IDirectDrawSurface_Release(g_pDDS);
        g_pDDS = NULL;
    }
    if (g_pDD != NULL) {
        IDirectDraw_Release(g_pDD);
        g_pDD = NULL;
    }
}
