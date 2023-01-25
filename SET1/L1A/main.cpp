/* CSCI 200: Lab 1A (MATH EQUATION SOLVER):  (Program and use equations using C)
 *
 * Author: Walter Behaylo
 * Resources used:
 None
 * More complete description here...
 coded OHM's law and NEWTON's law for universal gravitation so that the user can implement independent variables and get the solved dependent variables
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath> // for math functions, specifically the square root in Newton's
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/
  // first we will set up the variables for OHM's law
  double current;
  double resistance;
  double voltage;

  // now we will set up the variables for Newton's law of universal gravitation
  const double G = 6.67 * pow(10,-11); // initialize the gravitational constant
  double force; //our output
  double M1; // the two masses of the objects between which force is measured
  double M2;
  double radius; // the distance between the two objects between which force is measued

  // now we're gonna start setting up our program, since we've declared our variables
  int equation_choice;
  cout << endl << "Hello, welcome to Walter's Equation solver." << endl<< endl; // begin the program
  cout << "You can either use OHM's law for circuits, or Newton's law of Universal Gravitational Pull." <<endl<< endl; //give the user options for equations, and get their decision
  cout << "Which one would you like to use? (enter 1 for Ohm's, or 2 for Newton's" << endl<< endl;
  cin >> equation_choice;
  cout << endl;

  if (equation_choice == 1) {
    char ohm_version;
    cout << "Ohm's law, good choice" << endl << endl <<"Do you want to solve for current, voltage, or resistance? (Enter I, V, R)" << endl; //take in what part of OHM's law they want to solve for
    cin >> ohm_version;
    cout << endl;
    if (ohm_version == 'V') {
        cout << "Solving for voltage I see, please enter the current and resistance, respectively."<< endl;
        cout << "I = "; // get the inputs for the two known variables, and then compute for the unknown
        cin >> current;
        cout << "R = ";
        cin >> resistance;
        voltage = current * resistance;
        cout << "The voltage of this circuit is "<< voltage << endl;
    }
    else if (ohm_version == 'I'){
        cout << "Solving for current this time are we? Please enter the voltage and resistance, respectively."<< endl;
        cout << "V = "; // get the inputs for the two known variables, and then compute for the unknown
        cin >> voltage;
        cout << "R = ";
        cin >> resistance;
        current = voltage / resistance;
        cout << "The current of this circuit is "<< current << endl;
    }
    else if (ohm_version == 'R'){
        cout << "OK, resistance it is. Please enter the voltage and current, respectively."<< endl;
        cout << "V = "; // get the inputs for the two known variables, and then compute for the unknown
        cin >> voltage; 
        cout << "I = ";
        cin >> current;
        resistance = voltage / current;
        cout << "The resistance of this circuit is "<< resistance << endl;
    }
  }
  else if (equation_choice == 2){
    cout << "Big gravity guy are we? OK, I'm going to prompt you to enter a bunch of variables now."<< endl;
    cout << "M1 = ";
    cin >> M1;
    cout << "M2 = ";
    cin >> M2;
    cout << "r = ";
    cin >> radius;
    force = (G * M1 * M2)/(radius * radius);
    cout << "The gravitational force is: "<< force << endl;

  }
  cout << endl;
  return 0; // signals the operating system that our program ended OK.
}
  /******** INSERT YOUR CODE ABOVE HERE ********/

  
