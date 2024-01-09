//made by : Manuel Andretto 2074979

#include "ComputerPlayer.h"

bool ComputerPlayer::buy_intent() {
        // Implement the logic for buying the property, this function will return true with a probability of 25%
        int rnd = random(1, 4);
		if(rnd == 1 && board->get_value(pos()).return_type() != (CellType::Void) && board->get_value(pos()).return_type() != (CellType::Start)){
            p_property.push_back(pos());
            std::sort(p_property.begin(), p_property.end());
            
            return true;
        }
        
        return false;
}

 bool ComputerPlayer::upgrade_intent() {
        // Implement the logic for upgrading the building, this function will return true with a probability of 25%
        int rnd = random(1, 4);
        
        return (rnd == 1);
 }

