/*****************************************************************************
*
*  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
*  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
*  TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR
*  A PARTICULAR PURPOSE.
*
*  Copyright (C) 1993-1999 Microsoft Corporation. All Rights Reserved.
*
******************************************************************************
*
* UiUtils.C
*
* UI utility routines
*
*****************************************************************************/

#include <windows.h>
#include <windowsx.h>

#include <mmsystem.h>
#include <commdlg.h>
#include <commctrl.h>
#include <ctype.h>

#include "debug.h"

#include "midiplyr.h"

static char BCODE          gszFace[]               = "arial";

/*****************************************************************************
*
* EmbossedTextOut
*
* Draw embossed text in the given device context
*
* hDC                       - hDC to draw in
* x, y                      - Upper left corner of text
* lpsz                      - Pointer to the text
* cb                        - Length of text
* crText                    - Color for text face
* crShadow                  - Color for text shadow
* cx, cy                    - Offset for shadow
*
* The text will be drawn with the currently selected font.
*
* If cb == -1, the lstrlen(lpsz) will be used.
*
* If crText == -1, COLOR_BTNTEXT will be used.
*
* If crShadow == -1, COLOR_BTNSHADOW will be used.
*
*****************************************************************************/
VOID EmbossedTextOut(
    HDC                     hDC,
    int                     x,
    int                     y,
    LPSTR                  lpsz,
    UINT                    cb,
    COLORREF                crText,
    COLORREF                crShadow,
    int                     cx,
    int                     cy)
{
    COLORREF                crOld;
    UINT                    uMode;
    SIZE                    sizeText;
    RECT                    rcText;

    /* If text length is -1, use lstrlen to get the length
    ** of the text.
    */
    if (cb == -1)
        cb = lstrlen(lpsz);

    /* If the shadow or text color is -1, use the
    ** system color for that one.
    */
    if (crShadow == (COLORREF)-1)
        crShadow = GetSysColor (COLOR_BTNSHADOW);
    if (crText == (COLORREF)-1)
        crText = GetSysColor (COLOR_BTNTEXT);

    /* setup the DC, saving off the old values
    */
    uMode = SetBkMode(hDC, OPAQUE);
    crOld = SetTextColor(hDC, crShadow);

    /* Draw the text at the desired offset using the
    ** shadow color, then again at the normal position
    ** using the text color.  This will the text an 'Embossed'
    ** or 'drop shadowed' look depending on what shadow color
    ** and offset are used.
    */
    GetTextExtentPoint32(hDC, lpsz, cb, &sizeText);
    rcText.left   = x;    rcText.right  = x+cx+sizeText.cx;
    rcText.top    = y;    rcText.bottom = y+cy+sizeText.cy;
    ExtTextOut(hDC, x+cx, y+cy, ETO_OPAQUE, &rcText, lpsz, cb, NULL);
    SetBkMode(hDC, TRANSPARENT);
    SetTextColor(hDC, crText);
    ExtTextOut(hDC, x, y, 0, NULL, lpsz, cb, NULL);

    /* restore the DC
    */
    SetTextColor(hDC, crOld);
    SetBkMode(hDC, uMode);
}

/*****************************************************************************
*
* CreateScaledFont
*
* Create a font scaled so that the given string will fit in the given
* rect, but be as large as possible while maintaining correct aspect ratio.
*
* hDC                       - DC to calculate font for
* lpRect                    - Rectangle to fit text into
* lpszFormat                - Format string to fit into rect
* anPosX[]                  - Will contain the X coordinates for each char
* anPosY                    - Will contain the Y coordinate for the string
*
* Returns HFONT or NULL if one could not be created
*
*****************************************************************************/
HFONT CreateScaledFont(
    HDC                     hDC,
    LPRECT                  lpRect,
    LPSTR                  lpszFormat,
    int                     anPosX[],
    int*                    nPosY)
{
    LOGFONT                 lf;
    HFONT                   hFont;
    HFONT                   h;
    LONG                    FormatWidth;
    LONG                    ScaledClientWidth;
    LONG                    ScaledClientHeight;
    LONG                    AspectN;
    LONG                    AspectD;
    int                     nPosX;
    UINT                    cb;
    UINT                    ii;
    UINT                    jj;
    SIZE                    size;

    ScaledClientHeight =  ((lpRect->bottom - lpRect->top)) * 3 / 4;
    ScaledClientWidth  =  ((lpRect->right  - lpRect->left)) * 3 / 4;

    _fmemset(&lf, 0, sizeof(lf));
    lf.lfHeight         = -(int)ScaledClientHeight;
    lf.lfWeight         = FW_BOLD;
    lf.lfCharSet        = ANSI_CHARSET;
    lf.lfClipPrecision  = CLIP_DEFAULT_PRECIS;
    lf.lfQuality        = PROOF_QUALITY;
    lf.lfPitchAndFamily = FF_ROMAN|DEFAULT_PITCH;
    lstrcpy(lf.lfFaceName, gszFace);

    hFont = CreateFontIndirect(&lf);
    h = SelectObject(hDC, hFont);

    cb = lstrlen(lpszFormat);
    GetTextExtentPoint(hDC, lpszFormat, cb, &size);

    AspectN = (LONG)size.cx;
    AspectD = (LONG)size.cy;

    FormatWidth = (ScaledClientHeight*AspectN)/AspectD;

    if (FormatWidth > ScaledClientWidth)
    {
        ScaledClientHeight =
            (ScaledClientWidth*AspectD)/AspectN;
    	SelectObject(hDC, h);
        DeleteObject(hFont);

        lf.lfHeight = -(int)ScaledClientHeight;

        hFont = CreateFontIndirect(&lf);

        SelectObject(hDC, hFont);
        GetTextExtentPoint(hDC, lpszFormat, cb, &size);
    }

    *nPosY  = grcTWnd.top  + (grcTWnd.bottom- grcTWnd.top  - size.cy)/2;
    nPosX   = grcTWnd.left + (grcTWnd.right - grcTWnd.left - size.cx)/2;

    ii = 0;
    for (jj=0; jj < cb; jj++)
    {
        if (jj != 0)
            GetTextExtentPoint(hDC, lpszFormat, jj, &size);
        else
            size.cx = 0;

        anPosX[ii++] = nPosX + size.cx;
    }

    SelectObject(hDC, h);

    return hFont;
}
