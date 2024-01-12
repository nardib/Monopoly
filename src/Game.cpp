//made by Marco Spolverato 2032569

#include "Game.h"

//Function to determine the order of players
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
    std::sort(players.begin(), players.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.second > b.second;});

    std::vector<int> tied_players = check_tie(players);

    while (!tied_players.empty())
    {
        for (int i = 0; i < tied_players.size(); i++) 
        {
            d1 = throw_dices().first;
            d2 = throw_dices().second;
            std::cout << "Giocatore " << players[tied_players[i]].first << " ha tirato i dadi ottenendo un valore di " << d1 << " + " << d2 << " = " << d1 + d2 << ".\n";
            players[tied_players[i]].second = d1 + d2;  // Update the score of the player
        }

        // Sort the players by score in descending order
        std::sort(players.begin(), players.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) 
        {
            return a.second > b.second;
        });

        // Check for ties again
        tied_players = check_tie(players);
    }

    // Create the order of players
    for (const auto& player : players) 
    {
        order.push_back(player.first);
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

//Function to handle crossing the "go" cell
void Game::cross_go(Player* p)
{
    p->increase_balance(20); //The player gets 20 florins for crossing the "go" cell
    std::cout<<"Giocatore "<< p->num()<< " e' passato dal via e ha ritirato 20 fiorini.\n";
    out<<"Giocatore "<< p->num()<< " e' passato dal via e ha ritirato 20 fiorini.\n";
}

//Function to move the player
void Game::move_player(Player* p,int n)
{
    p->move(n); //The player moves n cells
    std::cout<<"Giocatore "<< p->num()<< " e' arrivato alla casella "<< p->pos()<< ".\n";
    out<<"Giocatore "<< p->num()<< " e' arrivato alla casella "<< p->pos()<< ".\n";
}

//Function to remove a defeated player's properties
void Game::reset_properties(Player* p)
{
    std::vector<int> property_list = p->get_properties();   //The player's properties are stored in a vector
    for(int i=0; i<property_list.size() ; i++)
    {
        b->get_value(i).sell_property();    //The properties in the vector are sold
    }
    std::cout<<"Giocatore "<< p->num()<< " ha donato le sue proprietà alla banca in seguito alla bancarotta.\n";
    out<<"Giocatore "<< p->num()<< " ha donato le sue proprietà alla banca in seguito alla bancarotta.\n";
}

//Function to buy a terrain
bool Game::buy_terrain(Player* p)
{
    if(p->buy_intent() && (b->get_value(p->pos())).return_owner()==0)   //If the player wants to buy the terrain and the terrain is not owned by anyone
    {
        (b->get_value(p->pos())).buy_property(p->num());    //The terrain is bought
        p->decrease_balance((b->get_value(p->pos())).terrain_price());  //The player's balance is decreased
        std::cout<<"Giocatore "<< p->num()<< " ha acquistato il terreno "<< p->pos()<<".\n";
        out<<"Giocatore "<< p->num()<< " ha acquistato il terreno "<< p->pos()<<".\n";
        return true;
    }
    return false;
}

//Function to upgrade a building
bool Game::upgrade(Player* p)
{
    if(p->upgrade_intent() && (b->get_value(p->pos())).return_owner()==p->num())    //If the player wants to upgrade the building and the building is owned by the player
    {
        (b->get_value(p->pos())).upgrade_building();    //The building is upgraded
        if((b->get_value(p->pos())).building_type()==Building::House)
        {
            p->decrease_balance((b->get_value(p->pos())).house_price());    //The player's balance is decreased by the price of a house
            std::cout<<"Giocatore "<< p->num()<< " ha costruito una casa sul terreno "<< p->pos()<<".\n";
            out<<"Giocatore "<< p->num()<< " ha costruito una casa sul terreno "<< p->pos()<<".\n";
            return true;
        }
        if((b->get_value(p->pos())).building_type()==Building::Hotel)
        {
            p->decrease_balance((b->get_value(p->pos())).hotel_price());    //The player's balance is decreased by the price of a hotel
            std::cout<<"Giocatore "<< p->num()<< " ha migliorato una casa in albergo sul terreno "<< p->pos()<< ".\n";
            out<<"Giocatore "<< p->num()<< " ha migliorato una casa in albergo sul terreno "<< p->pos()<< ".\n";
            return true;
        }
    }
    return false;
}

//Function to return a player object from its number
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

//Function to pay the stay at another player's property
bool Game::pay_stay(Player* p)
{
    if((b->get_value(p->pos())).return_owner()!=0 && (b->get_value(p->pos())).return_owner()!=p->num()) //If the property is owned by another player
    {
        if((b->get_value(p->pos())).building_type()==Building::House)   //If the property has a house
        {
            if(p->budget()>((b->get_value(p->pos())).accomodation_house_price()))   //If the player has enough money to pay the stay
            {
                p->decrease_balance((b->get_value(p->pos())).accomodation_house_price());   //The player's balance is decreased
                (return_player(b->get_value(p->pos()).return_owner()))->increase_balance((b->get_value(p->pos())).accomodation_house_price());  //The owner's balance is increased
                std::cout<<"Giocatore "<< p->num()<< " ha pagato "<< ((b->get_value(p->pos())).accomodation_house_price())<< " fiorini a giocatore "<< (b->get_value(p->pos()).return_owner())<< " per pernottamento in una casa nella casella "<< p->pos()<< ".\n";
                out<<"Giocatore "<< p->num()<< " ha pagato "<< ((b->get_value(p->pos())).accomodation_house_price())<< " fiorini a giocatore "<< (b->get_value(p->pos()).return_owner())<< " per pernottamento in una casa nella casella "<< p->pos()<< ".\n";
                return true;
            }
            else    //If the player doesn't have enough money to pay the stay
            {
                std::cout<<"Giocatore "<< p->num()<< " non aveva abbastanza soldi per pagare giocatore "<< (b->get_value(p->pos()).return_owner())<< " e ha speso gli ultimi "<< p->budget()<< " fiorini.\n";
                out<<"Giocatore "<< p->num()<< " non aveva abbastanza soldi per pagare giocatore "<< (b->get_value(p->pos()).return_owner())<< " e ha speso gli ultimi "<< p->budget()<< " fiorini.\n";
                p->decrease_balance(p->budget());   //The player's balance is decreased by the amount of money he has left
                (return_player(b->get_value(p->pos()).return_owner()))->increase_balance(p->budget());  //The owner's balance is increased by the amount of money the player has left
                return false;
            }
        }
        if((b->get_value(p->pos())).building_type()==Building::Hotel)   //If the property has a hotel
        {
            if(p->budget()>((b->get_value(p->pos())).accomodation_hotel_price()))   //If the player has enough money to pay the stay
            {
                p->decrease_balance((b->get_value(p->pos())).accomodation_hotel_price());   //The player's balance is decreased
                (return_player(b->get_value(p->pos()).return_owner()))->increase_balance((b->get_value(p->pos())).accomodation_hotel_price());  //The owner's balance is increased
                std::cout<<"Giocatore "<< p->num()<< " ha pagato "<< (b->get_value(p->pos())).accomodation_hotel_price()<< " fiorini a giocatore "<< (b->get_value(p->pos()).return_owner())<< " per pernottamento in Hotel nella casella "<< p->pos()<< ".\n";
                out<<"Giocatore "<< p->num()<< " ha pagato "<< (b->get_value(p->pos())).accomodation_hotel_price()<< " fiorini a giocatore "<< (b->get_value(p->pos()).return_owner())<< " per pernottamento in Hotel nella casella "<< p->pos()<< ".\n";
                return true;
            }
            else    //If the player doesn't have enough money to pay the stay
            {
                std::cout<<"Giocatore "<< p->num()<< "non aveva abbastanza soldi per pagare giocatore "<< (b->get_value(p->pos()).return_owner())<< " e ha speso gli ultimi "<< p->budget()<< " fiorini.\n";
                out<<"Giocatore "<< p->num()<< "non aveva abbastanza soldi per pagare giocatore "<< (b->get_value(p->pos()).return_owner())<< " e ha speso gli ultimi "<< p->budget()<< " fiorini.\n";
                p->decrease_balance(p->budget());   //The player's balance is decreased by the amount of money he has left
                (return_player(b->get_value(p->pos()).return_owner()))->increase_balance(p->budget());  //The owner's balance is increased by the amount of money the player has left
                return false;
            }
        }
    }
    std::cout<<"La casella e' di proprieta' di "<<(b->get_value(p->pos()).return_owner()) <<" ma, senza alcun edificio, il transito e' gratuito.\n";
    out<<"La casella e' di proprieta' di "<<(b->get_value(p->pos()).return_owner()) <<" ma, senza alcun edificio, il transito e' gratuito.\n";
    return true;    //If there are no buildings on the property, the stay is free
}

//Function to throw two dices
std::pair<int, int> Game::throw_dices()
{
    dice1=throw_dice(6);
    dice2=throw_dice(6);
    return std::make_pair(dice1, dice2);
}

//Function to check if the dices are equal
bool Game::check_dices()
{
    return(dice1==dice2);
}

//Function to play the game
void Game::game()
{
    bool done=false;
    std::vector<int> po = player_order();
    std::cout<< "L'ordine dei giocatori e': "<<po[0]<< " "<< po[1]<< " "<< po[2]<< " "<< po[3]<< ".\n";
    out<< "L'ordine dei giocatori e': "<<po[0]<< " "<< po[1]<< " "<< po[2]<< " "<< po[3]<< ".\n";
    int player_count=4;
    int round_count=0;  //The round count increases every time all the players have played a turn
    int turn_count=1;   //The turn count increases every time a player has played a turn
    bool in_turn;       //The in_turn variable is true when a player is playing
    Player* curr;
    dice1=0;
    dice2=1;
    while(!done)
    {
        for(int i=0; i<4; i++)
        {
            if(i==0)
            {
                round_count++;      //The round count increases every time all the players have played a turn
            }
            if(return_player(po[i])->is_playing())
            {    
                curr= return_player(po[i]);
                in_turn=true;
            }
            if(player_count!=1 && return_player(po[i])->is_playing())
            {
                std::cout<<"|-------------------------------------Giocatore "<<curr->num()<<", Turno "<< round_count<<"-------------------------------------|\n";
                out<<"|-------------------------------------Giocatore "<<curr->num()<<", Turno "<< round_count<<"-------------------------------------|\n";
            }
            if(player_count==1)     //If there is only one player left, he wins
            {
                for(int i = 0; i < 4; i++)      //The player that has not been eliminated is found
                {
                    if(return_player(po[i])->budget()>0)
                        curr = return_player(po[i]);
                }
                i=4;
                std::cout<< "Giocatore "<< curr->num()<< " ha vinto la partita.\n";
                out<< "Giocatore "<< curr->num()<< " ha vinto la partita.\n";
                done=true;
                in_turn=false;
                std::cout<< curr->budget()<< " fiorini.\n";
                out<< curr->budget()<< " fiorini.\n";
            }
            while(in_turn)
            {
                if(check_dices())   //If the dices are equal, the player plays another turn
                {
                    std::cout<< "Giocatore "<< curr->num()<< " ha ottenuto un lancio doppio e svolgera' un altro turno.\n";
                    out<< "Giocatore "<< curr->num()<< " ha ottenuto un lancio doppio e svolgera' un altro turno.\n";
                }
                std::pair<int, int> dices = throw_dices();
                std::cout<<"Giocatore "<< curr->num()<< " ha tirato i dadi ottenendo un valore di "<< dices.first<<" + "<< dices.second<< " = "<< dices.first+dices.second<< ".\n";
                out<<"Giocatore "<< curr->num()<< " ha tirato i dadi ottenendo un valore di "<< dices.first<<" + "<< dices.second<< " = "<< dices.first+dices.second<< ".\n";
                in_turn = check_dices();
                int start_pos= curr->pos();
                move_player(curr, (dices.first + dices.second));
                std::cout<<*b;
                int end_pos= curr->pos();
                std::cout<< curr->budget()<< " fiorini.\n";
                if(end_pos<start_pos)   //If the player has crossed the "go" cell, he gets 20 florins
                {
                    cross_go(curr);
                    std::cout<<"(+20) -> "<< curr->budget()<< " fiorini.\n";
                }
                //If the player has landed on a property, he can buy it or upgrade it
                //The player is the owner of a valid cell, he can afford the upgrade, and there isn't an hotel already on the property
                if(b->get_value(curr->pos()).return_owner()==(curr->num()) && curr->pos()!=0 && curr->pos()!=7 && curr->pos()!=14 && curr->pos()!=21 && (curr->budget()>=(b->get_value(curr->pos())).price()) && (b->get_value(curr->pos())).building_type()!=Building::Hotel)
                {
                    if(upgrade(curr))
                    {
                        std::cout<<"(-"<< b->get_value(curr->pos()).price() <<") -> "<< curr->budget()<< " fiorini.\n";
                    }
                }
                //The terrain is not owned by anyone, the player can afford it, and it is not a special cell
                if(b->get_value(curr->pos()).return_owner()==0 && curr->pos()!=0 && curr->pos()!=7 && curr->pos()!=14 && curr->pos()!=21 && curr->budget()>=(b->get_value(curr->pos())).terrain_price() && b->get_value(curr->pos()).building_type()==Building::None)
                {
                    if(buy_terrain(curr))
                    {
                        std::cout<<"(-"<< b->get_value(curr->pos()).terrain_price() <<") -> "<< curr->budget()<< " fiorini.\n";
                    }
                }
                //If the player has landed on a property owned by another player, he pays the stay
                if((b->get_value(curr->pos()).return_owner())!=0 && (b->get_value(curr->pos()).return_owner())!=curr->num())
                {
                    if(pay_stay(curr))  //If the player has enough money to pay the stay
                    {
                        if((b->get_value(curr->pos())).building_type()==Building::House)
                        {
                            std::cout<<"(-"<< (b->get_value(curr->pos())).accomodation_house_price() <<") -> "<< curr->budget()<< " fiorini.\n";
                            std::cout<<"Giocatore "<<(return_player(b->get_value(curr->pos()).return_owner()))->num() <<" (+"<< (b->get_value(curr->pos())).accomodation_house_price() <<") -> "<< (return_player(b->get_value(curr->pos()).return_owner()))->budget()<< " fiorini.\n";
                        }
                        else if((b->get_value(curr->pos())).building_type()==Building::Hotel)
                        {
                            std::cout<<"(-"<< (b->get_value(curr->pos())).accomodation_hotel_price() <<") -> "<< curr->budget()<< " fiorini.\n";
                            std::cout<<"Giocatore "<<(return_player(b->get_value(curr->pos()).return_owner()))->num() <<" (+"<< (b->get_value(curr->pos())).accomodation_hotel_price() <<") -> "<< (return_player(b->get_value(curr->pos()).return_owner()))->budget()<< " fiorini.\n";
                        }
                    }
                    else    //If the player doesn't have enough money to pay the stay
                    {
                        player_count--;
                        std::cout<<"Giocatore " << curr->num() << " e' stato eliminato.\n";
                        out<<"Giocatore " << curr->num() << " e' stato eliminato.\n";
                        reset_properties(curr);         //The player's properties are sold
                        curr->end_game();               //The player is eliminated
                        in_turn=false;
                    }
                }
            }
            if(return_player(po[i])->is_playing())
            {
                std::cout<<"Giocatore " << curr->num() << " ha finito il turno.\n";
                out<<"Giocatore " << curr->num() << " ha finito il turno.\n";
                turn_count++;
                std::string cmd;
                std::cout<<"Inserire 'show' per visualizzare le proprieta' dei giocatori.\nInserire 'end' per terminare il gioco e dichiarare il piu' ricco come vincitore.\nLasciare vuoto per continuare.\n";
                std::getline(std::cin, cmd);
                if(cmd=="show")     //If the user wants to see the properties of the players
                {
                    for(int j=0; j<4; j++)
                    {
                        std::vector<int> property_list = return_player(j+1)->get_properties();
                        if(property_list.size()>0)
                        {
                            std::cout<<"Proprieta' Giocatore "<< j+1<< ": ";
                            for(int k=0; k<property_list.size(); k++)
                            {
                                std::cout<< property_list[k]<< " ";
                            }
                            std::cout<< "\n";
                        }
                        else
                        {
                            std::cout<<"Giocatore "<< j+1<< " non possiede proprieta'.\n";
                        }
                    }
                    std::cin.ignore();
                }
                if(cmd=="end")  //If the user wants to end the game
                {
                    turn_count=101;
                }
                if(cmd=="")
                {}
            }
            if(i==3)    //resets the loop for the player order
            {
                i==0;
            }
            if(turn_count>100)  //Ends the game automatically after a set number of turns
            {
                int richest = 0;
                int winner = 0;
                for(int i=0;i<4; i++)   //Finds the richest player
                {
                    curr = return_player(i+1);
                    if(curr->budget()>richest)
                    {
                        richest=curr->budget();
                        winner=curr->num();
                    }
                }
                for(int i=0; i< 4; i++) //Checks if there are any ties, and declares the winner(s)
                {
                    curr = return_player(i+1);
                    if(curr->budget()==return_player(winner)->budget())
                    {
                        std::cout<<"Giocatore "<< curr->num()<< " ha vinto la partita.\n";
                        out<<"Giocatore "<< curr->num()<< " ha vinto la partita.\n";
                    }
                }
                for(int i=0; i< 4; i++) //Prints the budget of each player
                {
                    curr = return_player(i+1);
                    std::cout<<"Giocatore "<< curr->num()<< ": "<< curr->budget()<< " fiorini.\n";
                    out<<"Giocatore "<< curr->num()<< ": "<< curr->budget()<< " fiorini.\n";
                }
                i=4;
                done=true;
            }
        }
    }
    out.close();
}
