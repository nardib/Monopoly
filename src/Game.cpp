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
        std::cout << "Player " << i + 1 << " throws: " << result.first << " and " << result.second << "." << std::endl;
        playerResults.push_back(result);
    }

    std::sort(playerResults.rbegin(), playerResults.rend(), compare_players);

    for (int i = 0; i < numPlayers - 1; ++i) {
        // Check for ties and resolve them by rethrowing dice
        while ((playerResults[i].first + playerResults[i].second) == (playerResults[i + 1].first + playerResults[i + 1].second)) {
            std::cout << "Tiebreaker for Player " << i + 1 << " and Player " << i + 2 << "." << std::endl;
            playerResults[i] = throw_dices();
            playerResults[i + 1] = throw_dices();
            std::cout << "New results: " << playerResults[i].first << ", " << playerResults[i].second << " and " << playerResults[i + 1].first << ", " << playerResults[i + 1].second << "." << std::endl;
        }
    }

    std::vector<int> finalOrder;
    for (int i = 0; i < numPlayers; ++i) {
        // Push the index (player order) into the finalOrder vector in reverse order
        finalOrder.push_back(i + 1);
    }

    std::cout << finalOrder[0] << finalOrder[1] << finalOrder[2] << finalOrder[3];
    return finalOrder;
}

void Game::cross_go(Player& p)
{
    p.increase_balance(20);
    std::cout<<"Giocatore "<< p.num()<< " è passato dal via e ha ritirato 20 fiorini.\n";
}

void Game::move_player(Player* p,int n)
{
    p->move(n);
    std::cout<<"Giocatore "<< p->num()<< " e' arrivato alla casella "<< p->pos()<< ".\n";
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
    std::cout<<"Giocatore "<< p.num()<< " ha donato le sue proprietà alla banca in seguito alla bancarotta.\n";
}

void Game::buy_terrain(Player& p)
{
    if(p.buy_intent())
    {
        (b.get_value(p.pos())).buy_property(p.num());
    }
    std::cout<<"Giocatore "<< p.num()<< " ha acquistato il terreno "<< p.pos()<<".\n";
}

void Game::upgrade(Player& p)
{
    if(p.upgrade_intent() || (b.get_value(p.pos())).return_owner()==p.num())
    {
        (b.get_value(p.pos())).upgrade_building();
        if((b.get_value(p.pos())).building_type()==Building::House)
        {
            std::cout<<"Giocatore "<< p.num()<< " ha costruito una casa sul terreno "<< p.pos()<<".";
        }
        if((b.get_value(p.pos())).building_type()==Building::Hotel)
        {
            std::cout<<"Giocatore "<< p.num()<< " ha migliorato una casa in albergo sul terreno "<< p.pos()<< ".";
        }
    }
}

Player* Game::return_player(int n)
{
	if(n==1)
    {
        return p1;
    }
    if(n==2)
    {
        return p2;
    }
    if(n==3)
    {
        return p3;
    }
    if(n==4)
    {
        return p4;
    }
    throw std::invalid_argument("The player is not on the board");
}

bool Game::pay_stay(Player& p)
{
    if((b.get_value(p.pos())).return_owner()==0 && (b.get_value(p.pos())).return_owner()==p.num())
    {
        if((b.get_value(p.pos())).building_type()==Building::House)
        {
            if(p.budget()>((b.get_value(p.pos())).accomodation_house_price()))
            {
                p.decrease_balance((b.get_value(p.pos())).accomodation_house_price());
                (return_player(b.get_value(p.pos()).return_owner()))->increase_balance((b.get_value(p.pos())).accomodation_house_price());
                std::cout<<"Giocatore "<< p.num()<< " ha pagato "<< ((b.get_value(p.pos())).accomodation_house_price())<< " fiorini a giocatore "<< (b.get_value(p.pos()).return_owner())<< " per pernottamento nella casella "<< p.pos()<< ".\n";
                return true;
            }
            else
            {
                std::cout<<"Giocatore "<< p.num()<< "non aveva abbastanza soldi per pagare giocatore "<< (b.get_value(p.pos()).return_owner())<< " e ha speso gli ultimi "<< p.budget()<< " fiorini.\n";
                p.decrease_balance(p.budget());
                (return_player(b.get_value(p.pos()).return_owner()))->increase_balance(p.budget());
                return false;
            }
        }
        if((b.get_value(p.pos())).building_type()==Building::Hotel)
        {
            if(p.budget()>((b.get_value(p.pos())).accomodation_hotel_price()))
            {
                p.decrease_balance((b.get_value(p.pos())).accomodation_hotel_price());
                (return_player(b.get_value(p.pos()).return_owner()))->increase_balance((b.get_value(p.pos())).accomodation_hotel_price());
                std::cout<<"Giocatore "<< p.num()<< " ha pagato "<< (b.get_value(p.pos())).accomodation_hotel_price()<< " fiorini a giocatore "<< (b.get_value(p.pos()).return_owner())<< " per pernottamento nella casella "<< p.pos()<< ".\n";
                return true;
            }
            else
            {
                std::cout<<"Giocatore "<< p.num()<< "non aveva abbastanza soldi per pagare giocatore "<< (b.get_value(p.pos()).return_owner())<< " e ha speso gli ultimi "<< p.budget()<< " fiorini.\n";
                p.decrease_balance(p.budget());
                (return_player(b.get_value(p.pos()).return_owner()))->increase_balance(p.budget());
                return false;
            }
        }
    }
    return true;
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

void Game::game()
{
    bool done=false;
    std::vector<int> po = player_order();
    int player_count=4;
    int turn_count=0;
    Player* curr;
    while(!done)
    {
        for(int i=0; i<4; i++)
        {
            std::cout<<b;
            bool in_turn=false;
            if(return_player(po[i])->is_playing())
            {    
                curr= return_player(po[i]);
                in_turn=true;
            }
            if(player_count==1)
            {
                i=4;
                std::cout<< "Giocatore "<< curr->num()<< " ha vinto la partita.\n";
                done=true;
            }
            //while(in_turn)
            //{
                if(check_dices() || turn_count>0)
                {
                    std::cout<< "Giocatore "<< curr->num()<< " ha ottenuto un lancio doppio e svolgera' un altro turno.\n";
                }
                std::pair<int, int> dices = throw_dices();
                std::cout<<"Giocatore "<< curr->num()<< " ha tirato i dadi ottenendo un valore di "<< dices.first<<" + "<< dices.second<< " = "<< dices.first+dices.second<< ".\n";
                in_turn=check_dices();
                int start_pos= curr->pos();
                move_player(curr, (dices.first + dices.second));
                int end_pos= curr->pos();
                if(end_pos<start_pos)
                {
                    cross_go(*curr);
                }
                buy_terrain(*curr);
                upgrade(*curr);
                if(!pay_stay(*curr))
                {
                    player_count--;
                    std::cout<<"Giocatore " << curr->num() << " e' stato eliminato.";
                }
            //}
            std::cout<<"Giocatore " << curr->num() << " ha finito il turno.";
            if(i==3)
            {
                i==0;
            }
            if(turn_count>100)
            {
                int richest;
                int winner;
                for(int i=0;i<4; i++)
                {
                    if(curr->budget()>richest)
                    {
                        richest=curr->budget();
                        winner=curr->num();
                    }
                }
                i=4;
                done=true;
            }
        }
    }
}