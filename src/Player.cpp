//made by : Lorenzo Nardin 2066609

#include "Player.h"

//move this player in the board
void Player::move(int n, Board b)
{
	b.move_to(player_num, n);
}

int Player::get_pos_in_board(Board b) const
{
	for (int i = 0; i < SIZE; i++)
	{
		if(b.get_value(i).is_pn_here(player_num))
			return i;
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