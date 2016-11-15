// copyright (c) 2010, Roman T. Gritsulyak
#ifndef GAMEDRAWER_H_INCLUDED
#define GAMEDRAWER_H_INCLUDED
#include "game.h"

#define _T TEXT
// Drawing:
// functions related to representing
// game on forms and event receiver.
class GameDrawer
{
private:
    bool initTypeDrawMatrix();
    // drawing related info bool - isHead // TODO refactor to using this structure
    typedef std::map<std::pair<DrawType,bool> , HBITMAP> PicturesForElement;
    PicturesForElement mGameElements;
private:
    int upMargin;
    int leftMargin;
    int cellXsize;
    int cellYsize;
public:
    bool dump_Field(std::wstring & s_field);
	std::map< XYpair, HWND > initedFields;
	Game theGame;
    GameDrawer();
    ~GameDrawer();
    void clearRes();
    bool MoveToRoundWithCode(TCHAR * sbuffer);
	bool ReStartRound();
	bool drawGameField(HWND hWnd);
	bool PutPointOnInitialField();
	bool HighliteHead(HWND hwnd);
    bool DrawOnHwndByType(HWND hButton, DrawType atype, bool isHead = true);
    bool RecalcShapeAndDrawElement(const XYpair & XY); // view processer
    bool ProcessClickOnHWND(HWND hwnd); // Controller
private:
    bool DrawFigureOnHwnd(HWND hwnd, int number);
};


#endif // GAMEDRAWER_H_INCLUDED
