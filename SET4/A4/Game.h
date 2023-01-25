#ifndef GAME_H
#define GAME_H
// here we will make the struct of the game, which is a circular doubly linked list

#include "Player.h"

struct Game{
    int num_players; //the number of players playing
    int players_with_chips; // keeps track of players with chips to know when the game ends
    bool direction = true; //direction starts off to the left, meaning that until it switches current player will become its pLeft after its turn.
    int center_chips = 0; //the center chips starts off at zero
    Player* current_player;
    
    
    /**
    * @brief this function makes a single player with a number
    * @param NUMBER number is the number player it is
    * @return it returns a pointer to the recently created player
    */

    Player* MakePlayer(const int NUMBER);


    /**
    * @brief this function uses MakePlayer to make the players of the game, and their order
    * @param NUM_PLAYERS this is the number of players that will be made
    * @return this returns a pointer to the first player, so that we know where the game will start
    */
    Player* MakeList(const int NUM_PLAYERS); 
};

#endif