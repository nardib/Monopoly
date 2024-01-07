//made by Marco Spolverato 2032569

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
    int d1, d2;

    // Loop for each player
    for (int i = 0; i < 4; i++) 
    {
        d1 = throw_dices().first;
        d2 = throw_dices().second;
        std::cout << "Giocatore " << i+1<< " ha tirato i dadi ottenendo un valore di " << d1 << " + " << d2 << " = " << d1 + d2 << ".\n";
        players.push_back({i+1, (d1 + d2)});
    }

    // Sort players by score in descending order
    std::sort(players.begin(), players.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    });

    // Check for ties among the top players and resolve them
    std::vector<int> tied_players = check_tie(players);
    std::vector<std::pair<int, int>> resolved_ties;
    for (int i = 0; i < tied_players.size(); i++) 
    {
        d1 = throw_dices().first;
        d2 = throw_dices().second;
        std::cout << "Giocatore " << players[tied_players[i]].first << " ha tirato i dadi ottenendo un valore di " << d1 << " + " << d2 << " = " << d1 + d2 << ".\n";
        resolved_ties.push_back({players[tied_players[i]].first, d1 + d2});  // Store the resolved ties separately
    }

    // Sort the resolved ties by score in descending order
    std::sort(resolved_ties.begin(), resolved_ties.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    });

    // Replace the scores of the tied players in the players vector with their new scores
    for (int i = 0; i < tied_players.size(); i++) 
    {
        players[tied_players[i]].second = resolved_ties[i].second;
    }

    // Create the order of players
    for (const auto& player : players) 
    {
        order.push_back(player.first);
    }

    return order;
}

std::vector<int> Game::check_tie(const std::vector<std::pair<int, int>>& players)
{
    std::vector<int> ties;
    std::map<int, std::vector<int>> scores;

    // Group players by score
    for (int i = 0; i < players.size(); i++) 
    {
        scores[players[i].second].push_back(i);
    }

    // Check for ties
    for (const auto& score : scores) 
    {
        if (score.second.size() > 1)  // If more than one player has this score
        {
            ties.insert(ties.end(), score.second.begin(), score.second.end());  // Add all tied players to ties
        }
    }

    return ties;
}

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
    if(p->buy_intent() && (b->get_value(p->pos())).return_owner()==0)
    {
        (b->get_value(p->pos())).buy_property(p->num());
        p->decrease_balance((b->get_value(p->pos())).terrain_price());
        std::cout<<"Giocatore "<< p->num()<< " ha acquistato il terreno "<< p->pos()<<".\n";
        return true;
    }
    return false;
}

bool Game::upgrade(Player* p)
{
    if(p->upgrade_intent() && (b->get_value(p->pos())).return_owner()==p->num())
    {
        (b->get_value(p->pos())).upgrade_building();
        if((b->get_value(p->pos())).building_type()==Building::House)
        {
            p->decrease_balance((b->get_value(p->pos())).house_price());
            std::cout<<"Giocatore "<< p->num()<< " ha costruito una casa sul terreno "<< p->pos()<<".";
            return true;
        }
        if((b->get_value(p->pos())).building_type()==Building::Hotel)
        {
            p->decrease_balance((b->get_value(p->pos())).hotel_price());
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
    return std::make_pair(dice1, dice2);
}

bool Game::check_dices()
{
    return(dice1==dice2);
}

void Game::game()
{
    bool done=false;
    std::vector<int> po = player_order();
    std::cout<< "L'ordine dei giocatori e': "<<po[0]<< " "<< po[1]<< " "<< po[2]<< " "<< po[3]<< ".\n";
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
                in_turn=false;
                std::cout<< curr->budget()<< " fiorini.\n";
            }
            while(in_turn)
            {
                if(check_dices() && turn_count>0)
                {
                    std::cout<< "Giocatore "<< curr->num()<< " ha ottenuto un lancio doppio e svolgera' un altro turno.\n";
                }
                std::pair<int, int> dices = throw_dices();
                std::cout<<"Giocatore "<< curr->num()<< " ha tirato i dadi ottenendo un valore di "<< dices.first<<" + "<< dices.second<< " = "<< dices.first+dices.second<< ".\n";
                in_turn = check_dices();
                int start_pos= curr->pos();
                move_player(curr, (dices.first + dices.second));
                std::cout<<*b;
                int end_pos= curr->pos();
                if(end_pos<start_pos)
                {
                    cross_go(curr);
                }
                std::cout<< curr->budget()<< " fiorini.\n";
                if(b->get_value(curr->pos()).return_owner()==curr->num() && (curr->budget()>=(b->get_value(curr->pos())).price()))
                {
                    upgrade(curr);
                }
                if(b->get_value(curr->pos()).return_owner()==0 && curr->budget()>=(b->get_value(curr->pos())).terrain_price() && b->get_value(curr->pos()).building_type()==Building::None)
                {
                    buy_terrain(curr);
                }
                if(b->get_value(curr->pos()).return_owner()!=0 && b->get_value(curr->pos()).return_owner()!=curr->num())
                {
                    if(pay_stay(curr))
                    {}
                    else
                    {
                        player_count--;
                        std::cout<<"Giocatore " << curr->num() << " e' stato eliminato.\n";
                        reset_properties(curr);
                        curr->end_game();
                        in_turn=false;
                    }
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
                int richest = 0;
                int winner = 0;
                for(int i=0;i<4; i++)
                {
                    curr = return_player(i+1);
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
