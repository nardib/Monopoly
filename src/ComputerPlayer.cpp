//made by : Manuel Andretto 2074979

#include "ComputerPlayer.h"

bool ComputerPlayer::buy_this_property() {
        // Implement the logic for buying the property, this function will return true with a probability of 25%
        srand(time(0)); 
        int randNum = rand() % 4 + 1;
        
        return (randNum == 1);
}

 bool ComputerPlayer::upgrade_this_building() {
        // Implement the logic for upgrading the building, this function will return true with a probability of 25%
        srand(time(0));
        int randNum = rand() % 4 + 1;
        
        return (randNum == 1);
 }
