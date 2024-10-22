//made by : Manuel Andretto 2074979

#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <vector>
#include <algorithm>

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
	std::vector<int> get_properties() const {return p_property;}

	//move this player in the board n positions forward
	void move(int n);

	//gets pos in the board; returns the index in the array of the board
	//it does a linear search in the array and memorize that value in a variable
	int get_pos_in_board();

	//functions to modify the balance
	void decrease_balance (int n);
	void increase_balance (int n);

	//changes the value of this player to false; once it turns to false, it can't become true anymore
	//clears the p_property vector
	void end_game() {playing = false; p_property.clear();}

	//virtual functions that must be overrided
	virtual bool buy_intent() = 0;		//this function returns true if the player would buy this property
	virtual bool upgrade_intent() = 0;	//this function returns true if the player wants to upgrade the building in this cell

	//copies constructor and disables assignment 	
	Player (const Player&) = delete;
	Player& operator= (const Player&) = delete;

protected:

	//default constructor
	Player () : balance {100}, player_num {0}, player_pos {0}, playing {false} {}
	//constructor with the number of the player and the board where it plays
	Player (int num, Board* b) : balance {100}, player_num {num}, player_pos {0}, board {b}, playing{true}  {if(player_num < 1 || player_num > 4) throw std::invalid_argument("Number of player must be between 1 and 4");}
	//property owned by the player
	std::vector<int> p_property;
	//board where this Player plays
	Board *board;

private:

	//amount of money this player has; number of player; player position in the board
	int balance, player_num, player_pos;
	//tells if this player is playing or not
	bool playing;
};

#endif
