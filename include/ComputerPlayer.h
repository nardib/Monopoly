//made by : Manuel Andretto 2074979

#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player
{

public:
    bool buy_this_property() override;

    bool upgrade_this_building() override;
};

#endif