//made by : Lorenzo Nardin 2066609

#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <random>

//board size
const int BOARD_SIZE = 28;

class Board
{
public:

	//default constructor
	Board () : p1_pos {0}, p2_pos {0}, p3_pos {0}, p4_pos{0} {for (int i = 0; i < BOARD_SIZE; i ++) board[i];}
	//constructor of a random table with a defined number of cells (n_eco = number of economic cell, etc.)
	Board (int n_eco, int n_std, int n_lux);
	
	//moves in the board player_num n positions forward
	void move_to(int player_num, int n);

	//returns Cell[i] value; it has a check on the number i given as argument
	Cell& get_value(int i);
	//return the position of the player in the board
	int p1() {return p1_pos;}
	int p2() {return p2_pos;}
	int p3() {return p3_pos;}
	int p4() {return p4_pos;}

private:
	//array of Cell that contains all the cells of the board
	Cell board [BOARD_SIZE];
	//variables that memorize the position of every player in the board; private because i want them to be modified only with the command move_to, and they must assume a value between 0 and 27
	int p1_pos, p2_pos, p3_pos, p4_pos;

};

//overload operator<< to print the board
std::ostream& operator<< (std::ostream& out, Board b);

//function that returns a number between min and max (this will be used in various part of the code)
int random (int min, int max);

#endif