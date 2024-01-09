//made by : Marco Spolverato 2032569

#include "Game.h"

int main (int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cout << "Utilizzo: ./main [human/computer]" << std::endl;
		return 0;
	}
	std::string type= static_cast<std::string>(argv[1]);
	if(type != "human" && type != "computer")
	{
		std::cout << "Utilizzo: ./main [human/computer]" << std::endl;
		return 0;
	}
	Board b {8, 10, 6};
	ComputerPlayer p2(2, &b);
	ComputerPlayer p3(3, &b);
	ComputerPlayer p4(4, &b);
	if(type == "human")
	{
		HumanPlayer p1(1, &b);
		Game g(&p1, &p2, &p3, &p4, &b);
		g.game();
	}
	if(type == "computer")
	{
		ComputerPlayer p1(1, &b);
		Game g(&p1, &p2, &p3, &p4, &b);
		g.game();
	}
	return 0;
}