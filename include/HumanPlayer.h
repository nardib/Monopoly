//made by : Manuel Andretto 2074979

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player
{
public:

    //default constructor
    HumanPlayer (int n, Board* b):Player(n, b){}
    
    //overrided virtual functions  
    bool buy_intent() override;         //function that checks if you want to buy the property 
    bool upgrade_intent() override;     //function that checks if you want to upgrade the building
};

#endif