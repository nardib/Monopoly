//made by : Manuel Andretto 2074979

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player
{

public:

    HumanPlayer (int n, Board b):Player(n, b){}
    
    bool buy_this_property() override;

    bool upgrade_this_building() override;
};

#endif