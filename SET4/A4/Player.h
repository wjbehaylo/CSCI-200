#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Player {
private:
/**
* @brief this is the player's identification, to track which player's turn it is, whose next, etc
*/
int mPlayer;

/**
* @brief this is the number of chips that the current player has
*/
int mChips = 3; //the player always starts with 3 chips

/**
* @brief this is the player to the right of the current player, if direction is 
*/
Player* pRight;

/**
* @brief this is the player to the left of the current player
*/
Player* pLeft;

public:

/**
* @brief this gives a memory address to the pointer to the player to the right of the current player
* @param right_player is the address of the player to the right of the current player
*/
void set_pRight(Player* right_player);

/**
* @brief this getter functions gets the pointer to the player to the right of the current player
*/
Player* get_pRight();

/**
* @brief this gives a memory address to the pointer to the player to the left of the current player
* @param left_player is the address of the player to the right of the current player
*/
void set_pLeft(Player* left_player);

/**
* @brief this getter function gets the pointer to the player to the left of the current player
*/
Player* get_pLeft();

/** 
* @brief this is a getter function to get the number player that it is
* @return mPlayerNum
*/
int get_player_num();

/**
* @brief this is a setter function to initialize the player's number
*/
void set_player_num(const int PLAYER_NUM);

/**
* @brief this a getter function to get the number of chips that the player currently has
* @return returns the value of mChips, the number of chips that the player currently has
*/
int get_chips();

/**
* @brief this is a setter function to set the number of chips that a player has
* @param NUM_CHIPS this is the number of chips that the player will have
*/

void set_chips(const int NUM_CHIPS);

/**
* @brief this function takes a chip from the current player and gives it to another player, increasing the target's chips and decreasing the players chips
* @param DIRECTION is the direction (R = right, L = left) that the chip is given
*/
void give_player_chip(const char DIRECTION);

/**
* @brief this function takes a chip from the player and adds a chip to the center, 
*/
void give_center_chip();
};

#endif