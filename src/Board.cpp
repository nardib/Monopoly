//made by : 

#include "Board.h"

Board::Board(int n_eco, int n_std, int n_lux) : p1_pos {0}, p2_pos {0}, p3_pos {0}, p4_pos{0}
{
	if(n_eco + n_std + n_lux != 24)
		throw std::invalid_argument("The number of every type of cell must be 24");

	int eco_count = 0, std_count = 0, lux_count = 0;
	//for loop that initialize all the cells of the board
	for (int i = 0; i < 28; i++)
	{
		bool is_set = false;
		if(i == 0)
		{
			board[i] = (CellType::Start);
			is_set = true;
		}
		if(i == 7 || i == 14 || i == 21)
		{
			board[i] = (CellType::Void);
			is_set = true;
		}	
		//i choose randomly the configuration of the cells in the board, but respecting the defined number of cells for every type
		while (!is_set)
		{
			int rnd = rand() % 3;
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

void Board::move_to(int p, int n)
{
	if (p == 1)
	{
		board[p1_pos].p1 = false;
		if(p1_pos + n < 28)
		{
			//sposto il player e aggiorno p1_pos
			p1_pos += n;
			board[p1_pos].p1 = true;
		}
		else
		{
			//se passo per il via devo aggiornare i fiorini del player
			p1_pos = p1_pos + n - 28;
			board[p1_pos].p1 = true;
		}
	}
	else if (p == 2)
	{
		board[p2_pos].p2 = false;
		if(p2_pos + n < 28)
		{
			//sposto il player e aggiorno p1_pos
			p2_pos += n;
			board[p2_pos].p2 = true;
		}
		else
		{
			//se passo per il via devo aggiornare i fiorini del player
			p2_pos = p2_pos + n - 28;
			board[p2_pos].p2 = true;
		}
	}
	else if (p == 3)
	{
		board[p3_pos].p3 = false;
		if(p3_pos + n < 28)
		{
			//sposto il player e aggiorno p1_pos
			p3_pos += n;
			board[p3_pos].p3 = true;
		}
		else
		{
			//se passo per il via devo aggiornare i fiorini del player
			p3_pos = p3_pos + n - 28;
			board[p3_pos].p3 = true;
		}
	}
	else if (p == 4)
	{
		board[p4_pos].p4 = false;
		if(p4_pos + n < 28)
		{
			//sposto il player e aggiorno p1_pos
			p4_pos += n;
			board[p4_pos].p4 = true;
		}
		else
		{
			//se passo per il via devo aggiornare i fiorini del player
			p4_pos = p4_pos + n - 28;
			board[p4_pos].p4 = true;
		}
	}
	
}

//print the board correctly via std::cout
std::ostream& operator<< (std::ostream& out, Board b)
{
	//i print in the top the cells between 14 and 21
	for (int i = 14; i < 22; i++)
		std::cout << b.get_value(i) << ' ';
	std::cout << std::endl;
	//i print the side cells with the necessary space
	std::cout << b.get_value(13) << "                                                                   " << b.get_value(22) << std::endl;
	std::cout << b.get_value(12) << "                                                                   " << b.get_value(23) << std::endl;
	std::cout << b.get_value(11) << "                                                                   " << b.get_value(24) << std::endl;
	std::cout << b.get_value(10) << "                                                                   " << b.get_value(25) << std::endl;
	std::cout << b.get_value(9) << "                                                                   " << b.get_value(26) << std::endl;
	std::cout << b.get_value(8) << "                                                                   " << b.get_value(27) << std::endl;
	//in the end i print the bottom cells
	for (int i = 7; i >= 0; i--)
		std::cout << b.get_value(i) << ' ';
	std::cout << std::endl;

	return out;
}