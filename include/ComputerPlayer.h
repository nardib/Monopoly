//made by : Manuel Andretto 2074979

#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player
{

public:

    //default constructor
    ComputerPlayer (int n, Board b):Player(n, b){}
    
    //function that decides whether the computer buys the property 
    bool buy_intent() override;

    //function that decides whether the computer upgrade the property
    bool upgrade_intent() override;
    
};

#endif