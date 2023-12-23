//made by : Lorenzo Nardin 2066609

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player
{
public:

	//these functions return the values of the member variables
	int budget() const {return balance;}
	int num() const {return player_num;}
	int pos() const {return player_pos;}
	int last_dice() const {return last_dice_throw;}

	//move this player in the board n positions forward
	void move(int n, Board b);

	//get pos in the board; return the index in the array of the board
	//it does a linear search in the array and memorize that value in a variable
	int get_pos_in_board(Board b) const;

	//function to throw two dices (and a third if the two previous results are the same)
	int throw_dices();

	//copy construcor and assignment disabled
	Player (const Player&) = delete;
	Player& operator= (const Player&) = delete;

protected:

	//default constructor
	Player () : balance {100}, player_num {0}, player_pos {0}, last_dice_throw {0} {}
	//constructor with the number of the player
	Player (int num) : balance {100}, player_num {num}, player_pos {0}, last_dice_throw {0} {if(player_num < 1 || player_num > 4) throw std::invalid_argument("Number of player must be between 1 and 4");}

private:

	//amount of money this player has; number of player; player position in the board
	int balance, player_num, player_pos, last_dice_throw;

};

#endif