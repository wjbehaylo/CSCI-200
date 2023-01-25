#ifndef DECK_H
#define DECK_H

//this is the documentation file for the deck of uno cards that will be used

#include "card.h" //the deck is composed of cards
#include <cstdlib> // this library is necessary to include for the random function
#include <iomanip>
#include <string.h>
using namespace std;

//deck is a generic structure to store cards within, it will be used for our list of all cards, our actual game deck, our discard/play pile, and the hands of players
class Deck{
    private:
        
        //this data member represents the size of the deck
        int mSize;

        //this data member is a dynamically allocated array which contains the cards
        Card* mCards;
    public:
    

        /**
        * @brief this is the default constructor for the deck, which sets mSize to 0 and makes mCardss a nullptr
        */
        Deck();


        /**
        * @brief this is the copy constructor for the deck, which makes the deck a deep copy of another deck
        * @param OTHER this is the other deck that will be copied
        */
        Deck(Deck &OTHER);

        /**
        * @brief this is the copy assignment operator, which makes one deck a copy of the other, and in our case this will only be used with making the deck the discard pile when it is empty, so we also empty the other deck
        * @param other this is the deck which will be copied and then emptied
        * @return there is no return value because the changes are made to this within the function
        */
        void operator=(Deck& other);

        /**
        * @brief this is the destructor for the deck, which makes the size 0 and deallocates mCards
        */
        ~Deck();

        /**
        * @brief this is a getter function for the size of the deck
        * @return this function returns the integer value of the size of the deck
        */
        int getSize() const;

        /**
        * @brief this is a setter function for the size of the deck
        * @param NEWSIZE this parameter represents what the new size of the deck will be
        */
        void setSize(const int NEWSIZE);

        /**
        * @brief this is the draw function of the program, which removes a card from the deck and returns it so that it can be added to a player's hand
        * @return this returns a pointer to a random card from the deck
        */
        Card draw();

        /** 
        * @brief this function gets value of a specific card in a deck, so that that card can be accessed
        * @param POS this is the position of the card in the deck
        * @return returns a the value of a card in the deck at position POS
        */
        Card getCard(const int POS);



        /**
        * @brief this function takes a card as input and adds it to the end of the deck
        * @param NEW_CARD this is the new card that will be added to the deck
        */
        void addCard(const Card NEW_CARD);

        /**
        * @brief this function removes a card from an index of the deck, and changes the deck based on that
        * @param POS this is the position that the card will be removed from
        */
        void removeCard(const int POS);

        /**
        * @brief this function prints the cards in the deck, calling the print function for each
        */
        void printDeck();

};

#endif