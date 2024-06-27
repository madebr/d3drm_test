#include "dd.h"

#include <d3drm.h>
#include <ddraw.h>

#include <stdio.h>

static LPDIRECTDRAW g_pDD;
static LPDIRECT3DRM g_pD3DRM;
static LPDIRECTDRAWSURFACE g_pDDSPrimary;
static LPDIRECTDRAWSURFACE g_pDDSBack;
static LPDIRECTDRAWPALETTE g_pDDPal;
static LPDIRECTDRAWCLIPPER g_pClipper;
static LPDIRECT3DRMDEVICE g_pD3DRMDevice;
static LPDIRECT3DRMVIEWPORT g_pViewport;
static LPDIRECT3DRMFRAME g_pCamera;
static LPDIRECT3DRMFRAME g_pScene;
static LPDIRECT3DRMFRAME g_pCube;
static HWND g_hWnd;
static int g_bFullScreen;
static int g_bAnimating;
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
        fprintf(stderr, "%s (%s)\n", szMessage, DDErrorString(hr));
        return 1;
    }
    return 0;
}

void DDPreInit() {
    g_pDD = NULL;
    g_pD3DRM = NULL;
    g_pDDSPrimary = NULL;
    g_pDDSBack = NULL;
    g_pDDPal = NULL;
    g_pClipper = NULL;
    g_pD3DRMDevice = NULL;
    g_pViewport = NULL;
    g_pCamera = NULL;
    g_pScene = NULL;
    g_pCube = NULL;

    g_bFullScreen = FALSE;
    g_bAnimating = FALSE;
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
        g_iBpp = 8;
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

        hr = IDirectDraw_CreateSurface(g_pDD, &ddsd, &g_pDDSPrimary, NULL);
        if (DDFailedCheck(hr, "CreateSurface (primary)")) {
            return 0;
        }

        //-- Create the back buffer

        ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
        // Make our off-screen surface 320x240
        ddsd.dwWidth = 320;
        ddsd.dwHeight = 240;
        // Create an offscreen surface
        ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_3DDEVICE;

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
        hr = IDirectDrawSurface_SetClipper(g_pDDSPrimary, g_pClipper);
        if (DDFailedCheck(hr, "SetClipper")) {
            return 0;
        }
    }
    return 1;
}

void DDCheckSurfaces() {
    // Check the primary surface
    if (g_pDDSPrimary) {
        if (IDirectDrawSurface_IsLost(g_pDDSPrimary) == DDERR_SURFACELOST) {
            IDirectDrawSurface_Restore(g_pDDSPrimary);
        }
    }
    // Check the back buffer
    if (g_pDDSBack) {
        if (IDirectDrawSurface_IsLost(g_pDDSBack) == DDERR_SURFACELOST) {
            IDirectDrawSurface_Restore(g_pDDSBack);
        }
    }
}

static BOOL InitializeDirect3DRM(void) {
    HRESULT hr;
    hr = Direct3DRMCreate(&g_pD3DRM);
    if (DDFailedCheck(hr, "Direct3DRMCreate")) {
        return FALSE;
    }
    return TRUE;
}

static BOOL CreateD3DRMDevice(void) {
    HRESULT hr;
    hr = IDirect3DRM_CreateDeviceFromSurface(g_pD3DRM, NULL, g_pDD, g_pDDSBack, &g_pD3DRMDevice);
    if (DDFailedCheck(hr, "CreateDeviceFromSurface")) {
        return FALSE;
    }
    return TRUE;
}

static BOOL CreateD3DRMViewport(void) {
    HRESULT hr;

    // First create the scene frame
    hr = IDirect3DRM_CreateFrame(g_pD3DRM, NULL, &g_pScene);
    if (DDFailedCheck(hr, "CreateFrame (scene)")) {
        return FALSE;
    }

    // Next, create the camera as a child of the scene
    hr = IDirect3DRM_CreateFrame(g_pD3DRM, g_pScene, &g_pCamera);
    if (DDFailedCheck(hr, "CreateFrame (camera)")) {
        return FALSE;
    }

    // Set the camera to lie somewhere on the negative z-axis, and
    // point towards the origin
    hr = IDirect3DRMFrame_SetPosition(g_pCamera, g_pScene, D3DVAL(0.0), D3DVAL(0.0), D3DVAL(-300.0));
    if (DDFailedCheck(hr, "SetPosition (camera)")) {
        return FALSE;
    }

    IDirect3DRMFrame_SetOrientation(g_pCamera, g_pScene,
            D3DVAL(0.0), D3DVAL(0.0), D3DVAL(1.0),
            D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0));
    if (DDFailedCheck(hr, "SetOrientation (camera)")) {
        return FALSE;
    }

    // create lights
    LPDIRECT3DRMLIGHT pLightAmbient = NULL;
    LPDIRECT3DRMLIGHT pLightDirectional = NULL;
    LPDIRECT3DRMFRAME pLights = NULL;

    // Create two lights and a frame to attach them to
    // I haven't quite figured out the CreateLight's second
    // parameter yet.
    hr = IDirect3DRM_CreateFrame(g_pD3DRM, g_pScene, &pLights);
    if (DDFailedCheck(hr, "CreateFrame (lights)")) {
        return FALSE;
    }

    hr = IDirect3DRM_CreateLight(g_pD3DRM, D3DRMLIGHT_AMBIENT, D3DRMCreateColorRGB(D3DVAL(0.3), D3DVAL(0.3), D3DVAL(0.3)),
                        &pLightAmbient);
    if (DDFailedCheck(hr, "CreateLight (ambient)")) {
        return FALSE;
    }
    hr = IDirect3DRM_CreateLight(g_pD3DRM, D3DRMLIGHT_DIRECTIONAL, D3DRMCreateColorRGB(D3DVAL(0.8), D3DVAL(0.8), D3DVAL(0.8)),
                        &pLightDirectional);
    if (DDFailedCheck(hr, "CreateLight (directional)")) {
        return FALSE;
    }

    // Orient the directional light
    hr = IDirect3DRMFrame_SetOrientation(pLights, g_pScene,
                            D3DVAL(30.0), D3DVAL(-20.0), D3DVAL(50.0),
                            D3DVAL(0.0), D3DVAL(1.0), D3DVAL(0.0));
    if (DDFailedCheck(hr, "SetOrientation (lights)")) {
        return FALSE;
    }

    // Add ambient light to the scene, and the directional light
    // to the pLights frame
    hr = IDirect3DRMFrame_AddLight(g_pScene, pLightAmbient);
    if (DDFailedCheck(hr, "AddLight (ambient light)")) {
        return FALSE;
    }
    hr = IDirect3DRMFrame_AddLight(g_pScene, pLightDirectional);
    if (DDFailedCheck(hr, "AddLight (directional light)")) {
        return FALSE;
    }

    // Create the viewport on the device
    hr = IDirect3DRM_CreateViewport(g_pD3DRM, g_pD3DRMDevice, g_pCamera, 10, 10, 300, 220, &g_pViewport);
    if (DDFailedCheck(hr, "CreateViewport")) {
        return FALSE;
    }
    // set the back clipping field
    hr = IDirect3DRMViewport_SetBack(g_pViewport, D3DVAL(5000.0));
    if (DDFailedCheck(hr, "SetBack")) {
        return FALSE;
    }

    // Release the temporary lights created. It seems
    // they will have been copied for the scene during AddLight
    IDirect3DRMLight_Release(pLightAmbient);
    IDirect3DRMLight_Release(pLightDirectional);

    // success
    return TRUE;
}

static BOOL CreateD3DRMDefaultScene(void) {
    HRESULT hr;

    // Create the frame for the cube
    hr = IDirect3DRM_CreateFrame(g_pD3DRM, g_pScene, &g_pCube);
    if (DDFailedCheck(hr, "CreateFrame cube")) {
        return FALSE;
    }
    // Load the cube
    hr = IDirect3DRMFrame_Load(g_pCube, "cube.x", NULL, D3DRMLOAD_FROMFILE, NULL, NULL);
    if (DDFailedCheck(hr, "Load (cube.x)")) {
        return FALSE;
    }
    // Set cube's position/orientation relative to scene
    hr = IDirect3DRMFrame_SetPosition(g_pCube, g_pScene, D3DVAL(0.0), D3DVAL(0.0), D3DVAL(0.0));
    if (DDFailedCheck(hr, "SetPosition (cube)")) {
        return FALSE;
    }

    hr = IDirect3DRMFrame_SetRotation(g_pCube, g_pScene, D3DVAL(1.0), D3DVAL(1.0), D3DVAL(0.0), D3DVAL(0.1));
    if (DDFailedCheck(hr, "SetRotation (cube)")) {
        return FALSE;
    }

    // success
    return TRUE;
}

BOOL DDLoadD3DRM(void) {

    if (!InitializeDirect3DRM()) {
        return FALSE;
    }
    if (!CreateD3DRMDevice()) {
        return FALSE;
    }
    if (!CreateD3DRMViewport()) {
        return FALSE;
    }
    if (!CreateD3DRMDefaultScene()) {
        return FALSE;
    }
    g_bAnimating = TRUE;
    return TRUE;
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
        hr = IDirectDrawSurface_Blt(g_pDDSPrimary, &rcDest, g_pDDSBack, &rcSrc, DDBLT_WAIT, NULL);
        if (DDFailedCheck(hr, "Blt")) {
        }
    } else {
        hr = IDirectDrawSurface_Flip(g_pDDSPrimary, NULL, DDFLIP_WAIT);
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
    if (g_pDDSPrimary == NULL) {
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
    HRESULT hr;
    if (g_bAnimating) {
        hr = IDirect3DRM_Tick(g_pD3DRM, D3DVAL(1.0));
        if (DDFailedCheck(hr, "Tick")) {
            return;
        }
    } else {
        hr = IDirect3DRMViewport_ForceUpdate(g_pViewport, 10, 10, 300, 180);
        if (DDFailedCheck(hr, "ForceUpdate")) {
            return;
        }
    }
    hr = IDirect3DRMDevice_Update(g_pD3DRMDevice);
    if (DDFailedCheck(hr, "Update")) {
        return;
    }

    // Call our routine for flipping the surfaces
    DDFlip();
}

void DDDone() {
    if (g_pViewport != NULL) {
        IDirect3DRMViewport_Release(g_pViewport);
        g_pViewport = NULL;
    }
    if (g_pCamera != NULL) {
        IDirect3DRMFrame_Release(g_pCamera);
        g_pCamera = NULL;
    }
    if (g_pCube != NULL) {
        IDirect3DRMFrame_Release(g_pCube);
        g_pCube = NULL;
    }
    if (g_pScene != NULL) {
        IDirect3DRMFrame_Release(g_pScene);
        g_pScene = NULL;
    }
    if (g_pD3DRMDevice != NULL) {
        IDirect3DRMDevice_Release(g_pD3DRMDevice);
        g_pD3DRMDevice = NULL;
    }
    if (g_pD3DRM != NULL) {
        IDirect3DRM_Release(g_pD3DRM);
        g_pD3DRM = NULL;
    }
    if (g_pClipper != NULL) {
        IDirectDrawClipper_Release(g_pClipper);
        g_pClipper = NULL;
    }
    if (g_pDDSBack != NULL) {
        IDirectDrawSurface_Release(g_pDDSBack);
        g_pDDSBack = NULL;
    }
    if (g_pDDSPrimary != NULL) {
        IDirectDrawSurface_Release(g_pDDSPrimary);
        g_pDDSPrimary = NULL;
    }
    if (g_pDD != NULL) {
        IDirectDraw_Release(g_pDD);
        g_pDD = NULL;
    }
}

void DDEnableAnimation(BOOL pEnable) {
    g_bAnimating = pEnable;
}
