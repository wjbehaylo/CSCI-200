// This is gonna have a function that goes from binary to decimal in it, and thats it

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int binary_to_decimal(){
    int decimal = 0;
    string binary;
    cout<< "Ok we goint binary to decimal. Enter that binary then."<<endl<<"Binary: ";
    
    
    cin>> binary;

    for (int i =0;i < binary.length(); i++){
        int digit = binary.substr(i,1);
        int value = pwr(2,binary.length()-1);
        decimal += digit * value;
    }
    cout << "That shit is "<< binary;
    return decimal;
}