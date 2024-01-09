//made by : Manuel Andretto 2074979

#include "ComputerPlayer.h"

// Implement the logic for buying the property, this function will return true with a probability of 25%
bool ComputerPlayer::buy_intent() {
       int rnd = random(1, 4);
       //Check if the player has enough balance to buy the property and check if the cell is not a Void or Start cell
       if(rnd == 1 && board->get_value(pos()).return_type() != (CellType::Void) && board->get_value(pos()).return_type() != (CellType::Start)) {
              p_property.push_back(pos());
              std::sort(p_property.begin(), p_property.end());
              return true;
       }
       return false;
}

// Implement the logic for upgrading the building, this function will return true with a probability of 25%
 bool ComputerPlayer::upgrade_intent() {
       int rnd = random(1, 4); 
       return (rnd == 1);
 }

