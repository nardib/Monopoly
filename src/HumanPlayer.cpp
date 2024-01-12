//made by : Manuel Andretto 2074979

#include "HumanPlayer.h"

//this function returns true if the player would buy this property
bool HumanPlayer::buy_intent() 
{
    std::string answer;
    //check if the player has enough balance to buy the property and check if the cell is not a Void or Start cell
    if(budget() >= board->get_value(get_pos_in_board()).price() && board->get_value(pos()).return_type() != (CellType::Void) && board->get_value(pos()).return_type() != (CellType::Start))
    { 
        do
        {
            std::cout << "Vuoi comprare cella " << pos() << "? (s/n): ";
            std::cin >> answer;

            std::cin.clear();                                                      //clears the error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    //skips to the next newline
        }while(answer != "s" && answer != "n" && answer != "S" && answer != "N");
                
        if(answer == "s" || answer == "S")
        {
            p_property.push_back(pos());                        //add the property to the p_property vector 
            std::sort(p_property.begin(), p_property.end());    //sort elements in ascending order
            
            return true;
        } 
    }    
    return false;
}

//this function returns true if the player wants to upgrade the building in this cell
 bool HumanPlayer::upgrade_intent() 
 {
    std::string answer;
    //check if the player has enough balance to upgrade the property
    if(budget() >= board->get_value(get_pos_in_board()).price())
    {
        do
        {
            std::cout <<"Vuoi migliorare cella " << pos() << "? (s/n): ";
            std::cin >> answer;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }while(answer != "s" && answer != "n" && answer != "S" && answer != "N");
        
        return (answer == "s" || answer == "S");
    }
    return false;
}