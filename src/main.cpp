//made by : Marco Spolverato 2032569

#include "Game.h"

int main (void)
{
	
	Cell c {static_cast<CellType>(3)};
	c.buy_property(4);
	c.upgrade_building();
	c.p1 = true;
	c.p3 = true;
	std::cout << c << std::endl;

	Board b {8, 10, 6};
	std::cout << b;
	b.move_to(3, 35);
	std::cout << b;
	std::cout << b.get_value(0) << std::endl;

	HumanPlayer p1(1, b);
	HumanPlayer p2(2, b);
	HumanPlayer p3(3, b);
	HumanPlayer p4(4, b);
	Game g(p1, p2, p3, p4, b);
	g.player_order();
	return 0;
}