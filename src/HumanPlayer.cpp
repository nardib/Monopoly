//made by : Manuel Andretto 2074979

#include "HumanPlayer.h"

bool HumanPlayer::buy_intent() {
        // Implement the logic for buying the property
        std::string answer;
        if(budget() >= get_board()->get_value(get_pos_in_board()).price()){ 
        do{
            std::cout << "Vuoi comprare cella " << pos() << "? (s/n): ";
            std::cin >> answer;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }while(answer != "s" && answer != "n");
        
        return (answer == "s");
        }
        return false;
        
        p_owned_cells.push_back(pos());
        std::sort(p_owned_cells.begin(), p_owned_cells.end());
}

 bool HumanPlayer::upgrade_intent() {
        // Implement the logic for upgrading the building
        std::string answer;
        if(budget() >= get_board()->get_value(get_pos_in_board()).price()){
        do{
            std::cout <<"Vuoi migliorare cella " << pos() << "? (s/n): ";
            std::cin >> answer;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }while(answer != "s" && answer != "n");

        return (answer == "s");
        }
        return false;
}