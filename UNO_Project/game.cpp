#include "game.h"
using namespace std;
//implimentation of member functions of game class

//implimentation of mMakePlayer. Note that NUM will go from 0-numPlayers-1, so when we reference the player number we need to add one to it
Player* Game::mMakePlayer(const int NUM){
    string name;
    cout<<"Player "<<NUM<<", please enter your desired username: ";
    cin>>name;
    cin.ignore(1000,'\n');
    Player* newPlayer = new Player(NUM, name);
    return newPlayer;
}

Game::Game(const int NUM_PLAYERS, Deck& deck){
    Player* first_player;
    Player* recent_player;
    Player* new_player;
    numPlayers = NUM_PLAYERS;
    players_with_uno = new Player*[NUM_PLAYERS]; //players with uno is a pointer to an array of pointers to players with uno, with each index coreesponding to a player
    for(int i = 0; i<NUM_PLAYERS; i++){ players_with_uno[i] = nullptr;} //each player's slot is initialized to a nullptr, because none start with UNO.
    main_deck = new Deck(deck); // main deck is intialized to a copy of the input deck
    discard_pile = new Deck(); //discard pile is initialized to an empty deck
    Deck* hand;
    

    rotation = true;
    
    //now we have to make our circularly linked list of players, initialize their hands and names, and which players are to the left and right of them
    for(int i = 1; i<NUM_PLAYERS+1; i++){
        //each player will need to have their own hand
        hand = new Deck; //this will store each players hand as it is built
        for (int j = 0; j<7; j++) 
            {hand->addCard(main_deck->draw());} //we need to draw 7 cards from the main deck for each player's hand
        if(i ==1){ //if it is the first player, 
            first_player = mMakePlayer(i); //creates a new player with num1, gets and gives their name
            first_player->setHand(hand); //makes the new players hand a pointer to the intialized hand
            recent_player = first_player;
            current_player = first_player; //the initial current player will be the first player
            continue;
        }
        else if(i == NUM_PLAYERS){ // if it is the last player
            new_player = mMakePlayer(NUM_PLAYERS); //makes a new player
            new_player->setHand(hand); //gives them a hand

            new_player->setRightPlayer(recent_player); //makes the player to the right of them the most recent player (we are moving clockwise)
            recent_player->setLeftPlayer(new_player); //makes it so that the recent player's next player is this player
            new_player->setLeftPlayer(first_player); //the player after the last player is the first player
            first_player->setRightPlayer(new_player); //the player before the first player is the last player
            continue;
        }
        else {//if we are not working with the first or last players, we only know the player before our current player
            new_player = mMakePlayer(i);
            new_player->setHand(hand);
            new_player->setRightPlayer(recent_player); //makes the new player point back to the most recent player
            recent_player->setLeftPlayer(new_player); //makes the most recent player point to this player also
            recent_player = new_player; //now the most recent player is the new player
            continue;
        }
    }
    //now that the players have been initialized, all that is left is to draw the top card from the deck
    top_card = main_deck->draw(); // the copy assignment operator means that top_card should now have the same values as whatever is drawn from maindeck
}
//destructor implimentation, delete the decks and then delete the players aswell
Game::~Game(){
    delete main_deck;
    delete discard_pile;

    //now we need to destruct all the players
    Player* next_player = current_player->getLeftPlayer();
    while(next_player != nullptr){ //run until we reach the end of the loop, at which point the next_player will be a pointer to the first player, which has been deleted
        delete current_player;
        current_player = next_player;
        next_player = next_player->getLeftPlayer();
    }
    delete current_player; //all that we would be left with is the final player, which we then delete
    //at this point the decks and all players have been deallocated
}


//implimentation for numPlayers getter
int Game::getNumPlayers() const{
    return numPlayers;
}

//implimentation for numPlayers setter
void Game::setNumPlayers(const int NUM){
    numPlayers = NUM;
}

//implimentation for shuffle, before it is called there will be a check that discard pile has cards
void Game::shuffle(){ //
    *main_deck = *discard_pile; //idk if this is gonna work honestly, because I'm confused on how the operator overload will work between them since they're references
    delete discard_pile; //emptires the discard pile
}

//implimentation for getDeck
Deck* Game::getDeck() const{
    return main_deck;
}

//implimentation for setDeck, here the pointer can't be constant because what points to it is being changed
void Game::setDeck(Deck* DECK){
    main_deck = DECK;
}

//implimentation for getDiscard
Deck* Game::getDiscard() const{
    return discard_pile;
}

//implimentation for setDiscard, as above the pointer can't be constant because whats pointing to it is changing
void Game::Discard(const Card CARD){
    discard_pile->addCard(CARD);
}

void Game::Draw(const int NUM_CARDS){
    for(int i = 0; i<NUM_CARDS; i++){
        if (main_deck->getSize() == 0){//if the deck is empty, we need to shuffle in the discard.
            shuffle();
        }
        current_player->getHand()->addCard(main_deck->draw()); //adds a card to the players hand that is the drawn card from the main deck
        
    }
    //at this point the player has drawn an adequate amount of cards
}

//implimentation of getter for rotation
bool Game::getRotation() const{
    return rotation;
}

//implimentation of setter for rotation
void Game::switchRotation(){
    rotation = !rotation;
}

//implimentation of get current_player
Player* Game::getCurrentPlayer()const{
    return current_player;
}
bool Game::gameOver() const{
    if( current_player->getHand()->getSize() == 0) return true;
    else return false;
}
//implimentation of unoUpdate
void Game::unoUpdate(){
    if(current_player->getHand()->getSize() == 1){ //if the size of the current player's hand is one, their place in the players with uno array is filled with a pointer to them
        players_with_uno[current_player->getNum()-1] = current_player; //if the hand of the current player has one card in it, make its place in players_with_uno a pointer to it
    }
    else if(current_player->getHand()->getSize()!= 1){
        players_with_uno[current_player->getNum()-1] = nullptr; //they don't have uno, make that reflected in the record of which players do have UNO
    }
}

void Game::unoAlert(){
    for(int i = 0; i<numPlayers; i++){
        if(players_with_uno[i] != nullptr){ //if player (i+1) has uno, print out their name
            cout<<players_with_uno[i]->getName()<<" has Uno"<<endl;
        }
    }
}

//implimentation of set current_player
void Game::switchCurrentPlayer(){
    if(rotation){
        current_player = current_player->getLeftPlayer();
    }
    else current_player = current_player->getRightPlayer();
}

//implimentation of top card getter
Card Game::getTopCard() const{
    return top_card;
}

//implimentation of top card setter
void Game::setTopCard(const Card NEW_TOP){
    top_card = NEW_TOP;
}

void Game::chooseColor(){
    char color_choice;
    cout<<"The color options to chose from are Red, Blue, Green, and Yellow."<<endl;
    cout<<"Please enter the first letter of the color you would like to choose: ";
    cin>>color_choice;
    color_choice = toupper(color_choice);
    cin.ignore(10000,'\n');
    Card new_top(top_card.value, color_choice);
    setTopCard(new_top);
}
