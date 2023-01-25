//This is the actual file in which the game will run through all of its classes

#include "game.h"
#include "player.h"
#include "deck.h"
#include "card.h"
#include <fstream>
#include <iostream>
#include <time.h>

#include <cstdlib> //for srand
using namespace std;


int main(){
    

    //first we will write the file containing all of the cards. The cards will be of the form color value
    ofstream FileOut;
    FileOut.open("UNO_DECK.txt");

    if(!FileOut.is_open()){ //if the file didn't open
        cout<<"Error, writing file did not open";
        return -1;
    }

    //we will be writing two of each card for each color, and 4 of each of the wildcards
    char values[] = {'1','2','3','4','5','6','7','8','9','d','s','r', 'D','C'};
    char colors[] = {'R','G','B','Y','W'};
    
    for(int i = 0; i<4; i++){ //for each color
        for(int j = 0; j<12; j++){ //and each card type
            //we will write each of the cards to the file, with 
            FileOut<<colors[i]<<" "<<values[j]<<"\n"; //between color and value put a space, and then between cards put a newline
            FileOut<<colors[i]<<" "<<values[j]<<"\n";
        }
    }
    //now we write in the special cards
    for(int i = 12; i<14; i++){
        for(int j = 0; j<4; j++){
        FileOut<<colors[4]<<" "<<values[i]<<"\n";
    }
    }
    FileOut.close();

    //now we will read in those values and create a deck of cards with those values
    ifstream FileIn;
    FileIn.open("UNO_DECK.txt");
    if (!FileIn.is_open()){
        cout<<"input file error, quitting program";
        return -1;
    }
    Deck full_deck;
    string color, value;
    Card next_card;
    while(!FileIn.eof()){//while we're not at the end of the file
        FileIn>>color>>value;
        if(!FileIn) break; //if we read in a value that wasn't there, the loop ends
        next_card.color = color[0];
        next_card.value = value[0];
        full_deck.addCard(next_card);
    }
    FileIn.close();


    int num_users = 0;
    cout<<"Welcome to UNO!"<<endl;
    
    
    cout<<"The rules of UNO are quite simple. You are always able to play a card if it is a wild card,"<<endl;
    cout<<"otherwise it must match the color or symbol of the top card."<<endl;
    cout<<"If you can't play a card, you can choose to draw one instead."<<endl<<"The goal of the game is to be the first person to play all of your cards!"<<endl<<endl;
    
    int seed;
    int seed_value = 0;
    while (true){
    cout<<"Would you like to seed this program? Enter 1 for yes, 2 for no: ";
    cin>>seed;
    if(!cin.fail() && (seed == 1 || seed == 2)){break;}
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<endl<<"Enter either 1 or 2"<<endl;
    }

    if(seed == 1){
        while (true){
            cout<<"Enter the seed value now: ";
            cin>>seed_value;
            if(!cin.fail() && seed_value>0) break;
            cin.clear();
            cin.ignore(10000,'\n');
            }
    srand(seed_value);}
    else srand(time(0)); 
    
    
    
while (true){
    cout<<endl<<"Enter how many people will be playing UNO today: ";
    cin>>num_users;
    //can't play uno with less than one person...
    if(!cin.fail() && num_users>1){break;}
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<"You're gonna need more people than that unfortunately, go get some friends to play!"<<endl<<endl;
    }
    

    Game UNO(num_users, full_deck);
    while (UNO.getTopCard().color == 'W'){
        UNO.getDiscard()->addCard(UNO.getTopCard()); //adds the top card to discard, now we just need to set a new top card
        UNO.setTopCard(UNO.getDeck()->draw()); //this draws a card from the Deck and makes it the new top card
    }
    cout<<endl<<endl; // formatting

    Card played_card; //this card represented the card that the player chooses to play 
    Card drawn_card; //the card that the player draws
    int cards_to_draw;
    bool skip;
    bool reverse;
        while(true){
            cards_to_draw = 0; //changes depending on the card that the player plays
            skip = false; //becomes true if the player plays a card that would skip a player
            reverse = false; //becomes true if the player plays a card that would reverse the direction
    
            cout<<endl<<endl<<UNO.getCurrentPlayer()->getName()<<", it's your turn."<<endl;
            UNO.unoAlert(); //alerts the current player which other players have UNO
            played_card = UNO.getCurrentPlayer()->playCard(UNO.getTopCard());

            if(played_card.color == '1'){ //if the player chose to draw a card
                

                drawn_card = UNO.getDeck()->draw();
                cout<<"You drew a "; drawn_card.printCard();
                cout<<endl<<endl;
                UNO.getCurrentPlayer()->getHand()->addCard(drawn_card);
                UNO.unoUpdate(); //checks if the player had UNO, in which case they no longer do
                UNO.switchCurrentPlayer();
                continue;
            }
            else{ //if the player chose to play a card
                if (UNO.gameOver()) break; //if it was the last card
                UNO.unoUpdate();
                UNO.Discard(UNO.getTopCard()); //discards the old top card
                UNO.setTopCard(played_card); //makes the top card the card the user played

                if (played_card.color == 'W'){//if it is a wild card, the player chooses the new color
                    UNO.chooseColor(); //lets the user choose the color, makes that the new color of the top card
                }
                if (played_card.value =='d') { //if the user played a draw 2
                    cards_to_draw += 2;
                    skip = true;
                }
                else if(played_card.value =='D'){ //if the user played a draw 4
                    skip = true;
                    cards_to_draw += 4;
                }
                else if(played_card.value == 's') skip = true; //if the user played a skip
                else if(played_card.value == 'r') {
                    if( UNO.getNumPlayers() ==2){ skip = true;}
                    else reverse = true; //if the user played a reverse
                }
            
            //at this point the user has played their card and the game has calculated what that's gonna do, so lets do it
                if (reverse == true){
                
                    UNO.switchRotation();
                    UNO.switchCurrentPlayer();
                    continue;
                }
                else if(skip ==true){
                    UNO.switchCurrentPlayer(); //moves to the person being skipped
                    UNO.Draw(cards_to_draw); //if they need to draw cards, make them draw cards
                    UNO.unoUpdate(); //update, since player drew cards
                    UNO.switchCurrentPlayer(); //switch to the person after them (because they got skipped)
                    continue;
                    }
                else{ 
                    UNO.switchCurrentPlayer();
                    continue;
                }
            }
        


            
                
        }
         //this is the end of the loop for the end of the game
        cout<<UNO.getCurrentPlayer()->getName() <<" WON!";
        

    return 0;

}



//need to add in a check to see what players have uno, and let other players know what who it is. 