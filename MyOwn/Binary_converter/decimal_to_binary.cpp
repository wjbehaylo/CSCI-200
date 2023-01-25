// this one is just the decimal to binary

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int decimal_to_binary(){
    int decimal, binary = 0, remainder = 5, place = 1;
    cout<< "Enter the decimal here: ";
    cin>> decimal;
    while (decimal != 0){
        remainder = decimal %2;
        binary = binary + (remainder *  place);
        decimal = decimal /2; 
        place *= 10;
        
    }
cout << "The number in binary form is: "<< binary;
return binary;
    }
