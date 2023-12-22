//file sviluppato da : Marco Spolverato 2032569

#include "Cell.h"

//this function returns a number between 1 and max
int throw_dice(int max)
{
	return (rand() % max) + 1;
}

int main (void)
{
	Cell c {static_cast<CellType>(3)};
	c.buy_property(4);
	c.upgrade_building();
	std::cout << c << std::endl;

	return 0;
}