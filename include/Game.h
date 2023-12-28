//made by : Marco Spolverato 2032569

#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game
{
    public:
     
     //constructor
     Game(Player *pl1, Player *pl2, Player *pl3, Player *pl4, Board bo);

     //function to choose starting player
     int starting_player();

     //function to handle crossing the "go" cell
     void cross_go(Player& p);

     //function to move the player
     void move_player(Player& p, int n);

     //function to remove a defeated player's properties
     void reset_properties(int player_num);

     //function to throw two dices, or more in case they are doubles
     int throw_dices();

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