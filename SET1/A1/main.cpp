/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     None
 *
 * Use the rand() function to make a single player rock paper scissors game where the player goes against the computer
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <stdlib.h> // for rand()
#include <time.h> // to seed rand()
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.
char player_choice; //to store the player's choice
int computer_choice1;//to store the random number generated for computer choice
char computer_choice2;//to store the actual rock paper or scissors
int win = 0; //to store player wins
int loss = 0; //to store player losses
int tie = 0; //to store player ties
char cont = 'Y'; //decides if the while loop will execute, used cont instead of continue because continue is forbidden

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
rand(); // first call to throw away
srand(time(0)); //randomly initialize the random function
  /******** INSERT YOUR CODE BELOW HERE ********/
while (cont == 'Y'){
cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter R, P, or S)"<<endl<<"Player one: ";
cin >> player_choice;
cout<< endl;
/* I decided to go through each player choice, then each AI choice, and base each game off of a stream of while and if statements*/

if (player_choice == 'R'){
    cout<< "Player choose Rock"<<endl;
    computer_choice1 = (rand()%3) +1;
    

switch (computer_choice1){ //random generator to get the computer's input
    case 1: computer_choice2 = 'P';
    break;
    case 2: computer_choice2 = 'S';
    break;
    case 3: computer_choice2 = 'R';
    break;
    }

    if (computer_choice2 == 'P'){ // an if branch for each possible combination of player and computer inputs
    cout<< "Computer choose Paper"<< endl<<endl;
    cout<< "Paper beats rock."<<endl;
    cout<< "Computer wins!"<<endl;
    loss++; //using the ++ shortcut to add to the game's statistics of games won, lossed, and tied
}
else if (computer_choice2 == 'S'){
    cout<< "Computer choose Scissors"<<endl<<endl;
    cout<< "Rock beats scissors."<< endl;
    cout<< "Player wins!"<< endl;
    win++;
}
else if (computer_choice2 == 'R'){
    cout<< "Computer choose Rock"<< endl<<endl;
    cout<< "No one wins."<<endl;
    cout<< "It's a tie!"<< endl;
    tie++;
}
cout<< endl;
}


else if (player_choice == 'P'){
    cout<< "Player choose Paper"<<endl;
    computer_choice1 = (rand()%3) +1;
switch (computer_choice1){ //random generator to get the computer's input
    case 1: computer_choice2 = 'R';
    break;
    case 2: computer_choice2 = 'S';
    break;
    case 3: computer_choice2 = 'P';
    break;
}
    if (computer_choice2 == 'R'){ // an if branch for each possible combination of player and computer inputs
    cout<< "Computer choose Rock"<<endl<<endl;
    cout<< "Paper beats rock."<< endl;
    cout<< "Player wins!"<< endl;
    win++;
    } 
    else if (computer_choice2 == 'S'){
    cout<< "Computer choose Scissors"<<endl<<endl;
    cout<< "Scissors beats paper."<<endl;
    cout<< "Computer wins!"<< endl;
    loss++;
}
    else if (computer_choice2 == 'P'){
    cout<< "Computer choose Paper"<< endl<<endl;
    cout<< "No one wins."<< endl;
    cout<< "It's a tie!"<< endl;
    tie++;
    }
cout<< endl;
}


else if (player_choice == 'S'){
    cout<< "Player choose Scissors"<<endl;
    computer_choice1 = (rand()%3) +1;
switch (computer_choice1){ //random generator to get the computer's input
    case 1: computer_choice2 = 'R';
    break;
    case 2: computer_choice2 = 'P';
    break;
    case 3: computer_choice2 = 'S';
    break;
}
    if (computer_choice2 == 'R'){ // an if branch for each possible combination of player and computer inputs
    cout<< "Computer choose Rock"<<endl<<endl;
    cout<< "Rock beats scissors."<<endl;
    cout<< "Computer wins!"<< endl;
    loss++;
    }
    else if (computer_choice2 == 'P'){
    cout<< "Computer choose Paper"<< endl<<endl;
    cout<< "Scissors beats paper." <<endl;
    cout<< "Player wins!"<< endl;
    win++;
}
    else if (computer_choice2 == 'S'){
    cout<< "Computer choose Scissors"<<endl<<endl;
    cout<< "No one wins."<<endl;
    cout<< "It's a tie!"<<endl;
    tie++;
    }
cout<<endl;

}
cout<< "Do you want to play again? (Y/N) "; //here we set up the ask to see if the player would like to play again, and update the while loop's conditional variable accordingly
cin>> cont;
cout<< endl; 
  /******** INSERT YOUR CODE ABOVE HERE ********/

  
}
cout<< "Thanks for playing!"<<endl;
cout<< "You won "<<win<< " game(s), lost "<< loss<< " game(s), and tied "<<tie<<" game(s)."<<endl;
//in retrospect, if I had known how I would've/should've just written stuff into a dictionary for player and computer
return 0;// signals the operating system that our program ended OK.
}