// copyright (c) 2010, Roman T. Gritsulyak
#include <windows.h>
#include <commctrl.h>

#pragma comment(lib, "comctl32.lib")

#include "game.h"
#include "gamedrawer.h"
#include "game_fields.h"
#include "Resource.h"

const int NUM_BUTTON_BITMAPS = 3;
const int MAX_LEN=1024;
HINSTANCE hInstance=NULL;
HWND hMainWnd;
HWND g_hToolBar;
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

GameDrawer * ptheGameDrawer;
#define MAX_LOADSTRING 100
/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = TEXT( "123FillApp" );

void ProtectedClose()
{
            if( MessageBox(hMainWnd, TEXT("Exit?"),TEXT( "Question:"),
                       MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES)
                       {
                           PostQuitMessage(0);
                       }
}

BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{
		case WM_INITDIALOG:

		return TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDOK:
					EndDialog(hwnd, IDOK);
				break;
				case IDCANCEL:
					EndDialog(hwnd, IDCANCEL);
				break;
			}
		break;
		default:
			return FALSE;
	}
	return TRUE;
}

static TCHAR lptsCodeGet[1024] = {0};

BOOL CALLBACK GetCodeDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{
		case WM_INITDIALOG:

		return TRUE;
		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDOK:
                    GetDlgItemText(hwnd, IDC_EDIT1, lptsCodeGet,1024);
					EndDialog(hwnd, IDOK);
				break;
				case IDCANCEL:
                    lptsCodeGet[0] = 0;
					EndDialog(hwnd, IDCANCEL);
				break;
			}
		break;
		default:
			return FALSE;
	}
	return TRUE;
}

void WinCreateToolbar(HWND hwnd)
{
// standard toolbars don't allow
// nonstadardly specially build images
    TBADDBITMAP tbab;
    TBBUTTON tbb[6];
//TBSTYLE_LIST style and then set the TBSTYLE_EX_MIXEDBUTTONS
    g_hToolBar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL,
                                WS_CHILD | WS_VISIBLE , 0, 0, 0, 0,
                                hwnd, (HMENU)ID_TOOLBAR, hInstance, NULL);

    // Send the TB_BUTTONSTRUCTSIZE message, which is required for
    // backward compatibility.
    SendMessage(g_hToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);

    tbab.hInst = hInstance;
    tbab.nID = IDB_TOOLBITMAP;

    SendMessage(g_hToolBar, TB_ADDBITMAP, 4, (LPARAM)&tbab);

    ZeroMemory(tbb, sizeof(tbb));
    tbb[0].iBitmap = 0;
    tbb[0].fsState = TBSTATE_ENABLED;
    tbb[0].fsStyle = TBSTYLE_BUTTON;
    tbb[0].idCommand = IDM_NEW;

    tbb[1].iBitmap = 1;
    tbb[1].fsState = TBSTATE_ENABLED;
    tbb[1].fsStyle = TBSTYLE_BUTTON;
    tbb[1].idCommand = IDM_NEWLEVEL;

    tbb[2].fsStyle = TBSTYLE_SEP;

    tbb[3].iBitmap = 2;
    tbb[3].fsState = TBSTATE_ENABLED;
    tbb[3].fsStyle = TBSTYLE_BUTTON;
    tbb[3].idCommand = IDM_ABOUT;

    tbb[4].fsStyle = TBSTYLE_SEP;

    tbb[5].iBitmap = 3;
    tbb[5].fsState = TBSTATE_ENABLED | TBSTYLE_GROUP ; // | TBSTATE_HIDDEN to hide
    tbb[5].fsStyle = TBSTYLE_BUTTON;
    tbb[5].idCommand = IDM_EXIT;

    SendMessage(g_hToolBar, TB_ADDBUTTONS, 6, (LPARAM)&tbb);
}

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    initializeGlobalFields();

    InitCommonControls();

    hInstance = hThisInstance;

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);
    /* Use default icon and mouse-pointer */
    //wincl.hIcon = LoadIcon (NULL, IDI_WINLOGO);//MAKEINTRESOURCE(IDI_SMALL)
    //wincl.hIconSm = LoadIcon (NULL, IDI_WINLOGO);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.hIcon = (HICON)LoadImage(hThisInstance,MAKEINTRESOURCE(IDI_SMALL),IMAGE_ICON,0,0,0);
    wincl.hIconSm = wincl.hIcon;
    wincl.lpszMenuName =  MAKEINTRESOURCE(IDC_WIN32MINE);
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) (COLOR_WINDOW+1);

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
    {
        MessageBox(0, TEXT("Window Registration Failed!"),TEXT("Error!"),
                   MB_ICONEXCLAMATION | MB_OK | MB_SYSTEMMODAL);
        return 0;
    }

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
               0,                   /* Extended possibilites for variation */
               szClassName,         /* Classname */
               TEXT("Roman Gritsulyak's 123Fill"),       /* Title Text */
               WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU | WS_MAXIMIZEBOX,
               // -- WINDOW| WS_EX_RIGHTSCROLLBAR | WS_EX_LEFTSCROLLBAR, /* default window */
               CW_USEDEFAULT,       /* Windows decides the position */
               CW_USEDEFAULT,       /* where the window ends up on the screen */
               544,                 /* The programs width */
               375,                 /* and height in pixels */
               NULL,        /* The window is a child-window to desktop */
               NULL,                /* No menu */
               hThisInstance,       /* Program Instance handler */
               NULL                 /* No Window Creation data */
           );

    hMainWnd = hwnd;

    /* TODO MAYBE status
    CreateStatusWindow(WS_CHILD|WS_VISIBLE,L"text",hwnd,190);
    int widths[5]={30,50,200,-1};
    SendDlgItemMessage(hwnd,190,SB_SETPARTS,4,(LPARAM)widths);
    SendDlgItemMessage(hwnd,190,SB_SETTEXT,2,(LPARAM)L"part 2");
    SendDlgItemMessage(hwnd,190,SB_SETTEXT,3,(LPARAM)L"last part");
    */

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static volatile char game_proc_state = 0; // 0 not processing 1 processing
    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        WinCreateToolbar(hwnd);
        ptheGameDrawer = new GameDrawer ;
        ptheGameDrawer->drawGameField(hwnd);
        break;
    case WM_CLOSE:
            ProtectedClose();
        break;
    case WM_COMMAND:
    switch (LOWORD(wParam))
        {
        case IDM_ABOUT:
            {
            int ret = DialogBox(GetModuleHandle(NULL),
						MAKEINTRESOURCE(IDD_ABOUTBOX), hwnd, AboutDlgProc);
#if 0
					if(ret == IDOK){
					}
					else if(ret == IDCANCEL){
						MessageBox(hwnd, _T("Dialog exited unnormally"), _T("Notice"),
							MB_OK | MB_ICONEXCLAMATION);
					}
					else if(ret == -1){
						MessageBox(hwnd, _T("Dialog failed!"), _T("Error"),
							MB_OK | MB_ICONERROR);
                    }
#endif
            }
            break;
        case IDM_NEWLEVEL:
            {
                int ret = DialogBox(GetModuleHandle(NULL),
                    MAKEINTRESOURCE(IDD_DIALOG1), hwnd, GetCodeDlgProc);

                if(ret == IDOK)
                    ptheGameDrawer->MoveToRoundWithCode(lptsCodeGet);
                else break;
            }
            break;
        case IDM_NEW:
        {
            TCHAR buffer[1024] = { 0 };
            if( MessageBox(hwnd, TEXT("Start new game?"), TEXT("Question:"),
                       MB_YESNOCANCEL | MB_ICONQUESTION) == IDYES)
                       {
                        delete ptheGameDrawer;
                        ptheGameDrawer = new GameDrawer ;
                        ptheGameDrawer->drawGameField(hwnd);
                       }
        }
        break;
        case IDM_EXIT:
            ProtectedClose();
        break;
        default:
		if(!game_proc_state)
		{
			game_proc_state = 1; // semi-mutex
			ptheGameDrawer->ProcessClickOnHWND((HWND) lParam);
			game_proc_state = 0;
		}
		break;
        }
        break;

        case WM_NOTIFY:
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
        }
        return 0;
    }
