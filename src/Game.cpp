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

std::pair<int, int> Game::throw_dices()
{
    dice1=throw_dice(6);
    dice2=throw_dice(6);
    return {dice1, dice2};
}

void Game::check_dices()
{
    if(dice1==dice2)
        throw_dices();
}