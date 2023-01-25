/* CSCI 200: Lab 1 B - Random number classification
 *
 * Author: Walter Behaylo
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     None
 *
 * Generate a random float between two user entered numbers and classify it to be within a certain quartile between those two numbers
 */


#include <iostream> // for input and output
#include <stdlib.h> // for the rand() function
#include <time.h> // to randomly seed our rand() function
#include <iomanip> // to format the random value
using namespace std;

//Author Walter Behaylo

int main() {
    double min; // declare the min and max variables
    double max;
    double random; // set up the random number that will be generated
    string quartile;// initialize the quartile, and the diff we will use to calculate them
    double diff;
    rand(); // first call to throw away
    srand(time(0)); //seeds rand with a time

    char choice = 'Y';
    
    cout << "Enter the minimum value: ";
    cin >> min;
    cout << "Enter the maximum value: ";
    cin >> max;
    // now based on those values, we will determine the quartiles
    diff = max - min;

    while (choice == 'Y'){
        random = rand()/(double)RAND_MAX * (max-min)+min; // this ensures that our random will be a float, since we divide it by the random max it will be between 0 and 1, which when multiplied by max-min is below max
        /* goes through the quartile values to determine where our random fits*/
        if ((random >= min) && (random< min + diff / 4)){
            quartile = "first";
        }
        else if ((random >= min + diff / 4) && (random < min + diff/2)){
            quartile = "second";
        }
        else if ((random >= min + diff / 2) && (random < min + 3* (diff/4))){
            quartile = "third";
        }
        else {
            quartile = "fourth";
        }
        
        cout << "A random value is: "<< setprecision(3)<<random<< endl;
        cout << "This is in the "<< quartile << " quartile"<< endl;
        cout << "Do you want another random value? (Y/N) ";
        cin >> choice;

    }
    cout << "Have a nice day!"<< endl;
    return (0);
}