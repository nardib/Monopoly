//made by Marco SPolverato 2032569

#include "Game.h"

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
    std::vector<std::pair<int, int>> players;
    std::vector<int> order;
    std::vector<int> tied_players;
    int d1, d2;

    // Loop for each player
    for (int i = 0; i < 4; i++) {
        do 
        {
            d1 = throw_dices().first;
            d2 = throw_dices().second;
            std::cout << "Giocatore " << i+1 << " ha tirato i dadi ottenendo un valore di " << d1 << " + " << d2 << " = " << d1 + d2 << ".\n";
            players[i] = {i+1, (d1 + d2)};
            tied_players = check_tie(players);  // Get the indices of the tied players
        }while (!tied_players.empty());  // Repeat if there's a tie
    }

    // Sort and return the order
    std::sort(players.begin(), players.end(), compare_players);
    for (const auto &player : players) {
        order.push_back(player.first);
    }
    return order;
}

std::vector<int> Game::check_tie(std::vector<std::pair<int, int>>& players)
{
    std::vector<int> tied_players;
    for (int i=0; i<players.size(); i++) 
    {
        std::cout<<"1\n";
        for (int j=i+1; j<players.size(); j++) 
        {
            std::cout<<"2\n";
            if (players[i].second == players[j].second) 
            {
                std::cout<<"3\n";
                std::cout << "Tie between player " << players[i].first << " and player " << players[j].first << ". Throwing the dices again.\n";
                tied_players.push_back(i);
                tied_players.push_back(j);
            }
        }
    }
    return tied_players;
}

/*std::vector<int> Game::player_order()
{
    std::vector<std::pair<int, int>> players;
    std::vector<int> order;
    int d1=throw_dices().first;
    int d2=throw_dices().second;
    std::cout<<"Giocatore "<< p1->num()<< " ha tirato i dadi ottenendo un valore di "<< d1<<" + "<< d2<< " = "<< d1+d2<< ".\n";
    players.push_back({p1->num(), (d1+d2)});
    d1=throw_dices().first;
    d2=throw_dices().second;
    std::cout<<"Giocatore "<< p2->num()<< " ha tirato i dadi ottenendo un valore di "<< d1<<" + "<< d2<< " = "<< d1+d2<< ".\n";
    players.push_back({p2->num(), (d1+d2)});
    d1=throw_dices().first;
    d2=throw_dices().second;
    std::cout<<"Giocatore "<< p3->num()<< " ha tirato i dadi ottenendo un valore di "<< d1<<" + "<< d2<< " = "<< d1+d2<< ".\n";
    players.push_back({p3->num(), (d1+d2)});
    d1=throw_dices().first;
    d2=throw_dices().second;
    std::cout<<"Giocatore "<< p4->num()<< " ha tirato i dadi ottenendo un valore di "<< d1<<" + "<< d2<< " = "<< d1+d2<< ".\n";
    players.push_back({p4->num(), (d1+d2)});
    std::sort(players.begin(), players.end(), compare_players);
    for(int i=0; i<4; i++)
    {
        order.push_back(players[i].first);
    }
    return order;
}
*/

void Game::cross_go(Player* p)
{
    p->increase_balance(20);
    std::cout<<"Giocatore "<< p->num()<< " è passato dal via e ha ritirato 20 fiorini.\n";
}

void Game::move_player(Player* p,int n)
{
    p->move(n);
    std::cout<<"Giocatore "<< p->num()<< " e' arrivato alla casella "<< p->pos()<< ".\n";
}

void Game::reset_properties(Player* p)
{
    for(int i=0; i< 28; i++)
    {
        if(b->get_value(i).return_owner()==(p->num()))
        {
            b->get_value(i).sell_property();
        }
    }
    std::cout<<"Giocatore "<< p->num()<< " ha donato le sue proprietà alla banca in seguito alla bancarotta.\n";
}

bool Game::buy_terrain(Player* p)
{
    if(p->buy_intent())
    {
        (b->get_value(p->pos())).buy_property(p->num());
        std::cout<<"Giocatore "<< p->num()<< " ha acquistato il terreno "<< p->pos()<<".\n";
        return true;
    }
    return false;
}

bool Game::upgrade(Player* p)
{
    if(p->upgrade_intent())
    {
        (b->get_value(p->pos())).upgrade_building();
        if((b->get_value(p->pos())).building_type()==Building::House)
        {
            std::cout<<"Giocatore "<< p->num()<< " ha costruito una casa sul terreno "<< p->pos()<<".";
            return true;
        }
        if((b->get_value(p->pos())).building_type()==Building::Hotel)
        {
            std::cout<<"Giocatore "<< p->num()<< " ha migliorato una casa in albergo sul terreno "<< p->pos()<< ".";
            return true;
        }
        return false;
    }
    return false;
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

bool Game::pay_stay(Player* p)
{
    if((b->get_value(p->pos())).return_owner()==0 && (b->get_value(p->pos())).return_owner()==p->num())
    {
        if((b->get_value(p->pos())).building_type()==Building::House)
        {
            if(p->budget()>((b->get_value(p->pos())).accomodation_house_price()))
            {
                p->decrease_balance((b->get_value(p->pos())).accomodation_house_price());
                (return_player(b->get_value(p->pos()).return_owner()))->increase_balance((b->get_value(p->pos())).accomodation_house_price());
                std::cout<<"Giocatore "<< p->num()<< " ha pagato "<< ((b->get_value(p->pos())).accomodation_house_price())<< " fiorini a giocatore "<< (b->get_value(p->pos()).return_owner())<< " per pernottamento nella casella "<< p->pos()<< ".\n";
                return true;
            }
            else
            {
                std::cout<<"Giocatore "<< p->num()<< "non aveva abbastanza soldi per pagare giocatore "<< (b->get_value(p->pos()).return_owner())<< " e ha speso gli ultimi "<< p->budget()<< " fiorini.\n";
                p->decrease_balance(p->budget());
                (return_player(b->get_value(p->pos()).return_owner()))->increase_balance(p->budget());
                return false;
            }
        }
        if((b->get_value(p->pos())).building_type()==Building::Hotel)
        {
            if(p->budget()>((b->get_value(p->pos())).accomodation_hotel_price()))
            {
                p->decrease_balance((b->get_value(p->pos())).accomodation_hotel_price());
                (return_player(b->get_value(p->pos()).return_owner()))->increase_balance((b->get_value(p->pos())).accomodation_hotel_price());
                std::cout<<"Giocatore "<< p->num()<< " ha pagato "<< (b->get_value(p->pos())).accomodation_hotel_price()<< " fiorini a giocatore "<< (b->get_value(p->pos()).return_owner())<< " per pernottamento nella casella "<< p->pos()<< ".\n";
                return true;
            }
            else
            {
                std::cout<<"Giocatore "<< p->num()<< "non aveva abbastanza soldi per pagare giocatore "<< (b->get_value(p->pos()).return_owner())<< " e ha speso gli ultimi "<< p->budget()<< " fiorini.\n";
                p->decrease_balance(p->budget());
                (return_player(b->get_value(p->pos()).return_owner()))->increase_balance(p->budget());
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
    std::cout<<po[0]<< " "<< po[1]<< " "<< po[2]<< " "<< po[3]<< "\n";
    int player_count=4;
    int turn_count=0;
    bool in_turn;
    Player* curr;
    while(!done)
    {
        for(int i=0; i<4; i++)
        {
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
            while(in_turn)
            {
                std::pair<int, int> dices = throw_dices();
                std::cout<<"Giocatore "<< curr->num()<< " ha tirato i dadi ottenendo un valore di "<< dices.first<<" + "<< dices.second<< " = "<< dices.first+dices.second<< ".\n";
                if(check_dices() || turn_count>0)
                {
                    std::cout<< "Giocatore "<< curr->num()<< " ha ottenuto un lancio doppio e svolgera' un altro turno.\n";
                }
                in_turn = check_dices();
                int start_pos= curr->pos();
                move_player(curr, (dices.first + dices.second));
                std::cout<<*b;
                int end_pos= curr->pos();
                if(end_pos<start_pos)
                {
                    cross_go(curr);
                }
                if((b->get_value(curr->pos())).return_owner()==curr->num())
                {
                    upgrade(curr);
                }
                if(b->get_value(curr->pos()).return_owner()==0)
                {
                    buy_terrain(curr);
                }
                if(!pay_stay(curr))
                {
                    player_count--;
                    std::cout<<"Giocatore " << curr->num() << " e' stato eliminato.\n";
                }
            }
            std::cout<<"Giocatore " << curr->num() << " ha finito il turno.\n";
            if(i==3)
            {
                i==0;
            }
            turn_count++;
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
                std::cout<<"Giocatore "<< winner<< " ha vinto la partita!\n";
                i=4;
                done=true;
            }
        }
    }
}