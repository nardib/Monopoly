//made by : Marco Spolverato 2032569

#include "Game.h"

int main (int argc, char *argv[])
{
	if(argc != 2)	//Check if the number of arguments is correct
	{
		std::cout << "Utilizzo: ./main [human/computer]" << std::endl;
		return 0;
	}
	std::string type= static_cast<std::string>(argv[1]);
	if(type != "human" && type != "computer")	//Check if the argument is correct
	{
		std::cout << "Utilizzo: ./main [human/computer]" << std::endl;
		return 0;
	}
	std::cout<<"Benvenuto in Monopoly!"<<std::endl;
	std::cout<<"Inserisci il numero di turni che vuoi giocare: ";
	int turns = 0;
	while(turns < 1 || std::cin.fail())		//Check if the input is correct
	{
		std::cout << "Inserisci un numero maggiore di 0: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin >> turns;
	}
	Board b {8, 10, 6};			//Create the board
	ComputerPlayer p2(2, &b);
	ComputerPlayer p3(3, &b);
	ComputerPlayer p4(4, &b);
	if(type == "human")			//Create the Human Player
	{
		HumanPlayer p1(1, &b);
		Game g(&p1, &p2, &p3, &p4, &b, turns);
		g.game();				//Start the game
	}
	if(type == "computer")		//Create the Computer Player
	{
		ComputerPlayer p1(1, &b);
		Game g(&p1, &p2, &p3, &p4, &b, turns);
		g.game();				//Start the game
	}
	return 0;
}