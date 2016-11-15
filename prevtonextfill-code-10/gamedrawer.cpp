// copeyright (c) Roman T. Gritsulyak 2010
#include "gamedrawer.h"
#include "Resource.h"
#include <algorithm>
#include "util.h"
#include <string>

// representation layer implementation

bool GameDrawer::dump_Field(std::wstring & s_field)
{
    TCHAR sztval[20];
    s_field +=L"Current size:" ;
    wsprintfW(sztval,L"%d", theGame.m_Pathes[0].size());
    s_field += sztval;
    s_field +=L"\nPassed Fields:";
    wsprintfW(sztval,L"%d", theGame.m_Passed.size());
    s_field += sztval;
    return true;
};

GameDrawer::GameDrawer()
{
    upMargin = 0 + 32; // 32 = size of toolbar
    leftMargin = 0;
    cellXsize = 30;
    cellYsize = 30;
    initTypeDrawMatrix();
    return;
}

GameDrawer::~GameDrawer()
{
    clearRes();
    return;
}

void GameDrawer::clearRes()
{
    for (int  x=0; x<theGame.m_GameField.xSize; x++)
        for (int y=0; y<theGame.m_GameField.ySize; y++)
        {
            std::pair<int,int> XY = std::pair<int,int>(x,y);
            DestroyWindow(initedFields[XY]);
        }

    initedFields.clear();

    theGame.clean();

    return;
}

bool GameDrawer::initTypeDrawMatrix()
{
    //  std::map<std::pair<DrawType,bool>,HBITMAP>  mGameElements
    struct tmpElem
    {
        DrawType elem;
        bool isHead;
        int ibmp;
    };

    tmpElem myElems[]=
    {
        {LeftRight,true,IDB_HEADRIGHT},
        {RightLeft,true,IDB_HEADLEFT},
        {LeftDown,true,IDB_HEADLEFT},
        {RightDown,true,IDB_HEADRIGHT},
        {UpDown,true,IDB_HEADDOWN},
        {DownUp,true,IDB_HEADUP},
        {UpRight,true,IDB_HEADUP},
        {UpLeft,true,IDB_HEADLEFT},
        {TargetType,true,0},
        {NotAField,true,0},
        {LeftRight,false,IDB_LEFTRIGHT},
        {RightLeft,false,IDB_LEFTRIGHT},
        {LeftDown,false,IDB_LEFTDOWN},
        {RightDown,false,IDB_RIGHTDOWN},
        {UpDown,false,IDB_UPDOWN},
        {DownUp,false,IDB_UPDOWN},
        {UpRight,false,IDB_UPRIGHT},
        {UpLeft,false,IDB_UPLEFT},
        {TargetType,false,0},
        {NotAField,false,0}
    };

    std::pair<DrawType,bool> current;

    for (int i=0; i<20; i++)
    {
        current = std::pair<DrawType,bool>(myElems[i].elem,myElems[i].isHead);
        mGameElements[current] =
            LoadBitmap(hInstance,MAKEINTRESOURCE(myElems[i].ibmp));
    }

    return true;
}

// functions related to representing
// game on forms
// just field without path
bool GameDrawer::drawGameField(HWND hWnd)
{
    // draw buttons
    for (int  x=0; x<theGame.m_GameField.xSize; x++)
        for (int y=0; y<theGame.m_GameField.ySize; y++)
        {
            std::pair<int,int> XY = std::pair<int,int>(x,y);
            //     DrawXYElement(hWnd, std::pair<int,int>(x,y), L" ");
            int realX = x*cellXsize + leftMargin;
            int realY = y*cellYsize + upMargin;

            HWND hwndButton = CreateWindowW(
                                  L"button",   // predefined class
                                  L" ",       // button text
                                  WS_VISIBLE | WS_CHILD| BS_BITMAP,  // styles
                                  realX,         // starting x position
                                  realY,         // starting y position
                                  cellXsize,        // button width
                                  cellYsize,        // button height
                                  hWnd,       // parent window
                                  NULL,       // No menu
                                  (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE),
                                  NULL);      // pointer not needed
            initedFields[XY] = hwndButton;
        }

    for (std::vector<Target>::iterator iter = theGame.m_GameField.m_Fields.begin();
            iter != theGame.m_GameField.m_Fields.end(); iter++)
    {
        DestroyWindow((HWND)initedFields[iter->targetXY]);

        //     DrawXYElement(hWnd, std::pair<int,int>(x,y), L" ");
        int realX = iter->targetXY.first*cellXsize + leftMargin;
        int realY = iter->targetXY.second*cellYsize + upMargin;

        HWND hwndButton = CreateWindowW(
                              L"button",   // predefined class
                              L" ",       // button text
                              WS_VISIBLE | WS_CHILD| BS_TEXT,  // styles
                              // Size and position values are given explicitly, because
                              // the CW_USEDEFAULT constant gives zero values for buttons.
                              realX,         // starting x position
                              realY,         // starting y position
                              cellXsize,        // button width
                              cellYsize,        // button height
                              hWnd,       // parent window
                              NULL,       // No menu
                              (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE),
                              NULL);      // pointer not needed
        initedFields[iter->targetXY] = hwndButton;
        DrawFigureOnHwnd((HWND)initedFields[iter->targetXY], iter->targetValue );
    }

    PutPointOnInitialField();

    ClientResize(hWnd,
                 (theGame.m_GameField.xSize)*cellXsize + leftMargin,
                 (theGame.m_GameField.ySize)*cellYsize + upMargin);

    return false;
};

bool GameDrawer::DrawFigureOnHwnd(HWND hwnd, int number)
{
    WCHAR sztval[20];

    wsprintfW(sztval,L"%d", number);

    LRESULT lResult = SendMessage(    // returns LRESULT in lResult
                          hwnd,       // (HWND) handle to destination control
                          BM_SETSTYLE,     // (UINT) message ID
                          BS_TEXT,      // = () wParam;
                          (LPARAM)NULL      // = () lParam;
                      );


    SetWindowTextW(hwnd,(WCHAR *)sztval);
    return true;
}

bool GameDrawer::ProcessClickOnHWND(HWND hwnd /* of clicked button */)
{
    XYpair myXYpair; // Find(hwnd);
    std::map<XYpair, HWND>::iterator i;

    // Understand game field
    for (i=initedFields.begin(); i!=initedFields.end(); ++i)
    {
        if (i->second == hwnd)
        {
            myXYpair =i->first;
            break;
        }
    }
    // no such - not a button; return false
    if (i == initedFields.end())
    {
        return false;
    }

    DrawType currentType = theGame.what_allowed_or_new_game(myXYpair);

    if (currentType == NotAField)
    {
        MessageBeep(MB_ICONEXCLAMATION);
        return false;
    }

    // draw depending from style:
    DrawOnHwndByType(hwnd,currentType,true);

    XYpair prevXY = theGame.refresh_current(myXYpair);

    if (currentType!=PreviousTargetType)
    {
        RecalcShapeAndDrawElement(prevXY);
    }
    else
    {
        TargetsVec::iterator fnd_target;
        if (!theGame.isTarget(prevXY,fnd_target))
        {
            HWND tmpwnd = (HWND)initedFields[prevXY];
            HighliteHead(tmpwnd);
        }
    }

    if (theGame.check_if_game_done()==true)
    {
        clearRes();

        if (++theGame.m_game_round == sTargetFields1.size())
        {
            theGame.m_game_round = 0;
        }

        return ReStartRound();
    }

    return true;
};

bool GameDrawer::MoveToRoundWithCode(TCHAR *ptsz)
{
    int i;

    for (i=0; i<sTargetFields1.size() ; i++)
    {
        char psz[2049];
        wcstombs(psz, (wchar_t*)ptsz, 2049);
        std::string s = psz;
        if (sTargetFields1[i].code_==psz)
            break;
    }

    if (i!=sTargetFields1.size())
    {
        clearRes();
        theGame.GameInitNumber(i);
        drawGameField(hMainWnd);
        return true;
    }
    else
    {
        GameDrawer::ReStartRound();
    }
}

bool GameDrawer::ReStartRound()
{
    clearRes();

        const int len = 1025;
        wchar_t t[len];
        mbstowcs(t, sTargetFields1[theGame.m_game_round].code_.c_str(), len);

        MessageBox(hMainWnd,t,
        _T("Cheat code for level:"),MB_OK | MB_ICONINFORMATION);

    theGame.GameInitNumber(theGame.m_game_round);
    drawGameField(hMainWnd);
    return true;
}

bool GameDrawer::PutPointOnInitialField()
{
    HWND tmpwnd = (HWND)initedFields[theGame.m_XYcurrent];
    DrawOnHwndByType(tmpwnd,TargetType,true);
    return true;
};

// TODO hint used when we know Path were it is
bool GameDrawer::RecalcShapeAndDrawElement(const XYpair & XY)
{
    // get hwnd of element to draw there
    HWND tmpwnd = (HWND)initedFields[XY];

    // look into contest i.e.:

    // 1) find in pathes
    // may be rewrite in better stl??
    Path::iterator location;
    std::vector<Path>::iterator ip;
    for (ip = theGame.m_Pathes.begin();
            ip!=theGame.m_Pathes.end();
            ip++)
    {
        location = std::find( (*ip).begin(), (*ip).end(), XY );
        if (location!=(*ip).end())
            break;
    }

    // if it is target -  just draw target
    for (std::vector<Target>::iterator iter = theGame.m_GameField.m_Fields.begin();
            iter != theGame.m_GameField.m_Fields.end(); iter++)
    {
        if (iter->targetXY == XY )
        {
            DrawFigureOnHwnd((HWND)initedFields[XY],iter->targetValue);
            return true;
        }
    }

    XYpair prev_loc = *(location - 1);
    XYpair next_loc = *(location +1);

    DrawType aDrawType;
    // if it is horizontal
    if ((prev_loc.first > next_loc.first || prev_loc.first < next_loc.first )&& prev_loc.second == next_loc.second)
        aDrawType = LeftRight;

    if ((prev_loc.second > next_loc.second || prev_loc.second < next_loc.second )&& prev_loc.first == next_loc.first)
        aDrawType = UpDown;

    // -+
    //  |
    if (prev_loc.first < next_loc.first && prev_loc.second < next_loc.second && (*location).second == prev_loc.second)
        aDrawType = LeftDown;
    if (next_loc.first < prev_loc.first && next_loc.second < prev_loc.second && (*location).first == prev_loc.first)
        aDrawType = LeftDown;

    //   |
    //   +-
    if (prev_loc.first < next_loc.first && prev_loc.second < next_loc.second && (*location).first == prev_loc.first)
        aDrawType = UpRight;
    if (next_loc.first < prev_loc.first && next_loc.second < prev_loc.second && (*location).second == prev_loc.second)
        aDrawType = UpRight;

    //     |
    //   -+
    if (prev_loc.first > next_loc.first && prev_loc.second < next_loc.second && (*location).first == prev_loc.first)
        aDrawType = UpLeft;
    if (next_loc.first > prev_loc.first && next_loc.second < prev_loc.second &&  (*location).second == prev_loc.second )
        aDrawType = UpLeft;

    //    +-
    //    |
    if (prev_loc.first > next_loc.first && prev_loc.second < next_loc.second && (*location).second == prev_loc.second)
        aDrawType = RightDown;
    if (next_loc.first > prev_loc.first && next_loc.second < prev_loc.second && (*location).first == prev_loc.first)
        aDrawType = RightDown;

    DrawOnHwndByType(tmpwnd, aDrawType,false);
    return true;
}

bool GameDrawer::HighliteHead(HWND hmywnd)
{
    LRESULT lResult = SendMessage(
                          hmywnd,
                          BM_SETSTATE,
                          TRUE,
                          NULL
                      );

    lResult = EnableWindow(
                  hmywnd,	// handle to window
                  FALSE 	// flag for enabling or disabling input
              );

    return true;
}

bool GameDrawer::DrawOnHwndByType(HWND hwnd, DrawType currentType, bool isHead)
{
    if ( currentType== NotAField)
        return false; // not redraw

    if ( currentType== TargetType || currentType == PreviousTargetType)
        LRESULT lResult = SendMessage(    // returns LRESULT in lResult
                              hwnd,       // (HWND) handle to destination control
                              BM_SETSTATE,      // = () lParam;
                              TRUE,
                              NULL
                          );

    HBITMAP hbmp_btn =
        mGameElements[std::pair<DrawType,bool>(currentType,isHead)];

    LRESULT lResult = SendMessage(    // returns LRESULT in lResult
                          hwnd,       // (HWND) handle to destination control
                          BM_SETIMAGE,     // (UINT) message ID
                          IMAGE_BITMAP,      // = () wParam;
                          (LPARAM)hbmp_btn      // = () lParam;
                      );

    return true;
}
