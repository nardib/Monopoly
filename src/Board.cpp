//made by : 

#include "Board.h"

void Board::move_to(int p, int n)
{}

//print the board correctly via std::cout
std::ostream& operator<< (std::ostream& out, Board b)
{
	//i print in the top the cells between 14 and 21
	for (int i = 14; i < 22; i++)
		std::cout << b.get_value(i) << ' ';
	std::cout << std::endl;
	//i print the side cells with the necessary space
	std::cout << b.get_value(13) << "                                     " << b.get_value(22) << std::endl;
	std::cout << b.get_value(12) << "                                     " << b.get_value(23) << std::endl;
	std::cout << b.get_value(11) << "                                     " << b.get_value(24) << std::endl;
	std::cout << b.get_value(10) << "                                     " << b.get_value(25) << std::endl;
	std::cout << b.get_value(9) << "                                     " << b.get_value(26) << std::endl;
	std::cout << b.get_value(8) << "                                     " << b.get_value(27) << std::endl;
	//in the end i print the bottom cells
	for (int i = 7; i >= 0; i--)
		std::cout << b.get_value(i) << ' ';
	std::cout << std::endl;

	return out;
}