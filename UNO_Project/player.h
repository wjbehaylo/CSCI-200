#ifndef PLAYER_H
#define PLAYER_H

//in this file we will be documenting the player datatype
#include "deck.h"
#include "card.h"
#include <iostream>
#include <string>
using namespace std;

class Player{
    private:

    //the player will have both their number in the order, as well as their name
    int mNum;
    string mName;

    //the player will also have pointers to the players to the left and right of it, for the implimentation of the game's circularly linked list mechanics
    Player* pLeft;
    Player* pRight;
    
    //the player will also have a deck data structure representing their hand, which will have in it both their hand and the size of their hand
    Deck* Hand;

    public:
    
    /**
    * @brief this is the default constructor for a player, which makes their name empty, their number 0, their hand empty, and makes pLeft and pRight nullptrs
    */
    Player();

    /** 
    * @brief this is the parametrized constructor for a player, which makes their hand a certain size, sets pLeft and pRight, and sets their player number and name
    * @param NUMBER this is the number of the player in the order
    * @param NAME this is the name of the player that they selected
    */

    Player(const int NUMBER, const string NAME);

    /**
    * @brief this is the default destructor for the player class
    */
    ~Player();

    /**
    * @brief this is the getter function for the player's number
    * @return returns the player's number
    */
    int getNum() const;

    /**
    * @brief this is the setter function for the player's number
    * @param NEW_NUM this is the number that the mNum will be set to
    */
    void setNum(const int NEW_NUM);

    /**
    * @brief this is the getter function for the player's name
    * @return returns the player's name
    */
    string getName() const;

    /**
    * @brief this is the setter function for the player's name
    * @param NEW_NAME this is the string that pName will be set to
    */
    void setName(const string NEW_NAME);

    /**
    * @brief this is the getter function for the player to the left of this player
    * @return returns a pointer to the player to the left of this player
    */
    Player* getLeftPlayer() const;

    /**
    * @brief this is the setter function for the player to the left of this player
    * @param NEW_LEFT_PLAYER this is a pointer to the player that will now be the player to the left of the current player
    */
    void setLeftPlayer( Player* const NEW_LEFT_PLAYER);

    /**
    * @brief this is the getter function for the player to the right of this player
    * @return returns a pointer to the player to the left of this player
    */
    Player* getRightPlayer() const;

    /**
    * @brief this is the setter function for the player to the right of this player
    * @param NEW_RIGHT_PLAYER this is a pointer to the player that will now be the player to the right of the current player
    */
    void setRightPlayer(Player* const NEW_RIGHT_PLAYER);

    /**
    * @brief this is the getter function for the Deck containing the hand of this player
    * @return returns a pointer to the hand of the player
    */
    Deck* getHand() const;

    /**
    * @brief this is the setter function for the deck containing the hand of this player, 
    * @param NEW_HAND this is a pointer to the deck that will be the player's new hand
    */
    void setHand(Deck* const NEW_HAND);

    /**
    * @brief this is the key function of the program, in which based on the top card of the deck the player can choose a card from their hand to play(thus returning it and removing it from their hand)
    * @param TOPCARD this is a card representing the top card of the deck
    * @return this function returns the card that they choose to play
    */
    Card playCard(const Card TOP_CARD);


};

#endif