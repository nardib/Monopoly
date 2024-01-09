//made by : Manuel Andretto 2074979

#include "Player.h"

//move this player in the board
void Player::move(int n)
{
	board->move_to(player_num, n);
	player_pos = get_pos_in_board();
}

int Player::get_pos_in_board() 
{
	switch (player_num)
	{
	case 1:
		return board->p1();
		break;
	case 2:
		return board->p2();
		break;
	case 3:
		return board->p3();
		break;
	case 4:
		return board->p4();
		break;
	}
	throw std::out_of_range("This player is not in the board");
}

void Player::decrease_balance (int n)
{
	if (n < 0)
		throw std::invalid_argument("the amount of money must be positive");
	if (balance - n >= 0)
		balance -= n;
	else
		throw Player::NotEnoughMoney("You don't have enough money to complete this operation");
}

void Player::increase_balance (int n)
{
	if (n < 0)
		throw std::invalid_argument("The amount of money must be positive");
	balance += n;
}