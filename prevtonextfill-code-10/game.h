// copyright (c) 2010, Roman T. Gritsulyak
#ifndef GAME_H
#define GAME_H
#include <windows.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include "game_fields.h"
// (c) Roman Gritsulyak 2010
// contains all game and its logic
// does all game logic
extern HINSTANCE hInstance;
extern HWND hMainWnd;

// drawing element type
enum DrawType
{
    LeftRight,
    RightLeft,
    LeftDown,
    RightDown,
    UpDown,
    DownUp,
    UpRight,
    UpLeft,
    Head,
    TargetType,
    PreviousTargetType,
    NotAField,
    FinalField
};

// enum GameMode


// path - is coords sequense
typedef std::vector < XYpair > Path;

// goal:
// fill all field.
// move from previous target to next only allowed
// logic of game is implemented there:
// in MVC it is model ; Controller and and View in drawer
class Game
{
public:

    //         X   Y
    int m_game_round;
    XYpair m_XYcurrent;
    TargetsVec LastAllowedTargets;
    int PreviousTargetValue;
    // game field
    // in terms of current pathes
    std::vector<Path> m_Pathes;
    std::set<XYpair> m_Passed;
    // in terms of initial state to solve
    GameField m_GameField;

    int m_iCurPathIdx; // index of current path
    // default constructor
    Game();
    bool clean();
    bool GameInitNumber(int num);
    // purpose: init/ restore value called from Game
    bool isOnPath(XYpair aXY);
    bool isTarget(XYpair aXY,TargetsVec::iterator &fnd_target);
    // if XY push allowed for the moment?
    // purpose: check if allowed, and return corresponding value
    DrawType what_allowed_or_new_game(XYpair);
    // chacks if agme final
    bool check_if_game_done();
    // return previous value of current
    XYpair refresh_current(XYpair);
    // save functions:
    bool getGames(std::vector<std::string> & vsNames);
    bool saveGameByName(std::string sName);
    bool loadGameByName(std::string sName);
};

#endif
