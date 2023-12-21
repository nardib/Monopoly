//file sviluppato da : Marco Spolverato 2032569

#include <iostream>

//this function returns a number between 1 and max

int main (void)
{
	std::cout << "Hello, World!\n";

	return 0;
}

int throw_dice(int max)
{
	return (rand() % max) + 1;
}