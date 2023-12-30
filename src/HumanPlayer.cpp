//made by : Manuel Andretto 2074979

#include "HumanPlayer.h"

bool HumanPlayer::buy_intent() {
        // Implement the logic for buying the property
        std::string answer;
        do{
            std::cout << "Do you want to buy this property? (s/n): ";
            std::cin >> answer;

            std::cin.clear();
            fflush(stdin);
        }while(answer != "s" && answer != "n");
        
        return (answer == "s");
}

 bool HumanPlayer::upgrade_intent() {
        // Implement the logic for upgrading the building
        std::string answer;
        do{
            std::cout << "Do you want to upgrade the building in this cell? (s/n): ";
            std::cin >> answer;

            std::cin.clear();
            fflush(stdin);
        }while(answer != "s" && answer != "n");

        return (answer == "s");
}