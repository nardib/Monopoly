//made by : Manuel Andretto 2074979

#include "ComputerPlayer.h"

//returns true if the computer would buy this property
bool ComputerPlayer::buy_intent() 
{
       int rnd = random(1, 4);
       //first check if the cell is not a Void or Start cell, than return true with a probability of 25%
       if(rnd == 1 && board->get_value(pos()).return_type() != (CellType::Void) && board->get_value(pos()).return_type() != (CellType::Start)) 
       {
              p_property.push_back(pos());                        //add the property to the p_property vector   
              std::sort(p_property.begin(), p_property.end());    //sort elements in ascending order
              
              return true; 
       }
       return false;
}

//returns true if the computer wants to upgrade the building in this cell
 bool ComputerPlayer::upgrade_intent() 
 {
       int rnd = random(1, 4); 
      
      return (rnd == 1);    //this function will return true with a probability of 25%
 }

