#ifndef GAME_H
#define GAME_H

//this is where we document the game class, which is where the game actually happens
#include<iostream>
#include "deck.h"
#include "player.h"
#include "card.h"
#include <vector>
using namespace std;

class Game{
    private:
        //stores the number of players in the game
        int numPlayers;

        //a pointer to the main deck
        Deck* main_deck;

        //this is a list of pointers to the players with uno, which each corresponding to an individual player
        Player** players_with_uno;
        //a pointer to the discard pile
        Deck* discard_pile;

        //the current top card
        Card top_card;

        //which way the game is rotating, if true it means we are going clockwise (so pLeft is the next player), otherwise counterclockwise so pRight is the next player
        bool rotation; 

        // this a pointer to the current player, starts with player mNum 0 (player 1) 
        Player* current_player;

        /**
        * @brief makes a player with a number
        * @param NUM the number the player will be initialized with
        * @return returns a pointer to the player that was created
        */
        Player* mMakePlayer(const int NUM);

    public:

        /**
        * @brief the parametrized constructor for the game, no need for a default constructor because it will not be used. Only thing we need to construct is the number of players
        * @param NUM_PLAYERS the number of players planning on playing the game.
        * @param deck a deck all of the UNO cards that will be in the game
        */
        Game(const int NUM_PLAYERS, Deck& deck);

        /**
        * @brief the destructor for the game, calls destructors for each player and the game's deck
        */
        ~Game();



        /**
        * @brief getter function for numPlayers
        * @return returns the number of players
        */
        int getNumPlayers() const;

        /**
        * @brief setter function for numPlayers
        * @param NUM the number of playeres there will now be
        */
        void setNumPlayers(const int NUM);

        /**
        * @brief shuffle function, if players try to draw when the deck is empty the discard becomes the deck, unless discard is empty, in which case game tells player to play the game normally and quits
        */
        void shuffle();

        /**
        * @brief getter function for the main deck
        * @return returns a pointer to the main deck
        */
        Deck* getDeck() const;

        /**
        * @brief setter function for main deck
        * @param DECK makes main deck point to a new deck
        */
        void setDeck(Deck* DECK);

        /**
        * @brief getter function for the discard pile
        * @return returns a pointer to the discard pile
        */
        Deck* getDiscard() const;

        /**
        * @brief setter function for discard pile
        * @param CARD new discard pile to be pointed at
        */
        void Discard(const Card CARD);
        
        /**
        * @brief makes the current player draw a certain number of cards
        * @param NUM_CARDS the number of cards the player needs to draw
        */
        void Draw(const int NUM_CARDS);

        /**
        * @brief getter function for rotation
        * @return returns the bool value of the rotation (indicates left is next if true, otherwise false)
        */
        bool getRotation() const;

        /**
        * @brief after a reverse is played, switches the direction of play
        */
        void switchRotation();

        /**
        * @brief getter function for the current player
        * @return returns a pointer to the current player
        */
        Player* getCurrentPlayer() const;

        /**
        * @brief this checks if the current player has 0 cards in their hand, in which case the game ends
        */
        bool gameOver() const;
        
        /**
        * @brief this checks if the current player has one card in their hand, in which case they are added to the list of players with UNO. If they don't and they were on the list, the no-longer do. Keeps track of which players do and do not have UNO.
        */
        void unoUpdate();

        /**
        * @brief this prints out the names of all players that currently have uno
        */
        void unoAlert();

        /**
        
        */

        /**
        * @brief used to change whose turn it is, changes the current player based on the direction the game is rotating
        */
        void switchCurrentPlayer();

        /**
        * @brief a getter function for the current top card
        * @return returns the current top card
        */
        Card getTopCard() const;

        /** 
        * @brief setter function for the top card
        * @param NEW_TOP the new top card
        */
        void setTopCard(const Card NEW_TOP);

        /**
        * @brief a function called when the player plays a wild card, makes the color of the top card the user's choice
        */
        void chooseColor();


};

#endif


