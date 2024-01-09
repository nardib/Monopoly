//made by : Marco Spolverato 2032569

#include "Game.h"
#include <Windows.h>
#include <cstdio>

int main (int argc, char *argv[])
{
	// Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);
	if(argc > 1)
		std::cout << "elemento da riga di comando: " << argv[1] << std::endl;
	Board b {8, 10, 6};
	ComputerPlayer p1(1, &b);
	ComputerPlayer p2(2, &b);
	ComputerPlayer p3(3, &b);
	ComputerPlayer p4(4, &b);
	Game g(&p1, &p2, &p3, &p4, &b);
	g.game();
	/*
	Cell c {static_cast<CellType>(3)};
	c.buy_property(4);
	c.upgrade_building();
	c.p1 = true;
	c.p3 = true;
	std::cout << c << std::endl;
	std::cout << b;
	b.move_to(3, 35);
	std::cout << b;
	return 0;
	*/
}