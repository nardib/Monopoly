//made by : Marco Spolverato 2032569

#include "Board.h"

int main (void)
{
	Cell c {static_cast<CellType>(3)};
	c.buy_property(4);
	c.upgrade_building();
	c.p1 = true;
	c.p3 = true;
	std::cout << c << std::endl;

	Board b {};
	std::cout << b;

	return 0;
}