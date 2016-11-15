// copyright (c) 2010, Roman T. Gritsulyak
#include "util.h"


void ClientResize(HWND hmyWnd, int nWidth, int nHeight)
{
    RECT rcClient, rcWindow;

    POINT ptDiff;

    GetClientRect(hmyWnd, &rcClient);
    GetWindowRect(hmyWnd, &rcWindow);
    ptDiff.x = (rcWindow.right - rcWindow.left) - rcClient.right;
    ptDiff.y = (rcWindow.bottom - rcWindow.top) - rcClient.bottom;

    BOOL Hret=MoveWindow(hmyWnd,rcWindow.left, rcWindow.top,
                         nWidth+ptDiff.x , nHeight+ptDiff.y, TRUE);

    if(!Hret)
        MsgBoxErrorFrom(L"ClientResize");
}

void MsgBoxErrorFrom(WCHAR * wtitle)
{
        DWORD Error = GetLastError();
        TCHAR BufErr[MAXCHAR];

        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, Error, LANG_SYSTEM_DEFAULT, BufErr, MAXCHAR, NULL);

        MessageBox(0, BufErr,wtitle,
                   MB_ICONEXCLAMATION | MB_OK | MB_SYSTEMMODAL);

        return;
}
