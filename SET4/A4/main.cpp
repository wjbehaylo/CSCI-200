/* CSCI 200: Assessment 4: A4 Wild Left Center Right Simulation
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // went to office hours once to get help with functions between different players
 * use object oriented programming to simulate the game left-center-right
 */

 #include "Player.h"
 #include "Game.h"
 #include <cmath>
 #include <iostream>
 #include <time.h>
 #include <vector>
 using namespace std;


int roll(){
    int value = rand()%8 +1;
    return value;
}

int main(){
    srand(time(0)); //quickly seed the rand function we will be using
    int number_simulations;
    cout<< "How many times would you like to simulate a game? ";
    cin>>number_simulations;
    
    vector<int> all_turns;
    
    Game LRC; //makes LRC our Game.
    int turns; //the number of turns that have happened
    int num_rolls; // the number of rolls each player has on their turn
    int skip_counter; // a counter for how many players are skipped after the current player
    cout<< "How many players are playing: "; 
    cin>> LRC.num_players; //because we are simulating results for the same number of players, it is easier to set up the simulator this way
    
    for (int simulation = 1; simulation <= number_simulations; simulation ++){
    turns = 0; //the turns for this iteration are 0 currently
    

    LRC.current_player = LRC.MakeList(LRC.num_players); //make a list of players, and make current_player the first one
    LRC.players_with_chips = LRC.num_players; //initially everyone has chips
    
    

    while (LRC.players_with_chips >= 2){
        while(LRC.current_player->get_chips() == 0){ //while the current player has no chips, skip them and move to the next player. Goes until there is a player with chips
            if(LRC.direction == true){ //if we are moving to the left
                LRC.current_player = LRC.current_player->get_pLeft(); //the turn shifts to the left player
            }
            else if (LRC.direction == false){ //otherwise if we are moving to the right
                LRC.current_player = LRC.current_player->get_pRight(); //the turn shifts to the left player
            }
        }
        // if the player has at least 3 chips, they roll 3 die. Otherwise, they roll 
        if (LRC.current_player->get_chips() >= 3) num_rolls = 3;
        else num_rolls = LRC.current_player->get_chips();



        cout<< "Player #"<< LRC.current_player->get_player_num() << " has " << LRC.current_player->get_chips() <<" chips left"<<endl;
        cout<< "        Rolling "<< num_rolls <<" dice"<<endl;
        for(int i = 0; i<num_rolls; i++){
            switch (roll()){

                case 1: cout<<"        Rolled a 1 - KEEP!"<<endl;
                        break;
                case 2: cout<<"        Rolled a 2 - KEEP!"<<endl;
                        break;
                case 3: cout<<"        Rolled a 3 - KEEP!"<<endl;
                        break;
                case 4: LRC.current_player->give_player_chip('L'); 
                        if (LRC.current_player->get_pLeft()->get_chips() == 1) LRC.players_with_chips ++;
                        cout<<"        Rolled a 4 - GIVE LEFT! - Player #"<<LRC.current_player->get_player_num()<<" has "<<LRC.current_player->get_chips()<<" chips - Player #"<<LRC.current_player->get_pLeft()->get_player_num()<< " has "<<LRC.current_player->get_pLeft()->get_chips()<<" chips"<<endl;
                        break; // case 3 give a chip to the player to the left, if that is their only chip add one to the number of players with chips
                case 5: LRC.current_player->give_player_chip('R'); 
                        if (LRC.current_player->get_pRight()->get_chips() == 1) LRC.players_with_chips ++;
                        cout<<"        Rolled a 5 - GIVE RIGHT! - Player #"<<LRC.current_player->get_player_num()<<" has "<<LRC.current_player->get_chips()<<" chips - Player #"<<LRC.current_player->get_pRight()->get_player_num()<<" has "<<LRC.current_player->get_pRight()->get_chips()<<" chips"<<endl;
                        break; // case 4 give a chip to the player to the right. If that is their only chip add one to the number of players with chips
                case 6: LRC.current_player->give_center_chip(); LRC.center_chips ++; //removes a chip from current player, adds a chip to the center
                        cout<<"        Rolled a 6 - GIVE CENTER! - Player #"<<LRC.current_player->get_player_num()<<" has "<<LRC.current_player->get_chips()<<" chips - Center has "<<LRC.center_chips<<" chips"<<endl;
                        break;
                case 7: LRC.direction = !LRC.direction; //this way if we are going cw, we switch to ccw, and ccw switches to cw
                        cout<<"        Rolled a 7 - REVERSE!"<<endl;
                        break;
                case 8: skip_counter ++; //adds one to the skip counter
                        cout<<"        Rolled a 8 - skipping "<<skip_counter<<" Player(s)"<<endl;
                        break;

            }
        }
        if(LRC.current_player->get_chips() == 0){ //if after their turn a player has 0 chips, 
            LRC.players_with_chips --; //subtract the number of players with chips by 1
        }
        if(LRC.direction){//if play is clockwise (going to the left)
            for(int i = 0; i<skip_counter;i++){//for each skip we move one to the left
                LRC.current_player = LRC.current_player->get_pLeft(); //this changes the current player to be the player to the left of the current player
            }
            LRC.current_player = LRC.current_player->get_pLeft();
        }
        if(!LRC.direction){ //if play is ccw (going to the right)
            for(int i = 0; i<skip_counter; i++) LRC.current_player = LRC.current_player->get_pRight(); //for each skip we move one to the right
            LRC.current_player = LRC.current_player->get_pRight(); // changes current player to be the player to the right of the current player
        }
        turns ++;
        skip_counter = 0;
    }
// now that only one person still has chips, we have to find out who it is
    for (int i = 0; i<LRC.num_players;i++){ //
        if(LRC.current_player->get_chips() != 0){
            cout<<"Player #"<<LRC.current_player->get_player_num()<<" Wins!"<<endl;
            cout<<"They have "<<LRC.current_player->get_chips()<<" chips left after "<< turns<<" turns."<<endl<<endl;
            break;
        }
        LRC.current_player = LRC.current_player->get_pRight();
    }
    all_turns.push_back(turns);
    }
    //now that all the simulations have run, we can compute the average:
    int average = 0;
    for (int i = 0; i<all_turns.size();i++){
        average +=all_turns[i];
    }
    average = average/(all_turns.size() *1.0);
    cout<< "The average was: " <<average<< " turns per game";
    return 0;
}