//made by : Lorenzo Nardin 2066609

#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"

//board size
const int SIZE = 28;

class Board
{
public:

	//default constructor
	Board () : p1_pos {0}, p2_pos {0}, p3_pos {0}, p4_pos{0} {for (int i = 0; i < 28; i ++) board[i];}
	//constructor of a random table with a defined number of cells (n_eco = number of economic cell, etc.)
	Board (int n_eco, int n_std, int n_lux);
	
	//moves in the board player_num n positions forward
	void move_to(int player_num, int n);

	//returns Cell[i] value (da aggiornare in Board.cpp con il controllo che i sia valido)
	Cell get_value(int i);
	//return the position of the player in the board
	int p1() {return p1_pos;}
	int p2() {return p2_pos;}
	int p3() {return p3_pos;}
	int p4() {return p4_pos;}

private:
	Cell board [SIZE];
	//variables that memorize the position of every player in the board; private because i want them to be modified only with the command move_to, and they must assume a value between 0 and 27
	int p1_pos, p2_pos, p3_pos, p4_pos;

};

//overload operator<< to print the board
std::ostream& operator<< (std::ostream& out, Board b);

#endif