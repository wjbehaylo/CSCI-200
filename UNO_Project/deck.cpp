#include "deck.h"
#include <typeinfo> //get rid of after
//default constructor
Deck::Deck(){
    mSize = 0;
    mCards = nullptr;
}

//copy constructor

Deck::Deck(Deck &OTHER){
    mSize = OTHER.mSize; //makes the sizes identical
    mCards = new Card[mSize]; //makes mCards point to a newly allocated array of cards, with size of the other size
    Card nextCard;

    //now we go through creating a copy, by making nextCard a copy of a card in OTHER at index i, then making index i of this a card with the same value
    for(int i = 0; i<mSize; i++){
        nextCard= OTHER.getCard(i);
        mCards[i] = nextCard;
    }
// at this point the deep copy has been completed, as each index of this contains the same card as each corresponding index of OTHER
}

//copy assignment operator, note that in the program this is used only when "shuffling" the discard to make a new deck, so other needs to be emptied in the process
void Deck::operator=(Deck& other){
    //this's size should be 0, so no need to set it to that beforehand
    mSize = other.mSize;

    //this's mCards should be pointing to an empty array (otherwise no need to reshuffle) so there is no need to deallocate the memory since it should've already been done
    mCards = new Card[mSize];

    Card nextCard;
    for(int i = 0; i<mSize; i++){
        nextCard.color = other.getCard(i).color;
        nextCard.value = other.getCard(i).value;
        //now that next card is a deep copy of the other deck's card, we can add it to this deck
        mCards[i] = nextCard;

    }
    //at this point  mCards has been made an array equal to what other was, so no need to return any values or anything, we just need to deallocate the other array
    other.mSize = 0;
    delete[] other.mCards; //deallocate other's size

    //we can exit the function
}

//implimentation of the deck destructor that is called at the end of the program
Deck::~Deck(){
    mSize = 0; //regardless of what size was, it is now 0
    delete[] mCards; //deletes the allocated array of mCards
    mCards = nullptr; //makes sure that mCards doesn't become a dangling pointer
}

//getter function for deck size
int Deck::getSize() const{
    return mSize;
}

//setter function for deck size
void Deck::setSize(const int NEWSIZE) {
    mSize = NEWSIZE;
}

//implimentation of draw function from deck
Card Deck::draw(){
    //index will be the randomly generated index we are getting the card from
    int index = rand()%mSize; //we get the value by modulating a random number with the size of the array
    
    //make the new card that will be drawn
    Card drawnCard = this->getCard(index);

    //remove the card that was drawn from the deck
    removeCard(index);

    return drawnCard;
}

//implimentation of getCard function from deck
Card Deck::getCard(const int POS){
    Card gottenCard(mCards[POS].value, mCards[POS].color);
    return gottenCard;
}

//implimentation of card adder function. We will be accessing values randomly, so it is unnecessessary to add it to a specific index ever
void Deck::addCard(const Card NEW_CARD){
    //because we are adding to the size of mCards, increase mSize
    mSize++;
    

    //make the new array that our array will eventually point to 
    Card* newmCards = new Card[mSize];

    //the card that we will be changing the value of as we build newmCards
    Card nextCard;
    //now loop through the old mCards, making the newmCards identical
    for(int i = 0; i<mSize-1; i++){
        nextCard.color = mCards[i].color; 
        nextCard.value = mCards[i].value;
        newmCards[i] = nextCard;
    }

    //add the new card to the end of the list
    newmCards[mSize-1] = NEW_CARD;

    //now that the old set of cards has been copied and added to, we can get rid of it
    if(mSize != 1) delete[] mCards; //deallocaets the old mCards, but only if it had stuff in it(because otherwise we are deleting nothing)
    mCards = newmCards; //makes mCards point to the newly made list of cards
}

//implimentation of remove card function
void Deck::removeCard(const int POS){
    //we will only be removing a card if the deck has cards in it, so we don't need to check that this works
    mSize--; 

    //make the new array what our array will eventually point to
    Card* newmCards = new Card[mSize];

    //the card that we will be changing the value of as we build newmCards
    Card nextCard;

    for(int i = 0; i<POS; i++){
        nextCard.color = mCards[i].color;
        nextCard.value = mCards[i].value;
        newmCards[i] = nextCard;
    }
    //at this point we've gotten up to the position we want to remove, so lets skip over it to 'remove it'
    for(int i = POS; i<mSize; i++){
        nextCard.color = mCards[i+1].color;
        nextCard.value = mCards[i+1].value;
        newmCards[i] = nextCard;
    }
    delete[] mCards; //we have copied what we need from it, so now we will deallocate it before making it point to something new
    mCards = newmCards;
    return;
}

void Deck::printDeck(){
    for(int i = 0; i<mSize; i++){
        cout<<"    "<<i+1<<": ";
        mCards[i].printCard();
    }
}
