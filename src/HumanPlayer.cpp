//made by : 

#include "HumanPlayer.h"

bool HumanPlayer::buy_this_property() {
        // Implement the logic for buying the property
        std::string answer;
        do{
            std::cout << "Do you want to buy this property? (yes/no): ";
            std::cin >> answer;

            std::cin.clear();
            fflush(stdin);

            return (answer == "yes");
        }while(answer != "yes" && answer != "no");
}

 bool HumanPlayer::upgrade_this_building() {
        // Implement the logic for upgrading the building
        std::string answer;
        do{
            std::cout << "Do you want to upgrade the building in this cell? (yes/no): ";
            std::cin >> answer;

            std::cin.clear();
            fflush(stdin);
        
            return (answer == "yes");
        }while(answer != "yes" && answer != "no");
}