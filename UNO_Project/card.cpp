//this is the implimentation of the member functions of the Card class

#include "card.h"
#include <iostream>
#include <string.h>
using namespace std;

//implimentation of card default constructor
Card::Card(){
    value = '0';
    color = '0';
}

Card::Card(const char VAL, const char COLOR){
    value = VAL;
    color = COLOR;
}

void Card::operator=(const Card& OTHER){
    color = OTHER.color;
    value = OTHER.value;
}

void Card::printCard() const{
    string CardName = "";
    switch (color){
        case 'R': {
            CardName+="Red ";
            break;
        }

        case 'G':{
            CardName+= "Green ";
            break;
        }

        case 'B':{
            CardName+= "Blue ";
            break;
        }

        case 'Y':{
            CardName+= "Yellow ";
            break;
        }

        case 'W':{ //no need to set color here, just say that it is a wild card
            CardName += "Wild ";
            break;
        }
    }
    switch  (value){
        case '1':{
            CardName += "1";
            break;
        }

        case '2':{
            CardName += "2";
            break;
        }

        case '3':{
            CardName += "3";
            break;
        }

        case '4':{
            CardName += "4";
            break;
        }

        case '5':{
            CardName += "5";
            break;
        }

        case '6':{
            CardName += "6";
            break;
        }

        case '7':{
            CardName += "7";
            break;
        }

        case '8':{
            CardName += "8";
            break;
        }

        case '9':{
            CardName += "9";
            break;
        }

        case 'd':{
            CardName += "+2";
            break;
        }

        case 's':{
            CardName += "Skip";
            break;
        }

        case 'r':{
            CardName += "Reverse";
            break;
        }

        case 'D':{
            CardName += "+4";
            break;
        }

        case 'C':{
            CardName += "Color Change";
            break;
        }
    }
    cout<< CardName<<endl;
}
 // we are checking if the card this function is called from can be played on top of the top card
bool Card::checkCanPlay(const Card CURRENT_TOP){
    if (color == 'W') return true; //if the desired card is a wildcard, it can always be played
    else if(color == CURRENT_TOP.color) return true;
    else if(value == CURRENT_TOP.value) return true;
    else return false;
}