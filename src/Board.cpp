//made by : Lorenzo Nardin 2066609

#include "Board.h"

//function that returns a random number between min and max 
int random(int min, int max)
{
	//seed the random number generator
	std::random_device rd;
	std::mt19937 gen(rd());

	//create a distribution for this range
	std::uniform_int_distribution<> distribution(min, max);

	//return a random number between min and max
	return distribution(gen);
}

//constructor for class Board that initialize a board with a defined number of economic, standard and luxury cells
Board::Board(int n_eco, int n_std, int n_lux) : p1_pos {0}, p2_pos {0}, p3_pos {0}, p4_pos{0}
{
	if(n_eco + n_std + n_lux != 24)
		throw std::invalid_argument("The sum of the number of every type of cell must be 24");

	int eco_count = 0, std_count = 0, lux_count = 0;
	//for loop that initialize all the cells of the board
	for (int i = 0; i < 28; i++)
	{
		bool is_set = false;
		//the cell 0 is the starting point
		if(i == 0)
		{
			board[i] = (CellType::Start);
			is_set = true;
		}
		//cells 7, 14 and 21 are the edges
		if(i == 7 || i == 14 || i == 21)
		{
			board[i] = (CellType::Void);
			is_set = true;
		}
		//i choose randomly the configuration of the cells in the board, but respecting the defined number of cells for every type
		while (!is_set)
		{
			int rnd = random(0, 2);
			if (rnd == 0 && eco_count < n_eco)
			{
				board[i] = (CellType::Economic);
				eco_count++;
				is_set = true;
			}
			else if(rnd == 1 && std_count < n_std)
			{
				board[i] = (CellType::Standard);
				std_count++;
				is_set = true;
			}
			else if(rnd == 2 && lux_count < n_lux)
			{
				board[i] = (CellType::Luxury);
				lux_count++;
				is_set = true;
			}
		}
	}
}

//function that moves player p n positions forward in the board
void Board::move_to(int p, int n)
{
	//all the if checks are equal; everyone removes the player from it's current position, and change it's position based on n
	//if pn_pos + n < 28 the player doesn't cross the start, so i can move it simply n positions forward
	//else i must make it goes pn_pos + n - 28 positions forward in order to make it stay in the board crossing the start
	if (p == 1)
	{
		board[p1_pos].p1 = false;
		if(p1_pos + n < 28)
			p1_pos += n;
		else
			p1_pos += n - 28;
		board[p1_pos].p1 = true;
	}
	else if (p == 2)
	{
		board[p2_pos].p2 = false;
		if(p2_pos + n < 28)
			p2_pos += n;
		else
			p2_pos += n - 28;
		board[p2_pos].p2 = true;
	}
	else if (p == 3)
	{
		board[p3_pos].p3 = false;
		if(p3_pos + n < 28)
			p3_pos += n;
		else
			p3_pos += n - 28;
		board[p3_pos].p3 = true;
	}
	else if (p == 4)
	{
		board[p4_pos].p4 = false;
		if(p4_pos + n < 28)
			p4_pos += n;
		else
			p4_pos += n - 28;
		board[p4_pos].p4 = true;
	}
	
}

//function that returns the value of the i element in the board (it has a check of the bounds in order to not generate a segmentation fault)
Cell& Board::get_value(int i)
{
	if (i < 0 || i >= BOARD_SIZE)
		throw std::invalid_argument("This is not an element of the board");
	return board[i];
}

//print the board correctly via std::cout
std::ostream& operator<< (std::ostream& out, Board b)
{
	//i print in the top the cells between 14 and 21, with their index on top
	std::cout << "   ";
	for (int i = 14; i < 22; i++)
		std::cout << "     " << i << "    ";
	std::cout << std::endl;
	std::cout << "   ";
	for (int i = 14; i < 22; i++)
		std::cout << b.get_value(i) << ' ';
	std::cout << std::endl;
	//i print the side cells with the necessary space and their index on left and right
	std::cout << "13 " << b.get_value(13) << "                                                                   " << b.get_value(22) << " 22" << std::endl;
	std::cout << "12 " << b.get_value(12) << "                                                                   " << b.get_value(23) << " 23" << std::endl;
	std::cout << "11 " << b.get_value(11) << "                                                                   " << b.get_value(24) << " 24" << std::endl;
	std::cout << "10 " << b.get_value(10) << "                                                                   " << b.get_value(25) << " 25" << std::endl;
	std::cout << "9  " << b.get_value(9) << "                                                                   " << b.get_value(26) << " 26" << std::endl;
	std::cout << "8  " << b.get_value(8) << "                                                                   " << b.get_value(27) << " 27" << std::endl;
	//in the end i print the bottom cells with their index on bottom
	std::cout << "   ";
	for (int i = 7; i >= 0; i--)
		std::cout << b.get_value(i) << ' ';
	std::cout << std::endl;
	std::cout << "   ";
	for (int i = 7; i >= 0; i--)
		std::cout << "      " << i << "    ";
	std::cout << std::endl;

	return out;
}