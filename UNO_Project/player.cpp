//this file contains the implimentation of the member functions of the player class

#include "player.h"
#include <iostream>
#include <string.h>

using namespace std;


//implimentation of default player constructor
Player::Player(){
    mNum = 0; //the player does not have a number yet
    mName = ""; //the player also does not have a name
    pLeft = nullptr; //pLeft isn't created, so this points to nothing
    pRight = nullptr; //pRight also hasn't been created, so this points to nothing either
    Hand = nullptr; //their hand is currently empty, so this points to nothing as well
}

//implimentation of parametrized player constructor
Player::Player(const int NUMBER, const string NAME){
    mNum = NUMBER; //the player has a defined number
    mName = NAME; //the player should have a defined name
    
}

//implimentation of player destructor
Player::~Player(){
    pLeft = nullptr;
    pRight = nullptr;
    delete Hand; //the only dynamically allocated part of player, calling delete hand will call the destructor of the deck class for the player's hand
    Hand = nullptr; //once hand has been deleted, we also need to prevent a dangling pointer error by making it a nullptr
}

//implimentation of mNum getter
int Player::getNum() const{
    return mNum;
}

//implimentation of mNum setter
void Player::setNum(const int NEW_NUM){
    mNum = NEW_NUM;
}

//implimentation of mName getter
string Player::getName() const{
    return mName;
}

//implimentation of mName setter
void Player::setName(const string NEW_NAME){
    mName = NEW_NAME;
}

//implimentation of left player getter
Player* Player::getLeftPlayer() const{
    return pLeft;
}

//implimentation of left player setter
void Player::setLeftPlayer( Player* const NEW_LEFT_PLAYER){ //this means that in this context,  NEW_LEFT_POINTER cannot change what it is pointing to, so this is allowed. However if it was const Player* there would be an error because it would say that the player was constant and couldn't change, and that is not what pLeft and pRight are
    pLeft = NEW_LEFT_PLAYER;
}

//implimentation of right player getter
Player* Player::getRightPlayer() const{
    return pRight;
}

//implimentation of right player setter
void Player::setRightPlayer(Player* const NEW_RIGHT_PLAYER){
    pRight = NEW_RIGHT_PLAYER;
}

//implimentation of hand getter 
Deck* Player::getHand() const{
    return Hand;
}

//implimentation of hand setter
void Player::setHand(Deck* const NEW_HAND){
    Hand = NEW_HAND;
}

//implimentation of playCard function:
    //notes: this literally just checks if they can play the card, and if they can removes it from their hand and returns it, if they can't it will return 
Card Player::playCard(const Card TOP_CARD){

    //this prints out the player's hand, with numbers corresponding to the index of each card so that the player can choose which to play
    cout<<mName<<", your cards in order are as follows:"<<endl; 
    Hand->printDeck(); 
    
    //now that the players' cards are printed, they can choose to either play one or draw a card and skip their turn.
    //if they choose to draw a card, then no card will be removed from their hand, and the program will make them draw a card
    //this will be done by making a card that exclusively means they are gonna draw, and then the game will add a card to their hand and tell them what it is
    int PlayCard;
    string response;
    Card cardChoice('N', '1'); //initialized to this, but will change if the player chooses to play a card instead of drawing

    
    if(TOP_CARD.value == 'D' || TOP_CARD.value == 'C'){
        string top_color = "The top card is a wildcard, and the color has been set to ";
        switch (TOP_CARD.color){
            case 'R': {
                top_color+="Red ";
                break;
            }

            case 'G':{
                top_color+= "Green ";
                break;
            }

            case 'B':{
                top_color+= "Blue ";
                break;
            }

            case 'Y':{
                top_color+= "Yellow ";
                break;
            }
        }
        cout<<top_color<<endl;
        
    }

    else {cout<<"The top card right now is a "; TOP_CARD.printCard(); }
    

while (true){ //we will make the player choose a card to play (or not to play a card) until this loop is broken, indicating that they have either chosen to draw or chosen a valid card
    cout<<"Do you have a card to play? (enter yes/no)"<<endl;
    cin>>response;
    
    //convert response to be all uppercase
    for(int i = 0; i<response.length(); i++){
        response[i] = toupper(response[i]);
    }
    //now that response has been converted, we can check if the user chose to draw a card
    if(response != "YES") return cardChoice; //if they didn't want to play a card, they will be drawing

    //otherwise, we will ask which card the user wants to play
    cout<<"Enter the number of the card you would like to play: ";
    cin>>PlayCard;
    while(cin.fail() || PlayCard < 1 || PlayCard > Hand->getSize()){ //remember Hand is a pointer, so we need to dereference it before calling any methods
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"That card doesn't exist... enter a different number card"<<endl;
        cin>>PlayCard;
    }
    if(Hand->getCard(PlayCard-1).checkCanPlay(TOP_CARD)){//this checks if the chosen card can be played or not
        cardChoice = Hand->getCard(PlayCard-1);
        Hand->removeCard(PlayCard-1); //this removes the played card from the player's hand
        cout<<endl;
        return cardChoice;
    }
    else{ //if we've gotten here, they played a card that they aren't allowed to, so we tell them that and then restart the loop
        cout<<"Whoops! You can't play a "; Hand->getCard(PlayCard-1).printCard();
        cout<<endl;
    }
    }
    //at this point the function should've returned, because since the while loop has ended the player must have either played a valid card or chosen to draw one.
}
