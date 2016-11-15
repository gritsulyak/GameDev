// copyright (c) 2010, Roman T. Gritsulyak
#ifndef GAME_FIELDS_H_INCLUDED
#define GAME_FIELDS_H_INCLUDED
#include <vector>
#include <string>
//
typedef std::pair<int, int> XYpair;

// X,Y coords , and value - number of point to reach
struct Target
{
    XYpair targetXY;
    int     targetValue;
    Target(XYpair aXY, int iVal) { targetXY = aXY; targetValue = iVal;};
};

typedef std::vector<Target> TargetsVec;

struct GameField
{
    TargetsVec m_Fields;
int xSize;
int ySize;
std::string code_;
};

// just some game representations
// aim:
// - cover all fields.
// - from i it is possible to move into i+1
// - multiple exits from field can be
// - dead ends are possible

// init some globals
bool initializeGlobalFields();

// little field
extern std::vector<GameField> sTargetFields1;

extern std::vector<GameField> sTargetFields2;
extern std::vector<GameField> sTargetFields3;

#endif // GAME_FIELDS_H_INCLUDED
