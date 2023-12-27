//made by : Lorenzo Nardin 2066609

#include "Player.h"

//move this player in the board
void Player::move(int n)
{
	board.move_to(player_num, n);
}

int Player::get_pos_in_board() 
{
	switch (player_num)
	{
	case 1:
		return board.p1();
		break;
	case 2:
		return board.p2();
		break;
	case 3:
		return board.p3();
		break;
	case 4:
		return board.p4();
		break;
	}
	throw std::out_of_range("This player is not in the board");
}

//this function returns a number between 1 and max (used in throw_dices)
int throw_dice(int max)
{
	return (rand() % max) + 1;
}

int Player::throw_dices()
{
	int n1 = throw_dice(6);
	int n2 = throw_dice(6);
	int tot = n1  + n2;

	if(n1 == n2)
		tot += throw_dice(6);

	last_dice_throw = tot;
	return last_dice_throw;
}

void Player::decrease_balance (int n)
{
	if (n < 0)
		throw std::invalid_argument("The amount of money must be positive");
	if (balance - n >= 0)
		balance -= n;
	throw Player::NotEnoughMoney("You don't have enough money to complete this operation");
}

void Player::increase_balance (int n)
{
	if (n < 0)
		throw std::invalid_argument("The amount of money must be positive");
	balance += n;
}