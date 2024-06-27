#include "dd.h"

#include <windows.h>
#include <ddraw.h>
#include <io.h>

#include <stdio.h>
#include <string.h>

static ATOM g_windowClassAtom;
static HINSTANCE g_hInstance;
static HWND g_hwndMain;
static int g_bRunning;
#define CLASSNAME "ddraw_win32"

static void FatalError(const char *pMsg) {
    OutputDebugStringA(pMsg);
    MessageBoxA(g_hwndMain, pMsg, "Error", MB_ICONERROR);
}

static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        g_bRunning = 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

static int RegisterMyWindow(HINSTANCE hInstance) {
    WNDCLASSA wndClass;
    memset(&wndClass, 0, sizeof(wndClass));
    wndClass.lpfnWndProc = WndProc;
    wndClass.hInstance = hInstance;
    wndClass.hbrBackground = (HBRUSH)GetStockObject(COLOR_WINDOW + 1);//COLOR_WINDOW+1);;
    wndClass.lpszClassName = CLASSNAME;
    g_windowClassAtom = RegisterClassA(&wndClass);
    return g_windowClassAtom != 0;
}

static HWND CreateMyWindow(int nCmdShow, const char *title, int width, int height) {
    (void) nCmdShow;
    return CreateWindowExA(
        0,                                   /* DWORD dwExStyle */
        CLASSNAME,                           /* LPCSTR lpClassName */
        title,                               /* LPCSTR lpWindowName */
        WS_VISIBLE | WS_OVERLAPPEDWINDOW,    /* DWORD dwStyle */
        CW_USEDEFAULT,                       /* int X */
        CW_USEDEFAULT,                       /* int Y */
        width,                               /* int nWidth */
        height,                              /* int nHeight */
        NULL,                                /* HWND hWndParent */
        NULL,                                /* HMENU hMenu */
        g_hInstance,                         /* HINSTANCE hInstance */
        NULL);                               /* LPVOID lpParam */
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    (void)lpCmdLine;
    g_hInstance = hInstance;

    /* Attach to the console that started us if any */
    if (AttachConsole(ATTACH_PARENT_PROCESS)) {
        /* We attached successfully, lets redirect IO to the consoles handles if not already redirected */
        if (_fileno(stdout) == -2 || _get_osfhandle(_fileno(stdout)) == -2) {
            FILE *f;
            freopen_s(&f, "CONOUT$", "w", stdout);
        }

        if (_fileno(stderr) == -2 || _get_osfhandle(_fileno(stderr)) == -2) {
            FILE *f;
            freopen_s(&f, "CONOUT$", "w", stderr);
        }

        if (_fileno(stdin) == -2 || _get_osfhandle(_fileno(stdin)) == -2) {
            FILE *f;
            freopen_s(&f, "CONIN$", "r", stdin);
        }
    }

    if (!hPrevInstance) {
        if (!RegisterMyWindow(g_hInstance)) {
            return 1;
        }
    }

    g_hwndMain = CreateMyWindow(nCmdShow, "Win32 ddraw", 320, 240);
    if (!g_hwndMain) {
        FatalError("Failed to create a window");
        return 1;
    }

    if (!DDInit(g_hwndMain)) {
        FatalError("Failed to initialize DirectDraw");
        return 1;
    }

    if (!DDCreateSurfaces(0)) {
        FatalError("Failed to create surfaces");
        return 1;
    }

    MSG msg;
    g_bRunning = 1;
    while (g_bRunning) {
        while (PeekMessage(&msg, g_hwndMain, 0, 0, PM_NOREMOVE)) {
            GetMessage(&msg, NULL, 0, 0);
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        if (g_bRunning) {
            DDHeartBeat();
        }
    }

    DDDone();

    return 0;
}
