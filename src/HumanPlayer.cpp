//made by : Manuel Andretto 2074979

#include "HumanPlayer.h"

// Implement the logic for buying the property
bool HumanPlayer::buy_intent() {
    std::string answer;
    //Check if the player has enough balance to buy the property and check if the cell is not a Void or Start cell
    if(budget() >= get_board()->get_value(get_pos_in_board()).price() && board->get_value(pos()).return_type() != (CellType::Void) && board->get_value(pos()).return_type() != (CellType::Start)){ 
        do{
            std::cout << "Vuoi comprare cella " << pos() << "? (s/n): ";
            std::cin >> answer;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }while(answer != "s" && answer != "n" && answer != "S" && answer != "N");
                
        if(answer == "s" && answer == "S"){
            p_property.push_back(pos());
            std::sort(p_property.begin(), p_property.end());
            
            return true;
        }
    }    
    return false;
}

// Implement the logic for upgrading the building
 bool HumanPlayer::upgrade_intent() {
    std::string answer;
    if(budget() >= get_board()->get_value(get_pos_in_board()).price()){
        do{
            std::cout <<"Vuoi migliorare cella " << pos() << "? (s/n): ";
            std::cin >> answer;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }while(answer != "s" && answer != "n" && answer != "S" && answer != "N");

        return (answer == "s" && answer == "S");
    }
    return false;
}