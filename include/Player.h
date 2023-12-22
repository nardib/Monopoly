//made by : Lorenzo Nardin 2066609

#ifndef PLAYER_H
#define PLAYER_H

#include <stdexcept>
#include "Board.h"

class Player
{
public:

	//these functions return the values of the member variables
	int budget() {return balance;}
	int num() {return player_num;}
	int pos() {return player_pos;}

	//move this player in the board
	void move(int n);

	//get pos in the board; return the index in the array of the board
	//it does a linear search in the array and memorize that value in a variable
	int get_pos_in_board();

	//copy construcor and assignment disabled
	Player (const Player&) = delete;
	Player& operator= (const Player&) = delete;

protected:

	//default constructor
	Player () : balance {100}, player_num {0}, player_pos {0} {}
	//constructor with the number of the player
	Player (int num) : balance {100}, player_num {num}, player_pos {0} {if(player_num < 1 || player_num > 4) throw std::invalid_argument("Number of player must be between 1 and 4");}

private:

	//amount of money this player has; number of player; player position in the board
	int balance, player_num, player_pos;

};

#endif