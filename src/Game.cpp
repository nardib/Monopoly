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

bool comp(int a, int b)
{
    return(a<b);
}

bool compare_players(const std::pair<int, int>& player1, const std::pair<int, int>& player2)
{
    return(player1.first + player1.second) > (player2.first + player2.second);
}
std::vector<int> Game::player_order()
{
    const int numPlayers = 4;
    std::vector<std::pair<int, int>> playerResults;

    for (int i = 0; i < numPlayers; ++i) {
        std::pair<int, int> result = throw_dices();
        std::cout << "Player " << i + 1 << " throws: " << result.first << " and " << result.second << std::endl;
        playerResults.push_back(result);
    }

    std::sort(playerResults.begin(), playerResults.end(), compare_players);

    for (int i = 0; i < numPlayers - 1; ++i) {
        // Check for ties and resolve them by rethrowing dice
        while ((playerResults[i].first + playerResults[i].second) == (playerResults[i + 1].first + playerResults[i + 1].second)) {
            std::cout << "Tiebreaker for Player " << i + 1 << " and Player " << i + 2 << std::endl;
            playerResults[i] = throw_dices();
            playerResults[i + 1] = throw_dices();
            std::cout << "New results: " << playerResults[i].first << ", " << playerResults[i].second<< " and " << playerResults[i + 1].first << ", " << playerResults[i + 1].second << std::endl;
        }
    }

    std::vector<int> finalOrder;
    for (const auto& result : playerResults) {
        finalOrder.push_back(result.first);
    }

    return finalOrder;
}

void Game::cross_go(Player& p)
{
    p.increase_balance(20);
}

void Game::move_player(Player& p,int n)
{
    p.move(n);
}

void Game::reset_properties(Player& p)
{
    for(int i=0; i< 28; i++)
    {
        if(b.get_value(i).return_owner()==(p.num()))
        {
            b.get_value(i).sell_property();
        }
    }
}

void Game::buy_terrain(Player& p)
{
    if(p.buy_intent())
    {
        (b.get_value(p.pos())).buy_property(p.num());
    }
}

void Game::upgrade(Player& p)
{
    if(p.upgrade_intent() || (b.get_value(p.pos())).return_owner()==p.num())
    {
        (b.get_value(p.pos())).upgrade_building();
        if((b.get_value(p.pos())).building_type()==Building::House)
        {

        }
        if((b.get_value(p.pos())).building_type()==Building::Hotel)
        {

        }
    }
}

Player& Game::return_player(int n)
{
	if(n==1)
    {
        return *p1;
    }
    if(n==2)
    {
        return *p2;
    }
    if(n==3)
    {
        return *p3;
    }
    if(n==4)
    {
        return *p4;
    }
    throw std::invalid_argument("The player is not on the board");
}

void Game::pay_stay(Player& p)
{
    if((b.get_value(p.pos())).return_owner()==0 && (b.get_value(p.pos())).return_owner()==p.num())
    {
        if((b.get_value(p.pos())).building_type()==Building::House)
        {
            p.decrease_balance((b.get_value(p.pos())).accomodation_house_price());
            (return_player(b.get_value(p.pos()).return_owner())).increase_balance((b.get_value(p.pos())).accomodation_house_price());
        }
        if((b.get_value(p.pos())).building_type()==Building::Hotel)
        {
            p.decrease_balance((b.get_value(p.pos())).accomodation_hotel_price());
            (return_player(b.get_value(p.pos()).return_owner())).increase_balance((b.get_value(p.pos())).accomodation_hotel_price());
        }
    }
}

std::pair<int, int> Game::throw_dices()
{
    dice1=throw_dice(6);
    dice2=throw_dice(6);
    return {dice1, dice2};
}

bool Game::check_dices()
{
    return(dice1==dice2);
}