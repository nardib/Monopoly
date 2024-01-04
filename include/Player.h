//made by : Lorenzo Nardin 2066609

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player
{
public:

	class NotEnoughMoney : public std::runtime_error 
	{
	public:  NotEnoughMoney(const std::string& message): std::runtime_error(message) {}
	};

	//these functions return the values of the member variables
	int budget() const {return balance;}
	int num() const {return player_num;}
	int pos() const {return player_pos;}
	bool is_playing() const {return playing;}

	//move this player in the board n positions forward
	void move(int n);

	//get pos in the board; return the index in the array of the board
	//it does a linear search in the array and memorize that value in a variable
	int get_pos_in_board();

	//functions to modify the balance
	void decrease_balance (int n);
	void increase_balance (int n);

	//i change the value of this player to false; once it turns to false, it can't become true anymore
	void end_game() {playing = false;}

	//virtual functions that must be overrided (they )
	virtual bool buy_intent() = 0;	//this function returns true if the player would buy this property
	virtual bool upgrade_intent() = 0;	//this function returns true if the player wants to upgrade the building in this cell

	//copy construcor and assignment disabled
	Player (const Player&) = delete;
	Player& operator= (const Player&) = delete;

protected:

	//default constructor
	Player () : balance {100}, player_num {0}, player_pos {0}, playing {false} {}
	//constructor with the number of the player and the board where it plays
	Player (int num, Board* b) : balance {100}, player_num {num}, player_pos {0}, board {b}, playing{true}  {if(player_num < 1 || player_num > 4) throw std::invalid_argument("Number of player must be between 1 and 4");}

private:

	//amount of money this player has; number of player; player position in the board
	int balance, player_num, player_pos;
	//board where this Player plays
	Board *board;
	//tells if this player is playing or not
	bool playing;
};

#endif
