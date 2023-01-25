// This is a little binary converter project I made for fun to practice for my
// IO Stream and Procedural programming quiz tomorrow

#include <iostream>
#include <cstring>
#include <cmath>
#include "binary_to_decimal.h"
#include "decimal_to_binary.h"
#include "C:\Users\Walter's Computer\School\C\CSCI 200\SET2\L2B\coordinate_conversion.h"
#include "C:\Users\Walter's Computer\School\C\CSCI 200\SET2\A2\ppm_functions.h"

using namespace std;

int main(){
    int choice;
    cout<< "Welcome to the number station1" << endl << " What are you converting?"<< endl<<  "(1) Binary to Decimal"<<endl;
    cout<< "(2) Decimal to Binary"<<endl;
    choice = get_user_input(2);
    if (choice == 1){
        binary_to_decimal();
        return 0;
    }

    else if (choice == 2){
        decimal_to_binary();
        return 0;
    }
}