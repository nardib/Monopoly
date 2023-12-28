//made by Marco SPolverato 2032569

#include "Game.h"

//constructor
Game::Game(Player *pl1, Player *pl2, Player *pl3, Player *pl4, Board bo)
{
    p1=pl1;
    p2=pl2;
    p3=pl3;
    p4=pl4;
    b=bo;
}

int Game::starting_player()
{
    return 0;
}

void Game::cross_go(Player& p)
{
    p.increase_balance(20);
}

void Game::move_player(Player& p,int n)
{
    p.move(n);
}

int Game::throw_dices()
{
    dice1=throw_dice(6);
    dice2=throw_dice(6);
    return dice1+dice2; 
}