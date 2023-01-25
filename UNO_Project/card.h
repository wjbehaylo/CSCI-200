#ifndef CARD_H
#define CARD_H

//this file is where the card structure is documented
#include <string.h>
#include <iostream>
using namespace std;

struct Card{

    //this data member represents the type of the card:
    //it will say a number 1-9, +2, skip, switch, +4, or color (to represent color swap). *** I altered these to be chars for my switch statements
    char value;

    //this data member represents the color of the card, 
    //if the card is a wild card then it will contain W, meaning technically it is all colors
    char color;

    /**
    * @brief this is the default card constructor, which makes value and color empty
    */
    Card();

    /**
    * @brief this is the parametrized constructor, which sets value and color to the input parameters
    * @param VAL this is the value that the card's value will be set to
    * @param COLOR this is the color that the card's color will be set to
    */
    Card(const char VAL, const char COLOR);

    /**
    * @brief this is a copy assignment operator so that one card can become a copy of the other
    */
    void operator=(const Card& OTHER);


    /** 
    * @brief this function prints the card in a formatted way
    */
    void printCard() const;

    /**
    * @brief this function relates the current card to an input card, returning true if you could play the current card on top of the input card, false otherwise
    * @param CURRENT_TOP a card representing the current top card (to be played on top of or na)
    * @return returns true if the current card can be played on top of CHECK_CARD, false otherwise
    */
    bool checkCanPlay(const Card CURRENT_TOP);
};

#endif