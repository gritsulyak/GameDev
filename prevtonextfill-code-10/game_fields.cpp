// copyright (c) 2010, Roman T. Gritsulyak
#include "windows.h"
#include "game_fields.h"

// put to class
// little field dimension
std::vector<GameField> sTargetFields1;

// TODO ; unused for the moment; for another dimensions
std::vector<GameField> sTargetFields2;

// TODO ; unused for the moment; for another dimensions
std::vector<GameField> sTargetFields3;

// initialize vector of games
bool initializeGlobalFields()
{
    {
        //1
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(3,3), 0));
        curTarget.m_Fields.push_back(Target(XYpair(0,0), 1));
        curTarget.m_Fields.push_back(Target(XYpair(1,2), 2));
        curTarget.m_Fields.push_back(Target(XYpair(2,2), 3));
        curTarget.m_Fields.push_back(Target(XYpair(2,0), 4));
        curTarget.m_Fields.push_back(Target(XYpair(3,1), 5));
        curTarget.xSize = 4;
        curTarget.ySize = 4;
        curTarget.code_= "OPAPA";
        sTargetFields1.push_back(curTarget);
    }

    {
        //2
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(0,3), 0));
        curTarget.m_Fields.push_back(Target(XYpair(0,1), 1));
        curTarget.m_Fields.push_back(Target(XYpair(2,3), 1));
        curTarget.m_Fields.push_back(Target(XYpair(0,0), 2));
        curTarget.m_Fields.push_back(Target(XYpair(1,2), 2));
        curTarget.m_Fields.push_back(Target(XYpair(3,1), 2));
        curTarget.m_Fields.push_back(Target(XYpair(3,2), 3));
        curTarget.m_Fields.push_back(Target(XYpair(3,0), 3));
        curTarget.xSize = 4;
        curTarget.ySize = 4;
        curTarget.code_ = "COOL";
        sTargetFields1.push_back(curTarget);
    }

    {
        //3
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(1,1), 0));
        curTarget.m_Fields.push_back(Target(XYpair(3,1), 1));
        curTarget.m_Fields.push_back(Target(XYpair(0,3), 1));
        curTarget.m_Fields.push_back(Target(XYpair(3,0), 2));
        curTarget.m_Fields.push_back(Target(XYpair(0,1), 2));
        curTarget.m_Fields.push_back(Target(XYpair(2,0), 3));
        curTarget.m_Fields.push_back(Target(XYpair(1,0), 4));
        curTarget.xSize = 4;
        curTarget.ySize = 4;
        curTarget.code_ = "SIMPLE";
        sTargetFields1.push_back(curTarget);
    }

    {
        //4
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(1,0), 0));
        curTarget.m_Fields.push_back(Target(XYpair(2,0), 1));
        curTarget.m_Fields.push_back(Target(XYpair(0,1), 1));
        curTarget.m_Fields.push_back(Target(XYpair(2,1), 2));
        curTarget.m_Fields.push_back(Target(XYpair(3,1), 2));
        curTarget.m_Fields.push_back(Target(XYpair(1,3), 2));
        curTarget.m_Fields.push_back(Target(XYpair(2,2), 2));
        curTarget.m_Fields.push_back(Target(XYpair(2,3), 3));
        curTarget.m_Fields.push_back(Target(XYpair(3,3), 3));
        curTarget.xSize = 4;
        curTarget.ySize = 4;
        curTarget.code_ = "ALOT";
        sTargetFields1.push_back(curTarget);
    }

    {
        //5
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(0,0),0 ));
        curTarget.m_Fields.push_back(Target(XYpair(0,2),1 ));
        curTarget.m_Fields.push_back(Target(XYpair(1,1),3 ));
        curTarget.m_Fields.push_back(Target(XYpair(1,2),2 ));
        curTarget.m_Fields.push_back(Target(XYpair(2,0),1 ));
        curTarget.m_Fields.push_back(Target(XYpair(2,1),2 ));
        curTarget.m_Fields.push_back(Target(XYpair(2,2),3 ));
        curTarget.m_Fields.push_back(Target(XYpair(3,0),2 ));
        curTarget.xSize = 4;
        curTarget.ySize = 4;
        curTarget.code_ = "SAME";
        sTargetFields1.push_back(curTarget);
    }

    {
        //6
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(0,1),4 ));
        curTarget.m_Fields.push_back(Target(XYpair(0,2),2 ));
        curTarget.m_Fields.push_back(Target(XYpair(1,0),3 ));
        curTarget.m_Fields.push_back(Target(XYpair(1,2),0 ));
        curTarget.m_Fields.push_back(Target(XYpair(1,3),1 ));
        curTarget.m_Fields.push_back(Target(XYpair(2,1),2 ));
        curTarget.m_Fields.push_back(Target(XYpair(3,0),1 ));
        curTarget.xSize = 4;
        curTarget.ySize = 4;
        curTarget.code_ = "AGAIN";
        sTargetFields1.push_back(curTarget);
    }

    {
        //7
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(1,1),3 ));
        curTarget.m_Fields.push_back(Target(XYpair(1,2),4 ));
        curTarget.m_Fields.push_back(Target(XYpair(2,1),2 ));
        curTarget.m_Fields.push_back(Target(XYpair(2,2),3 ));
        curTarget.m_Fields.push_back(Target(XYpair(3,0),1 ));
        curTarget.m_Fields.push_back(Target(XYpair(3,1),1 ));
        curTarget.m_Fields.push_back(Target(XYpair(3,3),0 ));
        curTarget.xSize = 4;
        curTarget.ySize = 4;
        curTarget.code_ = "RIGHT";
        sTargetFields1.push_back(curTarget);
    }

    {
        //8
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(0,1),0 ));
        curTarget.m_Fields.push_back(Target(XYpair(1,0),1 ));
        curTarget.m_Fields.push_back(Target(XYpair(1,1),2 ));
        curTarget.m_Fields.push_back(Target(XYpair(1,2),3 ));
        curTarget.m_Fields.push_back(Target(XYpair(2,0),2 ));
        curTarget.m_Fields.push_back(Target(XYpair(2,1),1 ));
        curTarget.m_Fields.push_back(Target(XYpair(3,0),3 ));
        curTarget.m_Fields.push_back(Target(XYpair(3,1),2 ));
        curTarget.m_Fields.push_back(Target(XYpair(3,3),3 ));
        curTarget.xSize = 4;
        curTarget.ySize = 4;
        curTarget.code_ = "BORING";
        sTargetFields1.push_back(curTarget);
    }

    {
        //9
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(3,3), 0));
        curTarget.m_Fields.push_back(Target(XYpair(3,1), 1));
        curTarget.m_Fields.push_back(Target(XYpair(0,0), 2));
        curTarget.m_Fields.push_back(Target(XYpair(1,3), 3));
        curTarget.m_Fields.push_back(Target(XYpair(1,1), 4));
        curTarget.xSize = 4;
        curTarget.ySize = 4;
        curTarget.code_ = "MINI";
        sTargetFields1.push_back(curTarget);
    }
    {
        //10
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(0,0), 0 ));
        curTarget.m_Fields.push_back(Target (XYpair(1,2), 1));
        curTarget.m_Fields.push_back(Target(XYpair(2,1), 2));
        curTarget.m_Fields.push_back(Target(XYpair(2,3), 3));
        curTarget.m_Fields.push_back(Target (XYpair(2,0), 3));
        curTarget.xSize = 4;
        curTarget.ySize = 4;
        curTarget.code_ = "TOME";
        sTargetFields1.push_back(curTarget);
    }

    {
        //11
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(0,0), 0));
        curTarget.m_Fields.push_back(Target(XYpair(1,1), 1));
        curTarget.m_Fields.push_back(Target(XYpair(4,4), 2));
        curTarget.m_Fields.push_back(Target(XYpair(2,2), 2));
        curTarget.m_Fields.push_back(Target(XYpair(2,4), 3));
        curTarget.xSize = 5;
        curTarget.ySize = 5;
        curTarget.code_ = "INCREASE";
        sTargetFields1.push_back(curTarget);
    }

    {
        //12
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(0,0), 0));
        curTarget.m_Fields.push_back(Target(XYpair(2,2), 1));
        curTarget.m_Fields.push_back(Target(XYpair(2,4), 2));
        curTarget.m_Fields.push_back(Target(XYpair(1,1), 2));
        curTarget.m_Fields.push_back(Target(XYpair(1,3), 3));
        curTarget.xSize = 5;
        curTarget.ySize = 5;
        curTarget.code_ = "PUSH";
        sTargetFields1.push_back(curTarget);
    }

    {
        //13
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(2,2), 0));
        curTarget.m_Fields.push_back(Target(XYpair(0,0), 1));
        curTarget.m_Fields.push_back(Target(XYpair(0,4), 1));
        curTarget.m_Fields.push_back(Target(XYpair(4,0), 1));
        curTarget.m_Fields.push_back(Target(XYpair(4,4), 1));
        curTarget.m_Fields.push_back(Target(XYpair(4,1), 2));
        curTarget.m_Fields.push_back(Target(XYpair(0,2), 2));
        curTarget.m_Fields.push_back(Target(XYpair(0,1), 3));
        curTarget.m_Fields.push_back(Target(XYpair(4,3), 3));
        curTarget.m_Fields.push_back(Target(XYpair(3,3), 4));

        curTarget.xSize = 5;
        curTarget.ySize = 5;
        curTarget.code_ = "CLICK";
        sTargetFields1.push_back(curTarget);
    }

    {
        //14
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(1,1), 0));
        curTarget.m_Fields.push_back(Target(XYpair(0,4), 1));
        curTarget.m_Fields.push_back(Target(XYpair(2,2), 1));
        curTarget.m_Fields.push_back(Target(XYpair(4,4), 1));
        curTarget.xSize = 5;
        curTarget.ySize = 5;
        curTarget.code_ = "BACK";
        sTargetFields1.push_back(curTarget);
    }

    {
        //15
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(4,4), 0));
        curTarget.m_Fields.push_back(Target(XYpair(1,1), 1));
        curTarget.m_Fields.push_back(Target(XYpair(4,2), 1));
        curTarget.xSize = 5;
        curTarget.ySize = 5;
        curTarget.code_ = "GEEK";
        sTargetFields1.push_back(curTarget);
    }

    {
        //16
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(2,0), 0));
        curTarget.m_Fields.push_back(Target(XYpair(1,1), 2));
        curTarget.m_Fields.push_back(Target(XYpair(0,3), 1));
        curTarget.m_Fields.push_back(Target(XYpair(3,1), 1));
        curTarget.m_Fields.push_back(Target(XYpair(1,3), 3));
        curTarget.m_Fields.push_back(Target(XYpair(4,4), 2));
        curTarget.xSize = 5;
        curTarget.ySize = 5;
        curTarget.code_ = "NOTENDACTUALLY";
        sTargetFields1.push_back(curTarget);
    }

    {
        //17
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(2,0), 4));
        curTarget.m_Fields.push_back(Target(XYpair(1,1), 5));
        curTarget.m_Fields.push_back(Target(XYpair(4,1), 5));
        curTarget.m_Fields.push_back(Target(XYpair(0,2), 1));
        curTarget.m_Fields.push_back(Target(XYpair(3,2), 3));
        curTarget.m_Fields.push_back(Target(XYpair(1,3), 0));
        curTarget.m_Fields.push_back(Target(XYpair(2,3), 2));
        curTarget.m_Fields.push_back(Target(XYpair(0,4), 2));
        curTarget.m_Fields.push_back(Target(XYpair(2,4), 1));
        curTarget.m_Fields.push_back(Target(XYpair(3,4), 4));
        curTarget.xSize = 5;
        curTarget.ySize = 5;
        curTarget.code_ = "TWOFIVES";
        sTargetFields1.push_back(curTarget);
    }

    // $ python level_to_code.py < levels.txt
    // levels_a
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 0 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 1 , 1 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 1 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 1 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 1 , 2 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 2 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 2 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 3 ),  0 ));
        curTarget.xSize = 5 ;
        curTarget.ySize = 4 ;
        curTarget.code_="ADDITION";
        sTargetFields1.push_back(curTarget);
    }
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 0 ),  5 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 1 , 1 ),  4 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 1 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 1 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 2 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 3 ),  0 ));
        curTarget.xSize = 5 ;
        curTarget.ySize = 4 ;
        curTarget.code_="AGAINAGAIN";
        sTargetFields1.push_back(curTarget);
    }
    // levels_b
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 1 , 0 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 0 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 4 , 0 ),  4 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 5 , 0 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 1 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 1 ),  0 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 4 , 1 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 1 , 2 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 2 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 4 , 2 ),  4 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 5 , 2 ),  3 ));
        curTarget.xSize = 7 ;
        curTarget.ySize = 3 ;
        curTarget.code_="RECTANGLE";
        sTargetFields1.push_back(curTarget);
    }
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 0 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 4 , 0 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 0 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 1 , 1 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 1 ),  0 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 5 , 1 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 2 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 2 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 2 ),  3 ));
        curTarget.xSize = 7 ;
        curTarget.ySize = 3 ;
        curTarget.code_="ISEASY";
        sTargetFields1.push_back(curTarget);
    }
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 0 ),  0 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 0 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 1 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 2 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 2 ),  2 ));
        curTarget.xSize = 7 ;
        curTarget.ySize = 3 ;
        curTarget.code_="TRYNOW";
        sTargetFields1.push_back(curTarget);
    }
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 0 ),  0 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 0 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 0 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 2 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 2 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 2 ),  4 ));
        curTarget.xSize = 7 ;
        curTarget.ySize = 3 ;
        curTarget.code_="PROFITABLE";
        sTargetFields1.push_back(curTarget);
    }
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 1 , 1 ),  0 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 1 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 4 , 1 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 5 , 1 ),  3 ));
        curTarget.xSize = 7 ;
        curTarget.ySize = 3 ;
        curTarget.code_="BANANA";
        sTargetFields1.push_back(curTarget);
    }
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 0 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 1 , 0 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 0 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 0 ),  4 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 2 ),  0 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 4 , 2 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 5 , 2 ),  4 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 2 ),  5 ));
        curTarget.xSize = 7 ;
        curTarget.ySize = 3 ;
        curTarget.code_="REDAPPLE";
        sTargetFields1.push_back(curTarget);
    }
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 0 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 0 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 1 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 1 ),  0 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 4 , 1 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 5 , 1 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 2 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 2 ),  3 ));
        curTarget.xSize = 7 ;
        curTarget.ySize = 3 ;
        curTarget.code_="BLUECROCO";
        sTargetFields1.push_back(curTarget);
    }
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 0 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 1 , 1 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 1 ),  0 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 5 , 1 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 2 ),  1 ));
        curTarget.xSize = 7 ;
        curTarget.ySize = 3 ;
        curTarget.code_="YELLOWGORILLA";
        sTargetFields1.push_back(curTarget);
    }
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 0 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 0 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 1 , 1 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 1 ),  4 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 5 , 1 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 0 , 2 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 2 ),  0 ));
        curTarget.xSize = 7 ;
        curTarget.ySize = 3 ;
        curTarget.code_="VIOLETCAT";
        sTargetFields1.push_back(curTarget);
    }
    {
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 0 ),  4 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 0 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 4 , 0 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 1 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 3 , 1 ),  2 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 4 , 1 ),  1 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 1 ),  0 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 2 , 2 ),  3 ));
        curTarget.m_Fields.push_back(Target(XYpair ( 6 , 2 ),  2 ));
        curTarget.xSize = 7 ;
        curTarget.ySize = 3 ;
        curTarget.code_="FLOWERS";
        sTargetFields1.push_back(curTarget);
    }

    {
        //END
        GameField curTarget;
        curTarget.m_Fields.push_back(Target(XYpair(0,0), 88));
        curTarget.m_Fields.push_back(Target(XYpair(0,1),88));
        curTarget.m_Fields.push_back(Target(XYpair(0,2),88));
        curTarget.m_Fields.push_back(Target(XYpair(0,3),88));
        curTarget.m_Fields.push_back(Target(XYpair(0,4),88));
        curTarget.m_Fields.push_back(Target(XYpair(1,0),88));
        curTarget.m_Fields.push_back(Target(XYpair(1,2),88));
        curTarget.m_Fields.push_back(Target(XYpair(1,4),88));
        curTarget.m_Fields.push_back(Target(XYpair(2,0),88));
        curTarget.m_Fields.push_back(Target(XYpair(2,4),88));
        curTarget.m_Fields.push_back(Target(XYpair(4,0),88));
        curTarget.m_Fields.push_back(Target(XYpair(4,1),88));
        curTarget.m_Fields.push_back(Target(XYpair(4,2),88));
        curTarget.m_Fields.push_back(Target(XYpair(4,3),88));
        curTarget.m_Fields.push_back(Target(XYpair(4,4),88));
        curTarget.m_Fields.push_back(Target(XYpair(5,1),88));
        curTarget.m_Fields.push_back(Target(XYpair(6,2),88));
        curTarget.m_Fields.push_back(Target(XYpair(7,0),88));
        curTarget.m_Fields.push_back(Target(XYpair(7,1),88));
        curTarget.m_Fields.push_back(Target(XYpair(7,2),88));
        curTarget.m_Fields.push_back(Target(XYpair(7,3),88));
        curTarget.m_Fields.push_back(Target(XYpair(7,4),88));
        curTarget.m_Fields.push_back(Target(XYpair(9,0),88));
        curTarget.m_Fields.push_back(Target(XYpair(9,1),88));
        curTarget.m_Fields.push_back(Target(XYpair(9,2),88));
        curTarget.m_Fields.push_back(Target(XYpair(9,3),88));
        curTarget.m_Fields.push_back(Target(XYpair(9,4),88));
        curTarget.m_Fields.push_back(Target(XYpair(10,0),88));
        curTarget.m_Fields.push_back(Target(XYpair(10,4),88));
        curTarget.m_Fields.push_back(Target(XYpair(11,1),88));
        curTarget.m_Fields.push_back(Target(XYpair(11,2),88));
        curTarget.m_Fields.push_back(Target(XYpair(11,3),88));
        curTarget.code_ = "NEXTSTAGE";
        curTarget.xSize = 12;
        curTarget.ySize = 5;
        sTargetFields1.push_back(curTarget);
    }


    return true;
}

