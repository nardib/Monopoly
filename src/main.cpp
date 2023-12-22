//made by : Marco Spolverato 2032569

#include "Cell.h"

int main (void)
{
	Cell c {static_cast<CellType>(3)};
	c.buy_property(4);
	c.upgrade_building();
	std::cout << c << std::endl;

	return 0;
}