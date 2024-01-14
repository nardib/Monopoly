//made by : Marco Spolverato 2032569

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <map>
#include <fstream>

class Game
{
    public:
     
     //Constructor
     //the number of turns is the number given as argument * 4 (one turn for every player)
     Game(Player *pl1, Player *pl2, Player *pl3, Player *pl4, Board *bo, int turns):p1{pl1},p2{pl2},p3{pl3},p4{pl4},b{bo},turn_limit{turns*4},out{"../Logs/Log.txt"}{};

     //Function to determine the order of players
     std::vector<int> player_order();

     std::vector<int> check_tie(const std::vector<std::pair<int, int>>& players);

     //Function to handle crossing the "go" cell
     void cross_go(Player* p);

     //Function to move the player
     void move_player(Player* p, int n);

     //Function to remove a defeated player's properties
     void reset_properties(Player* p);

     //Function to buy a terrain
     bool buy_terrain(Player* p);

     //Function to upgrade a building
     bool upgrade(Player* p);

     //Function to return a player object from its number
     Player* return_player(int n);

     //Function to pay the stay at another player's property
     bool pay_stay(Player* p);

     //Function to throw two dices
     std::pair<int, int> throw_dices();

     //Function to check if the dices are equal
     bool check_dices();

    //Function to play the game
     void game();

     private:
     
     //The board on which the game is played
     Board *b;
     //The 4 players of the game
     Player *p1;
     Player *p2;
     Player *p3;
     Player *p4;
     //The number of turns
     int turn_limit;
     //The dices
     int dice1;
     int dice2;
     //The log file
     std::ofstream out;
}; 

//function to throw a single dice
int throw_dice(int max)
{
    return random(1, 6);
}

#endif
