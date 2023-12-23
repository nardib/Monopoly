//made by : 

#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"

//board size
const int SIZE = 28;

class Board
{
public:

	//default constructor
	Board () {for (int i = 0; i < 28; i ++) board[i];}
	
	//moves in the board player_num n positions forward
	void move_to(int player_num, int n);

	//returns Cell[i] value (da aggiornare in Board.cpp con il controllo che i sia valido)
	Cell get_value(int i) {return board[i];}

private:
	Cell board [SIZE];

};

//overload operator<< to print the board
std::ostream& operator<< (std::ostream& out, Board b);

#endif