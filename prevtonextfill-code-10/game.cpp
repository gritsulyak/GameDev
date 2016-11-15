// copyright (c) 2010, Roman T. Gritsulyak
#include "stdafx.h"
#include "game.h"
#include "game_fields.h"
#include <algorithm>

Game::Game()
{
    GameInitNumber(0);
};

bool Game::clean()
{
    m_Passed.clear();
    m_Pathes.clear();
    LastAllowedTargets.clear();
    return true;
}

bool Game::GameInitNumber(int num)
{
    m_game_round = num;
    m_GameField = sTargetFields1[num];


    for(TargetsVec::iterator i=m_GameField.m_Fields.begin(); i!=m_GameField.m_Fields.end();i++)
    {
        if(i->targetValue==0)
        {
        m_XYcurrent=i->targetXY;
        break;
        }
    }

    m_iCurPathIdx=0;
    PreviousTargetValue = 0;

    // initialize basic point in path
    Path aPath;
    aPath.push_back(m_XYcurrent);
    m_Pathes.push_back(aPath);
    m_Passed.insert(m_XYcurrent);
    LastAllowedTargets.push_back(Target(m_XYcurrent,PreviousTargetValue));

	return true;
}

bool Game::isTarget(XYpair aXY,TargetsVec::iterator &fnd_target)
{
    bool isTargetField = false;
    for(fnd_target=m_GameField.m_Fields.begin();
    fnd_target!=m_GameField.m_Fields.end(); fnd_target++)
    {
        if(fnd_target->targetXY == aXY)
            {
                isTargetField = true;
                break;
            }
    };

    return isTargetField;
}

bool Game::isOnPath(XYpair aXY)
{
    // TODO : fix processing
    // if already passed? already in path
    Path::iterator location;
    std::vector<Path>::iterator ip;

    bool isInPathes = false;
    for (ip = m_Pathes.begin();
            ip!=m_Pathes.end();
            ip++)
    {
        location = std::find( ip->begin(), ip->end(), aXY );
        if (location!=ip->end())
            {
            isInPathes = true;
            break;
            }
    }
    return isInPathes;
}

// if XY push allowed for the moment?
// purpose:  if allowed, and return corresponding value
DrawType Game::what_allowed_or_new_game(XYpair aXY)
{
    TargetsVec::iterator fnd_target;
    TargetsVec::iterator fnd_target_prev;
    bool isInPathes = isOnPath(aXY);
    bool isTargetField = isTarget(aXY,fnd_target);
    bool isCurrentTarget = isTarget(m_XYcurrent,fnd_target_prev);

     // 13.05.2010 fix. No frozen heads.
    if (isInPathes && isTargetField && isCurrentTarget)
      {
         PreviousTargetValue=fnd_target->targetValue;
            return PreviousTargetType;
      }

    if (isInPathes && isTargetField && !isCurrentTarget)
      {
         return NotAField;
      }

    if (isInPathes && ! isTargetField)
      {
            return NotAField;
      }

    if (! isInPathes && isTargetField) // unfilled target
    {
         if ( (m_XYcurrent.first == aXY.first && m_XYcurrent.second == aXY.second - 1 ) ||
              (m_XYcurrent.first == aXY.first && m_XYcurrent.second == aXY.second + 1 ) ||
              (m_XYcurrent.first == aXY.first - 1 && m_XYcurrent.second == aXY.second ) ||
              (m_XYcurrent.first == aXY.first + 1 && m_XYcurrent.second == aXY.second ) )
        {
            // TODO move to vector of previous processing for clarity
            if(PreviousTargetValue == fnd_target->targetValue-1) // it is Possible only move from previous to next
            {
                PreviousTargetValue++;
                LastAllowedTargets.push_back(*fnd_target);
                return TargetType;
            }
            else
                return NotAField; // not allowed yet target
        }
    }

    // is UpDown?
    if (m_XYcurrent.first == aXY.first && m_XYcurrent.second == aXY.second - 1 )
        return UpDown;

    if (m_XYcurrent.first == aXY.first && m_XYcurrent.second == aXY.second + 1 )
        return DownUp;

    // is LeftRight?
    if (m_XYcurrent.first == aXY.first - 1 && m_XYcurrent.second == aXY.second )
        return LeftRight;

    if (m_XYcurrent.first == aXY.first + 1 && m_XYcurrent.second == aXY.second )
        return RightLeft;

    return NotAField;
}

XYpair Game::refresh_current(XYpair aXY)
{
    XYpair XYprev = m_XYcurrent;
    m_XYcurrent = aXY;

    m_Pathes[0].push_back(aXY);
    m_Passed.insert(aXY);
    return XYprev;
};

bool Game::check_if_game_done()
{
    if(m_Passed.size()== m_GameField.xSize*m_GameField.ySize )
        		{
                    return true;
        		}
    return false;
}

bool Game::getGames(std::vector<std::string> & vsNames)
{
    return false;
};

bool Game::saveGameByName(std::string sName)
{
    return false;
};

bool Game::loadGameByName(std::string sName)
{
    return false;
};


