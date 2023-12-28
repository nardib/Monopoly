//made by : Manuel Andretto 2074979

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player
{

public:
    bool buy_this_property() override {
        // Implement the logic for buying the property
        std::cout << "Do you want to buy this property? (yes/no): ";
        std::string answer;
        std::cin >> answer;
        return (answer == "yes");
    }

    bool upgrade_this_building() override {
        // Implement the logic for upgrading the building
        std::cout << "Do you want to upgrade the building in this cell? (yes/no): ";
        std::string answer;
        std::cin >> answer;
        return (answer == "yes");
    }
};

#endif