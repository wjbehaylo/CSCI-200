#include "Game.h"
#include "Player.h"

Player* Game::MakePlayer(const int NUMBER){
    Player* pPlayer = new Player;
    pPlayer->set_player_num(NUMBER);
    return pPlayer;
}

Player* Game::MakeList(const int NUM_PLAYERS){
    Player* first_player; //this is for the first player we make, because we don't yet know who to point to 
    Player* recent_player; //this is for the most recent player made that is not the one currently being made, so we know where it's pLeft(next) and the new Player's pRight should point
    Player* new_player; //this is for the player currently being made
    for(int i = 1; i<NUM_PLAYERS+1; i++){
        if (i == 1){
            first_player = MakePlayer(i); //make the first player, no knowledge of where to point yet
            recent_player = first_player; //before moving on to the next player, record that the first player was the most recent
            continue;
        }
        if (i == NUM_PLAYERS){ //if we are on the last player, now we know where it's pRight should point and the first player's pLeft should point
            new_player = MakePlayer(i);
            new_player->set_pRight(recent_player); //the new player's last player was player i-1
            recent_player->set_pLeft(new_player);  //last player's next player is the new player
            new_player->set_pLeft(first_player);   //because we're at the end, we also know that the next player after the new player is the first player
            first_player->set_pRight(new_player);  //therefore the player before the first player is the new player
            return first_player;
        }
        new_player = MakePlayer(i);
        recent_player->set_pLeft(new_player);
        new_player->set_pRight(recent_player);
        recent_player = new_player;
    }

}
