//made by : Manuel Andretto 2074979

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player
{

public:
    bool buy_this_property() override;

    bool upgrade_this_building() override;
};


#endif