//made by : Marco Spolverato 2032569

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <algorithm>
#include <vector>

class Game
{
    public:
     
     //constructor
     Game(Player *pl1, Player *pl2, Player *pl3, Player *pl4, Board bo);

     Game(HumanPlayer& pl1, ComputerPlayer& pl2, ComputerPlayer& pl3, ComputerPlayer& pl4, Board bo):p1{&pl1},p2{&pl2},p3{&pl3},p4{&pl4},b{bo}{}

     //function to choose starting player
     std::vector<int> player_order();

     //function to handle crossing the "go" cell
     void cross_go(Player& p);

     //function to move the player
     void move_player(Player* p, int n);

     //function to remove a defeated player's properties
     void reset_properties(Player& p);

     //function to buy a terrain
     void buy_terrain(Player& p);

     //function to upgrade a building
     void upgrade(Player& p);

     //
     Player* return_player(int n);

     //function to pay the stay at another player's property
     bool pay_stay(Player& p);

     //function to throw two dices, or more in case they are doubles
     std::pair<int, int> throw_dices();

     //function to check if the dices are equal
     bool check_dices();

     void game();

     private:
     
     Board b;
     Player *p1;
     Player *p2;
     Player *p3;
     Player *p4;
     int dice1;
     int dice2;
}; 

//function to throw a dice
int throw_dice(int max)
  {
     return(rand() % max) + 1;
  }

#endif